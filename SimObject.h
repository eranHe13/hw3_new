//
// Created by User on 6/22/2022.
//

#ifndef HW3_NEW_SIMOBJECT_H
#define HW3_NEW_SIMOBJECT_H
#include <string>
#include <ostream>

using namespace std;
class SimObject {
private:
    string name;
    pair<float , float> location;
public:
    SimObject(const string& s_name , pair<float , float> location);
    const string& getName();
    const pair<float ,float>& getLocation();
    void setLocation(pair<float ,float>& loc);

};


#endif //HW3_NEW_SIMOBJECT_H
