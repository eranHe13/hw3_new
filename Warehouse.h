//
// Created by User on 6/22/2022.
//

#ifndef HW3_NEW_WAREHOUSE_H
#define HW3_NEW_WAREHOUSE_H
#include "SimObject.h"

class Warehouse: public SimObject{
private:
    long amount;
public:
    Warehouse(const string& name , pair<float , float>& loc , long amount);
    const long& get_amount();
    void operator -=(const int& a );
    void operator +=(const int& a );
    friend ostream& operator<<(ostream& os, const Warehouse& obj);

};


#endif //HW3_NEW_WAREHOUSE_H
