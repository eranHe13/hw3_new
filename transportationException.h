//
// Created by User on 6/1/2022.
//

#ifndef HW3_TRANSPORTATIONEXCEPTION_H
#define HW3_TRANSPORTATIONEXCEPTION_H


#include <exception>
#include <string>
using namespace std;

class TransportException: public exception{

protected:
    std::string e;

public:
    explicit TransportException(string  e): e(std::move(e)){}

    virtual std::string what(){
        return "ERROR: " + e;
    }
};




#endif //HW3_TRANSPORTATIONEXCEPTION_H
