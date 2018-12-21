
#include "reader/Reader.h"


int main(int argc, char *argv[]) {
    try {
        Reader start;
        start.readCommands(argv[1]);
        return 0;
    }
    catch (string e) {
        cout<<e<<endl;
        cout<<"That's not supposed to happen !!!!!!!!!!!!"<<endl;
    }
}
//run "t.txt"