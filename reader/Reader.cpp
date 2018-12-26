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
        //**********************//
        // if there is an error
        if (endFlag) {
            pthread_mutex_lock(threads.mutex);
            bool tempServer = threads.serverThreadIsRun;
            bool tempClient = threads.clientThreadIsRun;
            pthread_mutex_unlock(threads.mutex);
            if (tempServer){
                pthread_mutex_lock(threads.mutex);
                threads.serverThreadIsRun = false;
                pthread_mutex_unlock(threads.mutex);
                pthread_join(serverThread, NULL);
            }
            if (tempClient){
                pthread_mutex_lock(threads.mutex);
                threads.clientThreadIsRun = false;
                pthread_mutex_unlock(threads.mutex);
                pthread_join(clientThread, NULL);
            }
            if (interpreter != nullptr) {
                delete (interpreter);
                interpreter = nullptr;
            }
            pthread_mutex_destroy(&mutex);
            return;
        }
    }

    while (true) {
        cout << "enter new Command in cmd, press enter or '0' to exit\n";
        getline(cin, command);
        if (command == "0" || command == "") {
            endFlag = true;
        }
            // read one command
        else {
            endFlag = readCommandsFromCmd(command, interpreter);
        }
        // if there is an error
        if (endFlag) {
            /*
            pthread_mutex_lock(threads.mutex);
            if (threads.serverThreadIsRun){
                threads.serverThreadIsRun = false;
                pthread_join(serverThread, NULL);
            }
            if (threads.clientThreadIsRun){
                threads.clientThreadIsRun = false;
                pthread_join(clientThread, NULL);
            }
            pthread_mutex_unlock(threads.mutex);
            delete (interpreter);
            pthread_mutex_destroy(&mutex);
            return;*/
            pthread_mutex_lock(threads.mutex);
            bool tempServer = threads.serverThreadIsRun;
            bool tempClient = threads.clientThreadIsRun;
            pthread_mutex_unlock(threads.mutex);
            if (tempServer){
                pthread_mutex_lock(threads.mutex);
                threads.serverThreadIsRun = false;
                pthread_mutex_unlock(threads.mutex);
                pthread_join(serverThread, NULL);
            }
            if (tempClient){
                pthread_mutex_lock(threads.mutex);
                threads.clientThreadIsRun = false;
                pthread_mutex_unlock(threads.mutex);
                pthread_join(clientThread, NULL);
            }
            if (interpreter!=nullptr) {
                delete (interpreter);
                interpreter = nullptr;
            }
            pthread_mutex_destroy(&mutex);
            return;
        }
    }
}