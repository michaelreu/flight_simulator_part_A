
#include "xmlReader.h"
xmlReader::xmlReader() {
    initVecOfPaths();
}

void xmlReader::initVecOfPaths() {
    xmlPathsVec = { INDICATE_SPEED, INDICATE_ALT, PRESSURE_ALT, PITCH_DEG, ROLL_DEG, IN_PITCH_DEG, IN_ROLL_DEG,
                    ENC_INDICATE_ALT, ENC_PRESURE_ALT, GPS_ALT, GPS_GRND_SPD, GPS_VERTICAL_SPD, HEAD_DEG, CMPS_HEAD_DEG,
                    SLIP_SKID, TURN_RATE, SPEED_FPM, AILERON, ELEVATOR, RUDDER, FLAPS, THROTTLE, RPM};
}

const vector<string> &xmlReader::getXmlPathsVec() const {
    return this->xmlPathsVec;
}
