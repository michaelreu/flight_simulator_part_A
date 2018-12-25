
#include "Reader.h"

bool Reader::readCommandsFromFile(string fileName, LexerParser *interpreter){
    string command;
    vector<string> *lexerFile;
    lexerFile = interpreter->loadfile(fileName);
    try {
        interpreter->parser(lexerFile);
    }
    catch (char *e) {
        cout << e << endl;
        return true;
    } catch (string &e) {
        cout << e << endl;
        return true;
    }
    return false;
}

bool Reader::readCommandsFromCmd(string command, LexerParser *interpreter) {
    vector<string> *lexerCommand;
    lexerCommand = interpreter->lexerCommand(command);
    try {
        interpreter->parser(lexerCommand);
    }
    catch (char *e) {
        cout << e << endl;
        return true;
    } catch (string &e) {
        cout << e << endl;
        return true;
    }
    return false;
}



void Reader::run(int argc, char* argv[]) {
    string command = "";
    bool endFlag = false;
    pthread_t serverThread;
    pthread_t clientThread;
    pthread_mutex_t mutex;

    if (pthread_mutex_init(&mutex, NULL)) {
        cout << "mutex initialization error" << endl;
        return;
    }
    threadParams threads;
    threads.serverThread = &serverThread;
    threads.clientThread = &clientThread;
    threads.mutex = &mutex;
    threads.serverThreadIsRun = false;
    threads.clientThreadIsRun = false;
    CommandExpressionFactory* commandExpFac = new CommandExpressionFactory(&threads);
    LexerParser *interpreter = new LexerParser(commandExpFac);

    //executing scripts from all file paths passed as arguments
    for (int j = 1; j < argc; j++) {
        endFlag = readCommandsFromFile(argv[j], interpreter);
        //******************************************************************//
        // if there is an error
        if (endFlag) {
            delete (interpreter);
            if (!serverThread){
                pthread_join(serverThread, NULL);
            }
            if (!clientThread){
                pthread_join(clientThread, NULL);
            }
            pthread_mutex_destroy(&mutex);
            return;
        }
    }

    while (true) {
        cout << "enter new Command in cmd or '0' to exit\n";
        getline(cin, command);
        if (command == "0") {
            endFlag = true;
        }
        // read one command
        else {
            endFlag = readCommandsFromCmd(command, interpreter);
        }
        // if there is an error
        if (endFlag) {
            //delete (interpreter);
            if (threads.serverThreadIsRun){
                pthread_join(serverThread, NULL);
            }
            if (threads.clientThreadIsRun){
                pthread_join(clientThread, NULL);
            }
            pthread_mutex_destroy(&mutex);
            return;
        }
    }
}



