
#include "StrToDoubleClass.h"
#include "../expression/Neg.h"
#include "Operators.h"

/**
 * Ctor, init queue and stack to null as default
 * @param strOfExp the string of the expression.
 */
StrToDoubleClass::StrToDoubleClass(const string &strOfExp) {
    this->strOfExpression = strOfExp;
    this->numBeforeMe = false;
    //this->negative = false;
}

const string &StrToDoubleClass::getStrOfExpression() const {
    return strOfExpression;
}

stack<ShuntingYardExpression*>& StrToDoubleClass::getMainStack() {
    return this->mainStack;
}



stack<char> &StrToDoubleClass::getOperationsStack() {
    return operationsStack;
}

bool StrToDoubleClass::operationsPrecedence(const char c) {
    if ((getOperationsStack().top() == MINUS_CHAR) && (c==PLUS_CHAR)) {
        return true;
    }
    else if ((getOperationsStack().top() == DIV_CHAR) || (getOperationsStack().top() == MULT_CHAR)){
        return ((c==MINUS_CHAR)||(c==PLUS_CHAR));
    }
    return false;
    /*
    else if ((c==MINUS_CHAR)||(c==PLUS_CHAR)) {
        return  ((getOperationsStack().top() == DIV_CHAR) || (getOperationsStack().top() == MULT_CHAR));
    }
    return false;
    */
}

void StrToDoubleClass::popOperatorsInParenthesesToMainStack() {
    while (getOperationsStack().top() != PARENTHESES_OPEN_CHAR) {
        (getMainStack()).push(new Operators(getOperationsStack().top()));
        //pop the top of the stack
        getOperationsStack().pop();
    }
}

void StrToDoubleClass::popOperatorFromStackToMainStack() {
    getMainStack().push(new Operators(getOperationsStack().top()));
    getOperationsStack().pop();
}

void StrToDoubleClass::addRestOfOperatorsToDigitsStack() {
    while (!getOperationsStack().empty()) {
        popOperatorFromStackToMainStack();
    }
}

void StrToDoubleClass::insertByOrderToStack() {
    string str = getStrOfExpression();
    for(const auto* it = str.c_str(); *it; ++it) {
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
    //for (char& c : str) {

        //char* ch = &c;
        //char* ch = extractCharStarFromString(c);
        //skips on spaces
        /*
        if (utils.isDigit(c)) {

            if (this->numBeforeMe) {
//                ch += &c;
                //need to update the DOUBLE was inside*10 + double(digit)
            }
            getMainStack().push(&c);
            this->numBeforeMe = true;
        */
        } else if (utils.isOperation(*it)) {
            switch (*it) {

                case MINUS_CHAR:
                    if (!this->numBeforeMe) {
                        getMainStack().push(new Num(0));
                        getOperationsStack().push(*it);
                        break;
                    }
                    //

                case PLUS_CHAR:
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

        } else {
            throw INVALID_EXPRESSION_STRING;
        }

    }
    addRestOfOperatorsToDigitsStack();
}

Expression* StrToDoubleClass::stackToExpression() {
    while (!(getMainStack()).empty()) {
        ShuntingYardExpression* shuntingYardExpression = getMainStack().top();
        getMainStack().pop();
        //if expression is operator
        string tempStr = shuntingYardExpression->getNumOrOperationExp();
        const auto it = tempStr.c_str();
        if (utils.isOperation(*it)) {
            Expression* rightExpression = stackToExpression();
            Expression* leftExpression = stackToExpression();
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
            throw "Error occurd";
        }
        /*
        //stop condition
        if (utils.isDigit(c)) {
            return new Num (utils.charToInt(c));

        } else if (utils.isOperation(c)) {
            Expression* rightExpression = stackToExpression();
            Expression* leftExpression = stackToExpression();
            switch (c) {

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
        }*/
    }
}

double StrToDoubleClass::calculate() {
    insertByOrderToStack();
    Expression* ex = stackToExpression();
    return ex->calculate();
    return 0;
}


//#include "StrToDoubleClass.h"
//#include "Neg.h"

/**
 * Ctor, init queue and stack to null as default
 * @param strOfExp the string of the expression.
 */
/*
StrToDoubleClass::StrToDoubleClass(string &strOfExp) {
   this->strOfExpression = strOfExp;
   this->numBeforeMe = false;
   //this->negative = false;

}

const string &StrToDoubleClass::getStrOfExpression() const {
   return strOfExpression;
}
stack<char> &StrToDoubleClass::getDigitsStack() {
   return mainStack;
}
stack<char> &StrToDoubleClass::getOperationsStack() {
   return operationsStack;
}

bool StrToDoubleClass::operationsPrecedence(const char c) {
   if ((c==MINUS_CHAR)||(c==PLUS_CHAR)) {
       return  ((getOperationsStack().top() == DIV_CHAR) || (getOperationsStack().top() == MULT_CHAR));
   }
   return false;
}

void StrToDoubleClass::popOperatorsInParentheses() {
   while (getOperationsStack().top() != PARENTHESES_OPEN_CHAR) {
       getDigitsStack().push(getOperationsStack().top());
       //pop the top of the stack
       getOperationsStack().pop();
   }
}

void StrToDoubleClass::popOperatorFromStackToDigitsStack() {
   getDigitsStack().push(getOperationsStack().top());
   getOperationsStack().pop();
}

void StrToDoubleClass::addRestOfOperatorsToDigitsStack() {
   while (!getOperationsStack().empty()) {
       popOperatorFromStackToDigitsStack();
   }
}

void StrToDoubleClass::insertByOrderToStack() {
   string str = getStrOfExpression();
   for (char& c : str) {
       //skips on spaces
       if (c == SPACE_CHAR){
           continue;
       }
       if (utils.isDigit(c)) {
           if (this->numBeforeMe) {
               //need to update the DOUBLE was inside*10 + double(digit)
           }
           getDigitsStack().push(c);
           this->numBeforeMe = true;

       } else if (utils.isOperation(c)) {
           switch (c) {

               case PARENTHESES_CLOSE_CHAR:
                   //pops all the operation inside the parentheses
                   popOperatorsInParenthesesToMainStack();
                   //pops the '(' left in operation stack
                   getOperationsStack().pop();
                   break;

               case MINUS_CHAR:
                   if (!this->numBeforeMe) {
                       getDigitsStack().push(ZERO_CHAR);
                       getOperationsStack().push(c);
                       break;
                   }

               case PLUS_CHAR:
                   if ((!getOperationsStack().empty()) && (operationsPrecedence(c))) {
                       popOperatorFromStackToMainStack();
                   }

               case PARENTHESES_OPEN_CHAR:
               case MULT_CHAR:
               case DIV_CHAR:
                   getOperationsStack().push(c);
                   break;
               default:
                   break;
           }
           this->numBeforeMe=false;
       } else {
           throw INVALID_EXPRESSION_STRING;
       }

   }
   addRestOfOperatorsToDigitsStack();
}

Expression* StrToDoubleClass::stackToExpression() {
   while (!(getDigitsStack()).empty()) {
       char c = getDigitsStack().top();
       getDigitsStack().pop();
       //stop condition
       if (utils.isDigit(c)) {
           return new Num (utils.charToInt(c));
       } else if (utils.isOperation(c)) {
           Expression* rightExpression = stackToExpression();
           Expression* leftExpression = stackToExpression();
           switch (c) {

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
       }
   }
}

double StrToDoubleClass::calculate() {
   insertByOrderToStack();
   Expression* ex = stackToExpression();
   return ex->calculate();
}
*/
