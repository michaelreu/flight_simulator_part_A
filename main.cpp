
#include "reader/Reader.h"


int main(int argc, char *argv[]) {
    Reader* start = new Reader();
    start->run(argc, argv);
    delete(start);
}