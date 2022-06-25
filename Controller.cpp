//
// Created by User on 6/22/2022.
//

#include "Controller.h"

void Controller::init(int size, const char **files) {
    ///  initializing first files
    vector<string> input;
    for (int i = 1; i < size; i++) {
        input.emplace_back(files[i]);
    }
    try {
        for (int i = 0; i < input.size(); i++) {
            /// INPUT FILES
            if (input[i] == "-w") {
                i++;
                /// TODO -- CHECK IF CAN TAKE ANY NAME OF FILE  --- OR JUST "Depot.dat"
                model.init_warehouse(input[i]);
            }
            if (input[i] == "-t") {
                for (int j = ++i; j < input.size(); j++) {
                    model.init_truck(input[j]);
                }
            }
        }
    }
    catch (TransportException &e) { ///////ERROR ON INIT THE PROGRAM , EXIT
        cout << e.what();
        exit(0);
    }

}