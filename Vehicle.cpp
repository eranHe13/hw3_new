
#include "Vehicle.h"



Vehicle::Vehicle(const string& truck_name , const pair<float,float>&  loc ):
        SimObject(truck_name,loc),state(Parked),speed(0),curr_destination({"",{0,0}}),
        distance_to_destination(0){}



void Vehicle:: update_destination(string& warehouse ,const pair<float ,float>& to){
    curr_destination = {warehouse , to};

}

void Vehicle:: update_status(const string& curr_state){
    state = curr_state;
}

void Vehicle::update_speed(float & s){
    speed = s;
}

void Vehicle::update_dis_to_dest(const float& d){
    distance_to_destination= d;
}

const string& Vehicle:: get_status() const{
    return state;
}

const pair<string, pair<float, float>> &Vehicle::get_curr_destination() const {
    return curr_destination;
}

const float &Vehicle::get_dis_to_dest() {
    return distance_to_destination;
}

const float &Vehicle::get_speed() const {
    return speed;
}
