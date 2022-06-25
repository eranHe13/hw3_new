

#include "View.h"

View::View()
:size(DEFAULT_SIZE),
scale(DEFAULT_SCALE),
origin(make_pair(-23.7,-22.7))
{
    commands["default"] = DEFAULT;
    commands["size"] = SIZE;
    commands["zoom"] = ZOOM;
    commands["pan"] = PAN;
    commands["show"] = SHOW;
}

void View::set_default() {
    setSize(DEFAULT_SIZE);
    setScale(DEFAULT_SCALE);
    setOrigin(DEFAULT_ORIGIN, DEFAULT_ORIGIN);
}

void View::show() const {
    cout << "Display size: " << size << ", scale: " << scale
    << ", origin: (" << origin.first << "," << origin.second << ")" << endl;

    show_map();
}

/**
 * showing the map
 */
void View::show_map() const{
    if(!is_show_able()){
        cerr << "ERROR: can't display on this sizes please change";
        return;
    }
    Model model = Model::getInsatnce();
    int edge_y = (int) origin.second + size * scale - scale;
    string dot = ". ";
    int steps = 3;
    int spaces = 4;
    for(int i=0; i < size; i++){
        string header;
        if(!(i % steps)){
            int added_spaces = spaces - to_string(edge_y).length();
            header.append(added_spaces, ' ');
            header += to_string(edge_y);
        }
        else{
            header.append(spaces, ' ');
        }
        cout << header << " ";
        edge_y -= (int) scale;
        for(int j=0; j < size; j++){
            cout << dot;
//          TODO - add if there is object in this area
//          y = edge_y - i * scale
//          x = origin.x + j * scale
        }
        cout << endl;
    }
    // print the x-axis
    print_x_axis();
}

void View::print_x_axis() const{
    int edge_x = ceil(origin.first + size * scale - scale);
    int x_axis = (int) origin.first;
    while(x_axis <= edge_x){
        string s(6 - to_string(x_axis).length(), ' ');
        s += to_string(x_axis);
        cout << s;
        x_axis += scale * 3;
    }
    cout << endl;
}

bool View::is_show_able() const{
    double edge_x = origin.first + size * scale - scale;
    double edge_y = origin.second + size * scale - scale;
    bool res =  !(abs(origin.first) > MAX_SHOW || abs(origin.second) > MAX_SHOW ||
      abs(edge_x) > MAX_SHOW || abs(edge_y) > MAX_SHOW);
    return res;

}

int View::getSize() const {
    return size;
}

void View::setSize(int size) {
    View::size = size;
}

double View::getScale() const {
    return scale;
}

void View::setScale(double scale) {
    View::scale = scale;
}

const pair<double, double> &View::getOrigin() const {
    return origin;
}

void View::setOrigin(double x, double y) {
    origin.first = x;
    origin.second = y;
}

std::ostream &operator<<(std::ostream &os, const View &view) {
    os << "size: " << view.size << " scale: " << view.scale << " origin: " << view.origin.first;
    return os;
}

/**
 * preform the commands for the view obj
 * assuming the vars are already have been validated
 * @param cmd - the command to be execute
 * @param vars - vars for the different commands
 */
void View::operator()(const string& cmd, const vector<string>& vars){
    switch(commands[cmd]){
        case DEFAULT:
            set_default();
            break;
        case SIZE: {
            int _size = stoi(vars[1]);
            setSize(_size);
        }
            break;
        case ZOOM: {
            double _scale = stod(vars[1]);
            setScale(_scale);
        }
            break;
        case PAN: {
            double _x = stod(vars[1]);
            double _y = stod(vars[2]);
            setOrigin(_x, _y);
        }
            break;
        case SHOW:
            show();
            break;
    }
}
