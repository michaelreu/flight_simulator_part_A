#include "Reader.h"
using namespace std;

void Reader::lexer() {
    string command;
    vector<string> listOfCommand;
    while (true) {
        cout << "enter new Command - 0 to exit\n";
        getline(cin, command);
        if (command == "0"){
            break;
        }
        // split the data
        istringstream iss(command);
        for (string s; iss >> s;) {
            listOfCommand.push_back(s);
        }
        // if needed to read from a file
        if (listOfCommand[0] == "run") {
            dataVector = loadfile(listOfCommand[1].substr(1, listOfCommand[1].size() - 2));
        }
        // make the commands
        initCommandMap();
        parser();
        listOfCommand.clear();
    }
}


vector<string> Reader::loadfile(const string& fileName){
    string expression;
    vector<string> dataFromFile;
    ifstream myFile(fileName);
    if (myFile.is_open()) {
        while (myFile >> expression) {
            dataFromFile.push_back(expression);
        }
        myFile.close();
    }
    return dataFromFile;
}

void Reader::parser(){

    vector<string>::iterator it;
    for (it = dataVector.begin(); it != dataVector.end(); it++) {
        // make command
        if(getCommandsMap().count(*it)){
            ((commandsMap[(*it)])->calculate());
        // if the command is set var
        }else if(vars.count(*it)){
            //vars[dataVector[index]] **************************
        }
        else{

        }
    }


}
map<string, Expression*>& Reader::getCommandsMap() {
    return this->commandsMap;

}

vector<string>& Reader::getVector() {
    return this->dataVector;

}

void Reader::initCommandMap(){
    getCommandsMap()["OpenServerCommand"] = (new ExpressionCommand(new OpenServerCommand(&dataVector)));

}

