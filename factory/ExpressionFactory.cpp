//
// Created by tamir on 18/12/18.
//

#include "ExpressionFactory.h"


ExpressionFactory::ExpressionFactory(SymbolTable *&symTbl) {
    this->symbolTable = symTbl;
    this->numBeforeMe = false;
}


const string& ExpressionFactory::getStrOfExpression() const {
    return this->expressionStr;
}

stack<char>& ExpressionFactory::getOperationsStack() {
    return this->operationsStack;
}

stack<ShuntingYardExpression*>& ExpressionFactory::getMainStack() {
    return this->mainStack;
}

bool ExpressionFactory::operationsPrecedence(const char c) {
    if ((getOperationsStack().top() == MINUS_CHAR) && (c==PLUS_CHAR)) {
        return true;
    }
    else if ((getOperationsStack().top() == DIV_CHAR) || (getOperationsStack().top() == MULT_CHAR)){
        return ((c==MINUS_CHAR)||(c==PLUS_CHAR));
    }
    return false;
}
void ExpressionFactory::popOperatorFromStackToMainStack() {
    //
    while ((!getOperationsStack().empty()) && (getOperationsStack().top() != PARENTHESES_OPEN_CHAR)) {
        (getMainStack()).push(new Operators(getOperationsStack().top()));
        //pop the top of the stack
        getOperationsStack().pop();
    }
}

void ExpressionFactory::popOperatorsInParenthesesToMainStack() {
    getMainStack().push(new Operators(getOperationsStack().top()));
    getOperationsStack().pop();
}

void ExpressionFactory::addRestOfOperatorsToDigitsStack() {
    while (!getOperationsStack().empty()) {
        popOperatorFromStackToMainStack();
    }
}

void ExpressionFactory::insertByOrderToStack() {
    string str = getStrOfExpression();
    string tempVar;
    bool varAdded = false;
    for(const auto* it = str.c_str(); *it; ++it) {
        //white spaces are not necessary
        if ((*it) == SPACE_CHAR){
            continue;
        }
        //token as a number
        if( utils.isDigit(*it) ) {
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
                if (valOfVar < 0) {
                    valOfVar = -1 * valOfVar;
                    getMainStack().push(new Num(0));
                    getMainStack().push(new Num(valOfVar));
                    getOperationsStack().push(MINUS_CHAR);
                } else {
                    getMainStack().push(new Num(valOfVar));
                }
                //double valOfVar = symbolTable->getValueOfVar(tempVar);
                //getMainStack().push(new Num(valOfVar));
                tempVar="";
            } //check if tempVar is in the symbol table
            switch (*it) {
                case MINUS_CHAR:
                    if (!this->numBeforeMe) {
                        getMainStack().push(new Num(0));
                        getOperationsStack().push(*it);
                        break;
                    }
                    //
                case PLUS_CHAR:
                    //
                    if ((!getOperationsStack().empty()) && (operationsPrecedence(*it))) {
                        popOperatorFromStackToMainStack();
                    }

                case PARENTHESES_OPEN_CHAR:
                case MULT_CHAR:
                case DIV_CHAR:
                    getOperationsStack().push(*it);
                    break;
                case PARENTHESES_CLOSE_CHAR:
                    //pops all the operation inside the parentheses
                    popOperatorsInParenthesesToMainStack();
                    //pops the '(' left in operation stack
                    getOperationsStack().pop();
                    break;

                default:
                    break;
            }
            this->numBeforeMe=false;
            if (*it == PARENTHESES_CLOSE_CHAR) {
                this->numBeforeMe=true;
            }

        } else if (utils.isValidVarChar(*it)) {
            tempVar+=(*it);
        } else {
            throw INVALID_EXPRESSION_STRING;
        }
    }
    if (symbolTable->isVarInValueMap(tempVar)) {
        double valOfVar = symbolTable->getValueOfVar(tempVar);
        if (valOfVar < 0) {
            valOfVar = -1 * valOfVar;
            getMainStack().push(new Num(0));
            getMainStack().push(new Num(valOfVar));
            getOperationsStack().push(MINUS_CHAR);
        } else {
            getMainStack().push(new Num(valOfVar));
        }
    }
    this->numBeforeMe = false;
    addRestOfOperatorsToDigitsStack();
}
Expression* ExpressionFactory::generateExpressionOfStack() {
    while (!(getMainStack()).empty()) {
        ShuntingYardExpression* shuntingYardExpression = getMainStack().top();
        getMainStack().pop();
        //if expression is operator
        string tempStr = shuntingYardExpression->getNumOrOperationExp();
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
    //return new Num(0);
}

Expression* ExpressionFactory::createExpression(vector<string>::iterator &it) {
    this->expressionStr = (*it);
    insertByOrderToStack();
    return generateExpressionOfStack();
}

Expression* ExpressionFactory::createExpression(const string &strToExp) {
    this->expressionStr = strToExp;
    insertByOrderToStack();
    return generateExpressionOfStack();
}

