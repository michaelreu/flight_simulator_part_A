
#include "reader/Reader.h"
#define FILE_NAME 1

int main(int argc, char *argv[]) {
    try {
        Reader start;
        start.readCommands(argv[FILE_NAME]);
        ConnectCommand::stop();
        OpenServerCommand::stop();
        return 0;
    }
    catch (char* e) {
        cout<<e<<endl;
        cout<<"That's not supposed to happen !!!!!!!!!!!!"<<endl;
    } catch (string &e) {
        cout<<e<<endl;
        cout<<"That's not supposed to happen !!!!!!!!!!!!"<<endl;
    }
}
//run "t.txt"