//
// Created by User on 6/22/2022.
//

#include "Functions.h"

float Distance1(const pair<float,float>& from ,const pair<float,float>& to )
{
    float x1 = from.first;
    float y1 = from.second;
    float x2 = to.first;
    float y2 = to.second;
    float res = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) )*100;
    return res;
}


float& calc_speed( const pair<float,float>& from ,const pair<float,float>& to ){
    const float dis = Distance1(from , to);
    const float t  = Time :: get_Travel_time(course.at(from.getName()).first,course.at(to.getName()).first);
    float speed = dis / t;
    return speed;
}