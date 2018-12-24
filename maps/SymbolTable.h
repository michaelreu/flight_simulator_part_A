
#ifndef INC_14_12_12_46_VARIABLESMAP_H
#define INC_14_12_12_46_VARIABLESMAP_H
#define IN_MAP 1
#define INIT_ERR "Error: this var is not initialized: "
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
#define THROTTLE "/controls/engines/current-engine/throttle"
#define RPM "/engines/engine/rpm"
#include <string>
#include <map>
#include <vector>
#include "VarValue.h"
#include <algorithm>

using namespace std;
class VarValue;
class SymbolTable {
private:
    //key - var, value - double, bool initialized
    map<const string, VarValue> valuesMapVarToValue;
    //key - var, value - path
    map<string, string> destinationMapVarToPath;
    //each path has number of parameters that can be mapped to it
    map<string,vector<string>> bindMapPathToVecOfVars;
    //vector of the changes
    vector<string> changedArgsVec;

    vector<string> xmlPathsVec;
    pthread_mutex_t mutex;

public:
    SymbolTable ();
    void initPathXmlVec();
    void initVar(const string &key);
    void addValuesToMap(string &key, double value);
    void addDestinationToMap(string &key, string &dest);
    bool isVarInMap(const string &key);
    bool isVarInValueMap(const string &key);
    bool isVarInBindsMap(const string &key);
    double getValueOfVar(const string &key);
    void updateValuesFromClient(vector<double>&vecOfVals);
    string getPathByVar(const string &keyVar);
    vector<string> &getChangedArgsVec();
    pthread_mutex_t* getMutex();
    ~SymbolTable();


};

#endif //INC_14_12_12_46_VARIABLESMAP_H
