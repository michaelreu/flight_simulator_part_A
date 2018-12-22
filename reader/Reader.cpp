
#include "Reader.h"


void Reader::readCommands(string fileName){
    //SymbolTable SymbolMap;
    string command;
    LexerParser* interpreter = new LexerParser();
    vector<string> listOfCommand;
    while(true){
        cout << "enter new Command, '0' to exit, 'f' to read from file\n";
        getline(cin, command);
        if (command == "0") {
            break;
        }
        // read commands from file
        if (command == "f") {
            interpreter->loadfile(fileName);
            interpreter->lexByValue();
        }
        // read one command
        else{
            listOfCommand = interpreter->lexer(command);
            if (listOfCommand.empty()){
                break;
            }
        }
        interpreter->parser();
    }
    delete interpreter;
}




