

#include "Warehouse.h"



Warehouse :: Warehouse(const string& name , pair<float , float>& loc , long amount):
        SimObject(name , loc) , amount(amount){
}



void Warehouse ::operator -=(const int& a ){
    amount-=a;
}



void Warehouse::operator +=(const int& a ){
    amount+=a;
}
const long& Warehouse:: get_amount(){
    return amount;
}



ostream& operator<<(ostream& os, Warehouse& obj){
    os << "Warehouse "
    << obj.getName()
    <<" at position ("
    <<obj.getLocation().first << ", "
    <<obj.getLocation().second
    << "), Inventory: "
    << obj.get_amount();
    return os;

}