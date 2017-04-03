#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//////////////////////////
//       PARTS          //
//////////////////////////
class RobotPart{
protected:
    string namee;
    int model_number;
    double cost;
    double weight;
    string description;
    static string image_filename;
    static int type;
public:
    void makepart();
    int get_cost();
};

void RobotPart::makepart(){
    cout << "Please Enter a Name for the Part: ";
    cin >> namee;
    cout << "Model Number: ";
    cin >> model_number;
    cout << "Description: ";
    cin >> description;
    cout << "Please Enter a weight(In Pounds): ";
    cin >> weight;
    cout << "Please Enter a Cost (In Dollars): ";
    cin >> cost;
}

int RobotPart::get_cost(){
    return cost;
}

class head: public RobotPart{
private:
    double power;
    string p_out;
public:
    void set_power();
    string printout();
};

void head::set_power(){
    cout << "Please Enter Power in Watts: ";
    cin >> power;
};

string head::printout(){
    stringstream p_out;
    p_out << "Part Name:" << namee
    << "\nModel number: #" << model_number;
    return p_out.str();
};

class torso: public RobotPart{
private:
    int battery_compartments;
    int max_arms;
public:
    void set_battery_arms();
    string printout();
};

void torso::set_battery_arms(){
    cout << "Please Enter Battery Compartments (Up To 3): ";
    cin >> battery_compartments;
    cout << "Please Enter Max Arms: ";
    cin >> max_arms;
}
string torso::printout(){
    stringstream p_out;
    p_out << "Part Name:" << namee
    << "\nModel number: #" << model_number;
    return p_out.str();
};

class battery: public RobotPart{
private:
    double max_power;
public:
    void set_power();
    string printout();
};

void battery::set_power(){
    cout << "Please Enter power contained: ";
    cin >> max_power;
    
}
string battery::printout(){
    stringstream p_out;
    p_out << "Part Name:" << namee
    << "\nModel number: #" << model_number;
    return p_out.str();
};

class locomotor: public RobotPart{
private:
    double max_power; // In mph
public:
    void set_max_speed();
    string printout();
};

void locomotor::set_max_speed(){
    cout << "Please Enter Max Speed (in MPH): ";
    cin >> max_power;
}

string locomotor::printout(){
    stringstream p_out;
    p_out << "Part Name:" << namee
    << "\nModel number: #" << model_number;
    return p_out.str();
};

class arm: public RobotPart{
private:
    double max_power;
public:
    void set_power_consumed();
    string printout();
};
void arm::set_power_consumed(){
    cout << "Please set the power consumed: ";
    cin >> max_power;
}
string arm::printout(){
    stringstream p_out;
    p_out << "Part Name:" << namee
    << "\nModel number: #" << model_number;
    return p_out.str();
};

/////////////////////////
//         ROBOT       //
/////////////////////////

class Robot_Model{
private:
    string name;
    int model_number;
    double cost;
    double price;
    int weight;
    string description;
    
    
    torso Torso;
    head Head;
    locomotor Locomotor;
    arm Arm;
    battery Battery;
public:
    double findcost();
    double max_speed();
    double max_battery_life();
    Robot_Model (class head Head, class torso Torso, class arm Arm, class locomotor Locomotor, class battery Battery);
    string printout();
};

Robot_Model::Robot_Model(class head Head, class torso Torso, class arm Arm, class locomotor Locomotor, class battery Battery){
    this->Head = Head;
    this->Torso = Torso;
    this->Arm = Arm;
    this->Locomotor = Locomotor;
    this->Battery = Battery;
    cost = Head.get_cost() + Torso.get_cost() + Arm.get_cost() + Locomotor.get_cost() + Battery.get_cost();
    cout << "Parts registered correct! Now you can name your robot";
    cout << "\nModel Name: ";
    getline(cin, name);
    getline(cin, name);
    cout << "\nModel Number: ";
    cin >> model_number;
    cout << "\n Enter a description for your product";
    getline(cin, description);
    getline(cin, description);
}

string Robot_Model::printout(){
    stringstream p_out;
    p_out << " Robot Name: " << name << "\n Model Number: " << model_number << "\n Price: $" << cost << "\n Weight: " << weight <<"Pounds" << "\n Description: " << description;
    return p_out.str();
}
/////////////////////////
//   Project Manager   //
/////////////////////////

