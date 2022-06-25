
#include "Model.h"
Model *Model::instance = nullptr;

Model &Model::getInsatnce() {
    if (!instance) {
        instance = new Model();
    }
    return *instance;
}

/*
 * FIRST INITIALIZING OF THE WAREHOUSES FROM FILE
 *  - SEND FILE TO CHECK VALIDATION
 *  - PARSING DATA AND INIT CURRENT WAREHOUSE
 *  - CREATE ANYWAY "Frankfurt" WAREHOUSE
 * IF THERE IS ANY NOT VALID DATA , PROGRAM END
 */
void Model::init_warehouse(const string &file) {
    vector<vector<string> > data;
    is_warehouse_valid(file, data);
    for (auto &d: data) {
        pair<float, float> loc(stof(d[1]), stof(d[2])); // PARSE LOCATION
        long amount;
        stringstream ss1;
        ss1 << d[3];
        ss1 >> amount;                                                   // PARSE INVENTORY AMOUNT
        shared_ptr<Warehouse> p = make_shared<Warehouse>(d[0], loc, amount); // CRATE WAREHOUSE
        instance->objects.insert({d[0], p});
        instance->warehouses.insert({d[0], shared_ptr<Warehouse>(p)});
    }
    string w = "Frankfurt";
    pair<float, float> loc = {40, 10};
    long amount = 100000;
    shared_ptr<Warehouse> p = make_shared<Warehouse>(w, loc, amount);
    instance->objects.insert({w, p});
    instance->warehouses.insert({w, shared_ptr<Warehouse>(p)});
}

/*
 * FIRST INITIALIZING TRUCKS FROM FILE
 *  - SEND FILE TO CHECK VALIDATION
 *  - CHECK IF THE COURSE DATA IS VALID
 *  - PARSING DATA AND INIT CURRENT TRUCK
 * IF THERE IS ANY NOT VALID DATA , PROGRAM END
 */
void Model::init_truck(const string &file) {
    vector<vector<string> > data;
    is_truck_valid(file, data);
    is_valid_course(data);
    const string truck_name = file.substr(0, file.find('.'));
    const pair<float, float> &first_location = instance->warehouses[data[0][0]].get()->getLocation();
    shared_ptr<Truck> p = make_shared<Truck>(truck_name,first_location, data, instance->warehouses);
    instance->objects.insert({truck_name,p});
    instance->vehicle.insert({truck_name, p});
}



void Model::is_valid_course(vector<vector<string> > &data) {
    for (auto &s: data) {
        if (instance->warehouses.find(s[0]) == instance->warehouses.end())
            throw TransportException(s[0] + " NOT INCLUDE IN THE MAP");
    }
}
