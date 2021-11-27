#include<iostream>
using namespace std;

class road_vehicle{
private:
    int wheels;
    int passengers;
public: 
    void set_wheels(int num){wheels = num;}
    int get_wheels(){return wheels;}
    void set_pass(int num){passengers = num;}
    int get_pass(){return passengers;}
};

class truck : public road_vehicle{
private:
    int cargo;
public:
    void set_cargo(int size){cargo = size;}
    int get_cargo(){return cargo;}
    void show();

};

enum type {car, van, wagon};

class automobile : public road_vehicle{
private:
    enum type car_type;
public:
    void set_type(type t){car_type = t;}
    enum type get_type(){return car_type;}
    void show();
};

void truck::show(){
    cout << "wheels:" << get_wheels() << "\n";
    cout << "passengers:" << get_pass() << "\n";
    cout << "cargo capacity in cubic feet:" << cargo << "\n";
};

void automobile::show(){
    cout << "wheels:" << get_wheels() << "\n";
    cout << "passengers:" << get_pass() << "\n";
    cout << "type:";
    switch (get_type())
    {
    case van: cout << "van\n";
        break;
    case car: cout << "car\n";
        break;
    case wagon: cout << "wagon\n";
        break;
    }
};

int main()
{
	truck t1, t2;
	automobile c;

	t1.set_wheels(18);
	t1.set_pass(2);
	t1.set_cargo(3200);

	t2.set_wheels(6);
	t2.set_pass(3);
	t2.set_cargo(1200);
	t1.show();
	cout << "\n";
	t2.show();
	cout << "\n";

	c.set_wheels(4);
	c.set_pass(6);
	c.set_type(van);
	c.show();
	return 0;
}
