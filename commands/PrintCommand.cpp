#include "PrintCommand.h"
PrintCommand::PrintCommand(ExpressionFactory* expFac, string &str) {
    this->expFactory = expFac;
    this->strToPrint = str;
}
/**
 * check if print string or var value
 * @return true or false
 */
bool PrintCommand::isInQoutes() {
    // string case
    if ((strToPrint[0] == '\"') && (strToPrint[strToPrint.size()-1] == '\"')) {
        return true;
    }
    // var case
    return false;
}

/**
 * print
 */
void PrintCommand::execute() {
    // string case
    if (isInQoutes()) {
        string toPrint = strToPrint.substr(FIRST,strToPrint.size()-2);
        cout<< toPrint << endl;
        // var value case
    } else {
        Expression* tempPrint = (expFactory->createExpression(strToPrint));
        double toPrint = tempPrint->calculate();
        cout << toPrint << endl;
        delete(tempPrint);
    }
}