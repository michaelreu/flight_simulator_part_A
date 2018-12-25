#include "ExpressionFactory.h"

/*
 * Ctor
 */
ExpressionFactory::ExpressionFactory(SymbolTable *&symTbl) {
    this->symbolTable = symTbl;
    this->numBeforeMe = false;
    this->varDigit = false;
}

/*
 * getter
 */
const string& ExpressionFactory::getStrOfExpression() const {
    return this->expressionStr;
}
/*
 * getter
 */
stack<char>& ExpressionFactory::getOperationsStack() {
    return this->operationsStack;
}
/*
 * getter
 */
stack<ShuntingYardExpression*>& ExpressionFactory::getMainStack() {
    return this->mainStack;
}
/*
 * if the operation has precedence it pops all the operation with lower precedence
 */
bool ExpressionFactory::operationsPrecedence(const char c) {
    if ((getOperationsStack().top() == MINUS_CHAR) && (c==PLUS_CHAR)) {
        return true;
    }
    else if ((getOperationsStack().top() == DIV_CHAR) || (getOperationsStack().top() == MULT_CHAR)){
        return ((c==MINUS_CHAR)||(c==PLUS_CHAR));
    }
    return false;
}
/*
 *
 */
void ExpressionFactory::popOperatorFromStackToMainStack() {
    //
    while ((!getOperationsStack().empty()) && (getOperationsStack().top() != PARENTHESES_OPEN_CHAR)) {
        (getMainStack()).push(new Operators(getOperationsStack().top()));
        //pop the top of the stack
        getOperationsStack().pop();
    }
}
/*
 * in parentheses there is a precedence
 */
void ExpressionFactory::popOperatorsInParenthesesToMainStack() {
    getMainStack().push(new Operators(getOperationsStack().top()));
    getOperationsStack().pop();
}
/*
 * all the rest of the operation will be poped to the stack
 */
void ExpressionFactory::addRestOfOperatorsToDigitsStack() {
    while (!getOperationsStack().empty()) {
        popOperatorFromStackToMainStack();
    }
}
/*
 * the negative expression becomes to be minus: adding 0 before
 */
void ExpressionFactory::addMinusExpressionToMainStack(double valOfVar) {
    if (valOfVar < ZERO) {
        valOfVar = -1 * valOfVar;
        getMainStack().push(new Num(ZERO));
        getMainStack().push(new Num(valOfVar));
        getOperationsStack().push(MINUS_CHAR);
    } else {
        getMainStack().push(new Num(valOfVar));
    }
}
/*
 * inserting the numbers to the stack by the order of the expression
 */
void ExpressionFactory::insertByOrderToStack() {
    string str = getStrOfExpression();
    string tempVar="";
    this->varDigit = false;
    for(const auto* it = str.c_str(); *it; ++it) {
        //white spaces are not necessary
        if ((*it) == SPACE_CHAR){
            continue;
        }
        //token as a number
        if((utils.isDigit(*it)) && (!this->varDigit)) {
            const auto* tempExp = it;
            for(; utils.isDigit(*it)||((*it)=='.'); ++it) { ; }
            const auto numStr = string(tempExp, it);
            if (!utils.isStrDouble(numStr)) {
                throw DOUBLE_STRING_ERROR;
            }
            getMainStack().push(new Num(stod (numStr)));
            --it;
            this->numBeforeMe = true;
        } else if (utils.isShunYardOperation(*it)) {
            if (symbolTable->isVarInValueMap(tempVar)) {
                double valOfVar = symbolTable->getValueOfVar(tempVar);
                addMinusExpressionToMainStack(valOfVar);
                this->numBeforeMe = true;
                this->varDigit = false;
                tempVar="";
            } //check if tempVar is in the symbol table
            switch (*it) {
                case MINUS_CHAR:
                    this->varDigit = false;
                    if (!this->numBeforeMe) {
                        getMainStack().push(new Num(0));
                        getOperationsStack().push(*it);
                        break;
                    }
                case PLUS_CHAR:
                    this->varDigit = false;
                    if ((!getOperationsStack().empty()) && (operationsPrecedence(*it))) {
                        popOperatorFromStackToMainStack();
                    }
                case PARENTHESES_OPEN_CHAR:
                case MULT_CHAR:
                case DIV_CHAR:
                    getOperationsStack().push(*it);
                    break;
                case PARENTHESES_CLOSE_CHAR:
                    this->varDigit = false;
                    //pops all the operation inside the parentheses
                    popOperatorsInParenthesesToMainStack();
                    //pops the '(' left in operation stack
                    getOperationsStack().pop();
                    break;
                default:
                    break;
            }
            this->numBeforeMe = false;
            if (*it == PARENTHESES_CLOSE_CHAR) {
                this->numBeforeMe = true;
            }

        } else if (utils.isValidVarChar(*it)) {
            tempVar+=(*it);
            this->varDigit = true;
        } else {
            throw INVALID_EXPRESSION_STRING;
        }
    }
    if (symbolTable->isVarInValueMap(tempVar)) {
        double valOfVar = symbolTable->getValueOfVar(tempVar);
        addMinusExpressionToMainStack(valOfVar);
    }
    this->numBeforeMe = false;
    addRestOfOperatorsToDigitsStack();
}

/*
 * creating an expression with recursion
 */
Expression* ExpressionFactory::generateExpressionOfStack() {
    while (!(getMainStack()).empty()) {
        //each one of the ShuntingYardExpression* goes to the vector, then the vector frees
        ShuntingYardExpression* shuntingYardExpression = getMainStack().top();
        saveToFree.push_back(shuntingYardExpression);
        getMainStack().pop();
        //if expression is operator
        string tempStr = shuntingYardExpression->getNumOrOperationExp();
        //delete(shuntingYardExpression);
        const auto it = tempStr.c_str();
        if (utils.isShunYardOperation(*it)) {
            Expression* rightExpression = generateExpressionOfStack();
            Expression* leftExpression = generateExpressionOfStack();
            switch (tempStr[0]) {
                case PLUS_CHAR:
                    return new Plus (leftExpression,rightExpression);

                case MINUS_CHAR:
                    return new Minus (leftExpression,rightExpression);

                case MULT_CHAR:
                    return new Mult (leftExpression,rightExpression);

                case DIV_CHAR:
                    return new Div (leftExpression,rightExpression);

                default:
                    break;
            }
        } else if (utils.isStrDouble(tempStr)) {
            return new Num(stod(tempStr));
        } else {
            throw ERR_GEN_EXP;
        }
    }
}
/*
 * freeing the allocated memory of the ShuntingYardExpression* objects
 */
void ExpressionFactory::freeVectorOfMainStack() {
    for (ShuntingYardExpression* objToFree : this->saveToFree) {
        delete(objToFree);
    }
    this->saveToFree.clear();
}
/*
 * create the final expression to be return
 */
Expression* ExpressionFactory::finalExpression() {
    insertByOrderToStack();
    Expression* exp = generateExpressionOfStack();
    freeVectorOfMainStack();
    return exp;
}
/*
 * create expression
 */
Expression* ExpressionFactory::createExpression(vector<string>::iterator &it) {
    this->expressionStr = (*it);
    return finalExpression();
}
/*
 * create expression
 */
Expression* ExpressionFactory::createExpression(const string &strToExp) {
    this->expressionStr = strToExp;
    return finalExpression();
}
/*
 * Dtor
 */
ExpressionFactory::~ExpressionFactory() {
    freeVectorOfMainStack();
    delete(this->symbolTable);
}
