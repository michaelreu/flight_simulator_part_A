
#include "ExpressionFactory1.h"
#include "../reader/ExpressionCommand.h"
#include "../reader/OpenServerCommand.h"

Expression* ExpressionFactory1::createExpression(vector<string>::iterator it) {

   if ((*it)=="openServerCommand") {
       // get string from vector
       string stringPort = getNextDoubleInVector(dataVector);
       string stringHertz = getNextDoubleInVector(dataVector);
       // calculate to double
       this->port = (int)extractDoubleFromString(stringPort);
       this->hertz = (int)extractDoubleFromString(stringHertz);
       return new ExpressionCommand(new OpenServerCommand(it));
   }

}