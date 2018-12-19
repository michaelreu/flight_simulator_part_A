
#include "reader/Reader.h"


int main() {
    SymbolTable s = SymbolTable();
    //SymbolTable s = SymbolTable();
    //LexerParser l= LexerParser(s);
    //l.initMapOfCommands();
    Reader start;
    start.readCommands();
    return 0;


}
//run "t.txt"