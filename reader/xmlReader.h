
#ifndef INC_14_12_12_46_XMLREADER_H
#define INC_14_12_12_46_XMLREADER_H

#define INDICATE_SPEED "/instrumentation/airspeed-indicator/indicated-speed-kt"
#define INDICATE_ALT "/instrumentation/altimeter/indicated-altitude-ft"
#define PRESSURE_ALT "/instrumentation/altimeter/pressure-alt-ft"
#define PITCH_DEG "/instrumentation/attitude-indicator/indicated-pitch-deg"
#define ROLL_DEG "/instrumentation/attitude-indicator/indicated-roll-deg"
#define IN_PITCH_DEG "/instrumentation/attitude-indicator/internal-pitch-deg"
#define IN_ROLL_DEG "/instrumentation/attitude-indicator/internal-roll-deg"
#define ENC_INDICATE_ALT "/instrumentation/encoder/indicated-altitude-ft"
#define ENC_PRESURE_ALT "/instrumentation/encoder/pressure-alt-ft"
#define GPS_ALT "/instrumentation/gps/indicated-altitude-ft"
#define GPS_GRND_SPD "/instrumentation/gps/indicated-ground-speed-kt"
#define GPS_VERTICAL_SPD "/instrumentation/gps/indicated-vertical-speed"
#define HEAD_DEG "/instrumentation/heading-indicator/indicated-heading-deg"
#define CMPS_HEAD_DEG "/instrumentation/magnetic-compass/indicated-heading-deg"
#define SLIP_SKID "/instrumentation/slip-skid-ball/indicated-slip-skid"
#define TURN_RATE "/instrumentation/turn-indicator/indicated-turn-rate"
#define SPEED_FPM "/instrumentation/vertical-speed-indicator/indicated-speed-fpm"
#define AILERON "/controls/flight/aileron"
#define ELEVATOR "/controls/flight/elevator"
#define RUDDER "/controls/flight/rudder"
#define FLAPS "/controls/flight/flaps"
#define THROTTLE "/controls/engines/engine/throttle"
#define RPM "/engines/engine/rpm"

#include <string>
#include <vector>

using namespace std;

class xmlReader {
private:
    vector<string> xmlPathsVec;
    void initVecOfPaths();

public:
    xmlReader();
    const vector<string> &getXmlPathsVec() const;
};


#endif //INC_14_12_12_46_XMLREADER_H
