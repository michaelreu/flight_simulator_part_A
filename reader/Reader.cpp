
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
    bool endFlag = false;
    string command;
    int sockArr[NUM_OF_SOCK];
    for (int i = 0; i < NUM_OF_SOCK; i++) {    //initialize sockets values
        sockArr[i] = -1;
    }
    pthread_t thread;
    pthread_mutex_t lock;

    if (pthread_mutex_init(&lock, NULL)) {
        cout << "mutex initialization error" << endl;
        return;
    }
    threadParams threads;
    threads.thread = &thread;
    threads.lock = &lock;

    LexerParser *interpreter = new LexerParser(&threads);
    //executing scripts from all file paths passed as arguments
    for (int j = 0; j < argc; j++) {
        endFlag = readCommandsFromFile(argv[j], interpreter);
        if (endFlag) {
            delete (interpreter);
            pthread_join(thread, NULL);
            pthread_mutex_destroy(&lock);
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

        if (endFlag) {
            delete (interpreter);
            pthread_join(thread, NULL);
            pthread_mutex_destroy(&lock);
            return;
        }
    }
}



