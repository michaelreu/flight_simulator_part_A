
#include "Reader.h"


void Reader::readCommands(){
    string command;
    LexerParser interpeter;
    vector<string> listOfCommand;
    while(true){
        cout << "enter new Command - 0 to exit\n";
        getline(cin, command);
        if (command == "0") {
            break;
        }
        listOfCommand = interpeter.lexer(command);
        if (listOfCommand.empty()){
            break;
        }
        interpeter.parser(listOfCommand);
    }
}





