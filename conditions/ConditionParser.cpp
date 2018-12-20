//
// Created by cs on 12/18/18.
//

#include "ConditionParser.h"


ConditionParser::ConditionParser(vector<Expression *> &vecOfExp, string &con, SymbolTable *&symbolTable) {
    this->symTbl=symbolTable;
    this->vecOfExpCommands = vecOfExp;
    this->condition = con;
}
vector<Expression*>& ConditionParser::getVecOfExpCommands() {
    return this->vecOfExpCommands;
}
bool ConditionParser::checkCondition() {

}