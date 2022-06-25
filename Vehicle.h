

#ifndef HW3_NEW_VEHICLE_H
#define HW3_NEW_VEHICLE_H
#include "SimObject.h"
#include "Warehouse.h"
#include <vector>
#include <memory>
#include <map>
/*
 * STATS OF VEHICLES
 * */
static const string Stopped = "Stopped";
static const string Parked = "Parked";
static const string Off_road = "Off road";
static const string Moving_to = "Moving to";

class Vehicle :public SimObject{
private:
    string state;
    float speed;
    pair< string , pair<float ,float>> curr_destination;
    float distance_to_destination ;
public:
    Vehicle(const string& truck_name , const pair<float,float>&  loc  );                                                //CONSTRUCTOR FOR TRUCK
    const float & get_speed() const;                                                   // GETTER SPEED
    const string& get_status() const;                                               // GETTER STATUS
    const float& get_dis_to_dest();
    const pair< string , pair<float ,float>>& get_curr_destination() const  ;

    void update_status(const string& curr_state);                                   // SETTER STATUS
    void update_destination(string& warehouse ,const pair<float ,float>& to);          // SETTER LOCATION
    void update_speed(float & s);                                                   // SETTER FOR SPEED
    void update_dis_to_dest(const float& d);

    virtual void course_func(vector<string>& data) =0;
    virtual void position_func(vector<string>& data)=0;
    virtual void destination_func(vector<string>& data)=0;
    virtual void attack_func(vector<string>& data)=0;
    virtual void stop_func()=0;
    virtual void go(const int& time, map<const string , shared_ptr<Warehouse>>& all_warehouses)=0;

};


#endif //HW3_NEW_VEHICLE_H
