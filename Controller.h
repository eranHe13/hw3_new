

#ifndef HW3_NEW_CONTROLLER_H
#define HW3_NEW_CONTROLLER_H

#include "Model.h"
#include "transportationException.h"
#include <iostream>

class Controller {
    Model model;
    int time;
public:
    Controller() : model(model.getInsatnce()), time(0) {};

    void init(int size, const char **files);

    void simulation(vector<string> &data, const int &time);

    void user_interaction();

};
#endif //HW3_NEW_CONTROLLER_H
