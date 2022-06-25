
#include "SimObject.h"

SimObject::SimObject(const string& s_name , pair<float , float> loc):
        name(s_name) , location(loc){}


const string& SimObject::getName(){
    return name;
}
const pair<float ,float>& SimObject::getLocation(){
    return location;
}

void SimObject:: setLocation(pair<float ,float>& loc){
    location = loc;
}