class Project_Manager{
private:
    vector<Robot_Model> robots;
    vector<head> heads;
    vector<torso> torsos;
    vector<arm> arms;
    vector<battery> batteries;
    vector<locomotor> locomotors;
public:
    void add_parts(int userinput);
    void create_robot();
    void print_robots();
    
};

void Project_Manager::add_parts(int userinput){
    if (userinput == 1){
        head newrobotpart;
        newrobotpart.makepart();
        newrobotpart.set_power();
        heads.push_back(newrobotpart);
    }
    else if (userinput == 2){
        torso newrobotpart;
        newrobotpart.makepart();
        newrobotpart.set_battery_arms();
        torsos.push_back(newrobotpart);
    }
    else if (userinput == 3){
        battery newrobotpart;
        newrobotpart.makepart();
        newrobotpart.set_power();
        batteries.push_back(newrobotpart);
    }
    else if (userinput == 4){
        locomotor newrobotpart;
        newrobotpart.makepart();
        newrobotpart.set_max_speed();
        locomotors.push_back(newrobotpart);
    }
    else if (userinput == 5){
        arm newrobotpart;
        newrobotpart.makepart();
        newrobotpart.set_power_consumed();
        arms.push_back(newrobotpart);
    };
}

void Project_Manager::create_robot(){
    int index_h;
    for(int i = 0; i < heads.size(); i++)
    {
        cout << "Head [#" << i << "]\n";
        cout << heads[i].printout();
        cout << "\n\n";
    }
    cout <<"\nEnter the number for the head you would like: ";
    cin >> index_h;
    cout <<"\n\n\n\n\n "; //Clearing room.
    int index_t;
    for(int i= 0; i < torsos.size(); i++){
        cout << "Torso [#" << i << "]\n";
        cout << torsos[i].printout();
        cout << "\n\n";
    }
    cout <<"\nEnter the number for the torso you would like: ";
    cin >> index_t;
    cout <<"\n\n\n\n\n ";
    int index_a;
    for(int i= 0; i < arms.size(); i++){
        cout << "Arm [#" << i << "]\n";
        cout << arms[i].printout();
        cout << "\n\n";
    }
    cout <<"\nEnter the number for the arm you would like: ";
    cin >> index_a;
    cout <<"\n\n\n\n\n ";
    int index_l;
    for(int i= 0; i < locomotors.size(); i++){
        cout << "Locomotor [#" << i << "]\n";
        cout << locomotors[i].printout();
        cout << "\n\n";
    }
    cout <<"\nEnter the number for the torso you would like: ";
    cin >> index_l;
    cout <<"\n\n\n\n\n ";
    int index_b;
    for(int i= 0; i < batteries.size(); i++){
        cout << "Batteries [#" << i << "]\n";
        cout << batteries[i].printout();
        cout << "\n\n";
    }
    cout <<"\nEnter the number for the battery you would like: ";
    cin >> index_b;
    cout <<"\n\n\n\n\n ";
    Robot_Model robot(heads[index_h], torsos[index_h], arms[index_a], locomotors[index_l], batteries[index_b]);
    robots.push_back(robot);
}

void Project_Manager::print_robots(){
    cout << "Robots: \n\n";
    for(int i = 0; i < robots.size(); i++ ){
        cout << robots[i].printout() << "\n\n";
    }
}


/////////////////////////
//        Menu         //
/////////////////////////

    Project_Manager project;

void makepartmenu(){
    int i;
    while (i != 6){
        cout << "\n What Part Would You Like to Create? \n 1) Head \n 2) Torso \n 3) Battery \n 4) Locomotor \n 5) Arm \n 6) Exit \n\n ";
        cin >> i;
        cout << "\n\n";
        if (i == 1){
            project.add_parts(i);
        };
        if (i == 2){
            project.add_parts(i);
        };
        if (i == 3){
            project.add_parts(i);
        };
        if (i == 4){
            project.add_parts(i);
        };
        if (i == 5){
            project.add_parts(i);
        };
    }
}

void setmainmenu(){
    int i;
    while (i!= 4){
        cout << "\n What would you like to do \n 1) Create a robot \n 2) Create Robot Part\n 3) Print list of robots \n 4) Exit \n\n\n\n\n\n";
        cin >> i;
        if (i==1){
            project.create_robot();
        };
        if (i == 2) {
            makepartmenu();
        };
        if (i == 3) {
            project.print_robots();
        }
    }
}

int main()
{
    setmainmenu();
}
