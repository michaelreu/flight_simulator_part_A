

#include "CommandMapClass.h"

const map<string, Expression *> &CommandMapClass::getCommandsMap() const {
    return commandsMap;
}

initCommandMap(){
    getCommandsMap()["OpenServerCommand"] = (new ExpressionCommand(new OpenServerCommand(&dataVector)));

}
