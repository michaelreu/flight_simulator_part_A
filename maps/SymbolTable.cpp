#include "SymbolTable.h"



SymbolTable::SymbolTable(threadParams *threadsParam) {
    initPathXmlVec();
    this->threadsParam = threadsParam;
}

void SymbolTable::initPathXmlVec() {
    xmlPathsVec = { INDICATE_SPEED, INDICATE_ALT, PRESSURE_ALT, PITCH_DEG, ROLL_DEG, IN_PITCH_DEG, IN_ROLL_DEG,
                    ENC_INDICATE_ALT, ENC_PRESURE_ALT, GPS_ALT, GPS_GRND_SPD, GPS_VERTICAL_SPD, HEAD_DEG, CMPS_HEAD_DEG,
                    SLIP_SKID, TURN_RATE, SPEED_FPM, AILERON, ELEVATOR, RUDDER, FLAPS, THROTTLE, RPM};
}
void SymbolTable::initVar(const string &key) {
    valuesMapVarToValue.insert({key,ZERO_INIT});
    destinationMapVarToPath.insert({key, ""});
}
void SymbolTable::addValuesToMap(string &key, double value) {
    pthread_mutex_lock(this->threadsParam->mutex);
    valuesMapVarToValue.at(key) = value;
    // if is not on map already
    if(!(find(changedArgsVec.begin(), changedArgsVec.end(), key) != changedArgsVec.end())) {
        changedArgsVec.push_back(key);
    }
    pthread_mutex_unlock(this->threadsParam->mutex);
}

vector<string>& SymbolTable::getChangedArgsVec() {
    return changedArgsVec;
}

void SymbolTable::addDestinationToMap(string &key, string &dest) {
    pthread_mutex_lock(this->threadsParam->mutex);
    string pathDest = dest;
    // type of x = bind y - means: dest will be y
    if (destinationMapVarToPath.count(dest) == IN_MAP){
        //then the path will be the value of y in the destinationMap
        pathDest = destinationMapVarToPath[dest];
    }
    destinationMapVarToPath.at(key) = pathDest;
    //add the var to vector of vars that belongs to a path in the bind map
    bindMapPathToVecOfVars[pathDest].push_back(key);
    pthread_mutex_unlock(this->threadsParam->mutex);
}

bool SymbolTable::isVarInMap(const string &key) {
    return ((destinationMapVarToPath.count(key) == IN_MAP) && (valuesMapVarToValue.count(key)==IN_MAP));
}


bool SymbolTable::isVarInValueMap(const string &key) {
    if (valuesMapVarToValue.count(key)==IN_MAP) {
        return ((valuesMapVarToValue.count(key)==IN_MAP));
    }
}
bool SymbolTable::isVarInBindsMap(const string &key) {
    string path;
    map <string, vector<string>>::iterator it;
    for(it = bindMapPathToVecOfVars.begin(); it != bindMapPathToVecOfVars.end(); it++){
        for (string var : it->second) {
            if (var==key) {
                return true;
            }
        }
    }
    return false;
}

string SymbolTable::getPathByVar(const string &keyVar) {
    if (isVarInMap(keyVar)) {
        return (destinationMapVarToPath.at(keyVar));
    }
}
double SymbolTable::getValueOfVar(const string &key) {
    return (valuesMapVarToValue.at(key));
}


void SymbolTable::updateValuesFromClient(vector<double> &vecOfVals) {
    pthread_mutex_lock(this->threadsParam->mutex);
    string tempPath;
    vector<string>varsOfSpecificPath;
    for (unsigned long i = 0; i < vecOfVals.size(); ++i) {
        tempPath = xmlPathsVec.at(i);
        if (bindMapPathToVecOfVars.count(tempPath) > 0) {
            varsOfSpecificPath = bindMapPathToVecOfVars[tempPath];

            for (string var : varsOfSpecificPath) {
                valuesMapVarToValue[var] = vecOfVals.at(i);
            }
        }
    }
    pthread_mutex_unlock(this->threadsParam->mutex);
}


