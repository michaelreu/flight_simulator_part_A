#include "Command.h"

SleepCommand::SleepCommand(long time){
    this->time =time;
}

void SleepCommand::execute(){
    this_thread::sleep_for(chrono::milliseconds(time));
}