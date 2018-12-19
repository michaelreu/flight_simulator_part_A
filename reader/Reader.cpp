
#include "Reader.h"


void Reader::readCommands(){
    //SymbolTable SymbolMap;
    string command;
    LexerParser interpreter();
    vector<string> listOfCommand;
    while(true){
        cout << "enter new Command - 0 to exit\n";
        getline(cin, command);
        if (command == "0") {
            break;
        }
        listOfCommand = interpreter.lexer(command);
        if (listOfCommand.empty()){
            break;
        }
        interpreter.parser();
    }
}




