//
// Created by User on 6/22/2022.
//

#ifndef HW3_NEW_MODEL_H
#define HW3_NEW_MODEL_H
#include "SimObject.h"
#include "Warehouse.h"

#include "Truck.h"
#include <map>
#include <memory>
#include <vector>
#include "Validation.h"
#include "transportationException.h"


class Model {
private:
    Model() {}; // PRIVATE CONSTRUCTOR TO SINGLETON
    static Model *instance;
    map<const string , shared_ptr<SimObject>> objects;
    map<const string , shared_ptr<Vehicle>> vehicle;
    map<const string , shared_ptr<Warehouse>> warehouses;
public:
    static Model &getInsatnce(); // GETTER FOR THE OBJECT
    void init_warehouse(const string &file);                     // FIRST INITIALIZING OF THE WAREHOUSES FROM FILE
    void init_truck(const string &file);
    void is_valid_course(vector<vector<string> > &data);
};


#endif //HW3_NEW_MODEL_H
