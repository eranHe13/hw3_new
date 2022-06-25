//
// Created by User on 6/11/2022.
//

#ifndef HW3_TIME_H
#define HW3_TIME_H
#include <string>
using namespace std;

typedef struct tm1{
    int hour;
    int minute;
} TM;

class Time {
private:
    TM arrival;
    TM living;

public:
    Time(int ar_hour , int ar_minute , int li_hour , int li_minute):
        arrival({ar_hour, ar_minute}) , living({li_hour, li_minute}){
    }
    static const float get_Travel_time(const Time& from , const Time& to ){
        float minutes = to.arrival.minute - from.living.minute;
        float hour = to.arrival.hour - from.living.hour;
        if(minutes< 0 ){
            hour--;
            minutes=60+minutes;
        }
        float d = hour+(minutes/60);
        return d;
    }


    Time(string& arrival_s ,string& living_s  ){
        int arr_hour = stoi(arrival_s.substr( 0, arrival_s.find(':')));
        int arr_min = stoi(arrival_s.substr(  arrival_s.find(':')+1));
        int liv_hour = stoi(living_s.substr( 0, living_s.find(':')));
        int liv_min = stoi(living_s.substr(  living_s.find(':')+1));
        arrival = {arr_hour , arr_min};
        living = {liv_hour , liv_min};
    }

    const TM& get_arrival_time(){
        return arrival;
    }

    const TM& get_living_time(){
        return living;
    }
};


#endif //HW3_TIME_H
