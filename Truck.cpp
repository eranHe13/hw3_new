//
// Created by User on 6/22/2022.
//

#include "Truck.h"
Truck::Truck(const string &name,const pair<float,float> &loc ,vector<vector<string> >& data ,
             map<const string , shared_ptr<Warehouse>> all_warehouses):
            Vehicle(name, loc),warehouses(0),amount(0)
{   for(auto& s : data){
        update_course(s);
    }
    set_speed(*all_warehouses[warehouses[0]].get() , *all_warehouses[warehouses[1]].get());
    update_destination(warehouses[1] ,all_warehouses[warehouses[1]].get()->getLocation());
    update_dis_to_dest(Distance1(getLocation(),all_warehouses[warehouses[1]].get()->getLocation()));
    update_status("parked");
    for(const auto& a: course){
        cout << a.second.second <<" ";
        amount+=a.second.second;
    }
    *all_warehouses.at(data[0][0]).get() -= amount;

}
/*
 * GET EACH WAREHOUSE OF THE COURSE BY ORDER
 * PARSE AND INIT THE DATA
 * DATA = <WAREHOUSE> <ARRIVING_TIME> <INVENTORY_AMOUNT> <LIVING TIME>
 * */

void Truck:: update_course(vector<string>& data ){
    if(data.size() == 2){ // FIRST WAREHOUSE NOT HAS ARRIVING TIME AND INVENTORY AMOUNT
        int living_hour = stoi(data[1].substr( 0, data[1].find(':')));
        int living_min = stoi(data[1].substr(  data[1].find(':')+1));
        Time T(-1,-1,living_hour , living_min);
        warehouses.push_back(data[0]);
        course.insert( { data[0] ,  {T, 0} } )  ;
    }
    else{ // NOT FIRST WAREHOUSE HAS ARRIVING TIME AND INVENTORY AMOUNT
        Time T(data[1] , data[3]);
        warehouses.push_back(data[0]);
        course.insert( { data[0] ,  {T, stoi(data[2])} } );
    }

}


/*
 * GET TOW WAREHOUSES IN THE COURSE AND SET THE SPEED USING DISTANCE FUNCTION
 * */
void Truck:: set_speed( Warehouse& from , Warehouse& to ){
    const float dis = Distance1(from.getLocation() , to.getLocation());
    const float t  = Time :: get_Travel_time(course.at(from.getName()).first,course.at(to.getName()).first);
    update_dis_to_dest(dis);
    float speed = dis / t;
    update_speed(speed);
}

void Truck:: course_func(vector<string>& data){
    string state = "course";
    update_status(state);
    int angle = stof(data[2]) ;
    float res_angle = (450-angle) % 360;
    int rad = 10000000;
    pair<float , float> end_point_line ={cos(res_angle)*rad ,sin(res_angle)*rad };
    update_destination(state , end_point_line);
}



void Truck::position_func(vector<string>& data){
    cout << "NO POSSIBLE FOR TRUCK" << endl;
//    pair<float, float> loc(stof(data[2]), stof(data[3])); // PARSE LOCATION
//    string state = "position";
//    update_status(state);
//    float distance = Distance1(getLocation() , loc);
//    update_dis_to_dest(distance);
//    update_destination(state , loc);
}
void Truck::destination_func(vector<string>& data ) { cout << "NO POSSIBLE FOR TRUCK" << endl;}
void Truck::attack_func(vector<string>& data) { cout << "NO POSSIBLE FOR TRUCK" << endl;}
void Truck::stop_func() { update_status("stop");}


void Truck::move_truck(const pair<float,float>& to){
    float dist = Distance1(getLocation() , to);
    float t = get_speed() / dist;
    float x = ((1.0 - t) * getLocation().first +
               t * to.first);
    float y = ((1 - t) * getLocation().second +
               t * to.second);
    pair<float , float> loc = {x,y};
    setLocation(loc);

}



void Truck:: go(const int& time, map<const string , shared_ptr<Warehouse>>& all_warehouses ){
//    if(get_status() == "course"){
//        move_truck(get_curr_destination().second); /// truck drive on angle so just moving forward
//        return;
//    }
//    if(get_status() == "position"){ /// truck has a destination by point
//        if(get_dis_to_dest() <= get_speed()){ /// if distance smaller then the speed , stop on the point
//            pair<float,float> dest = get_curr_destination().second;
//            setLocation(dest);
//            update_status("parked on position");
//        }
//        else{ /// distance to points is more then the truck can do in hour so just moving forward
//            move_truck(get_curr_destination().second);
//            update_dis_to_dest(Distance1(getLocation() , get_curr_destination().second));
//        }
//        return;
//    }
    /// default course for the truck
    ///if arrival time to destination if bigger then time -- > move forward

    if(get_status() == "parked"){
        if(course.at(warehouses[0]).first.get_living_time() < )
    }


    if(course.at(get_curr_destination().first).first.get_arrival_time().hour >= time){
        move_truck(get_curr_destination().second);
        return;
    }

    else{ /// truck arrived to destination
        pair<float,float> dest = get_curr_destination().second;
        setLocation(dest);
        if(!warehouses.empty()) {warehouses.erase(warehouses.begin());}
        else{
            cout << "NO COURSE FOR TRUCK\n";
            return;
        } ///// TODO -- KEEP GOING FROM HERE -- > IF TRUCK ARRIVED CHECK IF NEED TO KEEP GOING TO TO PARK BY TIME
        update_destination(warehouses[0] , all_warehouses.at(warehouses[0])->getLocation());
        update_speed(calc_speed(getLocation(),all_warehouses.at(warehouses[0])->getLocation()));

    }



    if(get_dis_to_dest() <= get_speed()){
        if(warehouses.empty()){
            cout << "NO COURSE FOR TRUCK\n";
            return;
        }



    }


};
