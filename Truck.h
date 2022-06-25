

#ifndef HW3_NEW_TRUCK_H
#define HW3_NEW_TRUCK_H
#include <vector>
#include <memory>
#include <map>
#include "Vehicle.h"
#include "Time.h"
#include "Warehouse.h"
#include "iostream"
#include "Functions.h"

class Truck:public Vehicle{
private:
    vector <  string > warehouses; // ORDER VECTOR OF THE WAREHOUSES
    map< string ,pair<Time  , long > > course; // DATA ON EACH WAREHOUSE
    long amount; // CURRENT AMOUNT OF INVENTORY IN THE TRUCK
public:
    Truck(const string &name,const pair<float,float> &loc ,vector<vector<string> >& data ,
          map<const string , shared_ptr<Warehouse>> all_warehouses);

    void set_speed( Warehouse& from , Warehouse& to ); // PARSE AND CALCULATE SPEED
    void update_amount(const string& commend , long& amount); // SETTER AMOUNT INVENTORY
    void update_course(vector<string>& data ); //
    void print_status() const ;
    friend ostream& operator<<(ostream& os, const Truck& obj);
    void operator+=(const int& n);
    void operator-=(const int& n);

    void course_func(vector<string>& data) override;
    void position_func(vector<string>& data)override ;
    void destination_func(vector<string>& data) override;
    void attack_func(vector<string>& data)override;
    void stop_func()override ;
    void go(const int& time, map<const string , shared_ptr<Warehouse>>& all_warehouses) override ;

    void move_truck(const pair<float,float>& to );

};



#endif //HW3_NEW_TRUCK_H
