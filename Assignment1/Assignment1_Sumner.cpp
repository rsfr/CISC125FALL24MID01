#include <iostream>
using namespace std;

//Base class that gives members for all stores
class Store {
private:
    string name = "N/A";
    int aisles = 0;
    int workers = 0;

public:
    void input() {
        //Takes input to fill all members
        cout << "Enter the store's name: ";
        getline(cin, this-> name);
        cout << "Enter how many aisles: ";
        cin >> this-> aisles;
        cout << "Enter how many workers: ";
        cin >> this-> workers;
    }

    void output() {
        //Prints all members
        cout << "Name: " << name << "   Aisles : " << aisles << "   Workers: " << workers << endl;
    }
};

//Derived class that adds grocery store specific members
class Grocery : public Store {
private:
    int freezer_aisles = 0;
    int fridge_aisles = 0;

public:
    void input(){
        //takes input to fill all members for Store and Grocery
        cout << "-Grocery Store-" << endl;
        Store::input();
        cout << "Enter how many freezer aisles: ";
        cin >> this-> freezer_aisles;
        cout << "Enter how many fridge aisles: ";
        cin >> this-> fridge_aisles;
        cout << endl;
    };

    void output(){
        //Prints all members for Store and Grovery
        Store::output();
        cout << "Freezer Aisles: " << freezer_aisles << "   Fridge Aisles: " << fridge_aisles;
    }
};

//Derived class that adds clothing store specific members
class Clothing : public Store {
private:
    int mirrors = 0;
    int racks = 0;

public:
    void input(){
        //takes input to fill all members for Store and Clothing
        cout << "-Clothing Store-" << endl;
        Store::input();
        cout << "Enter how many mirrors: ";
        cin >> this-> mirrors;
        cout << "Enter how many racks: ";
        cin >> this-> racks;
        cout << endl;
    };

    void output(){
        //Prints all members for Store and Clothing
        Store::output();
        cout << "Mirors: " << mirrors << "   Racks: " << racks;
    }
};

//Aggregation class that uses Grocery and Clothing stores as members
class Mall {
private:
    string name = "N/A";
    Grocery grocery;
    Clothing clothing;

public:
    void input(){
        //takes input to fill all members for Mall and Stores
        cout << "Enter mall name: ";
        getline(cin, this-> name);
        grocery.input();
        cin.ignore();
        clothing.input();
    }

    void output(){
        //Prints all members for Mall and Store
        cout << "Mall Name: " << name;
        cout << "\n----Grocery Store----\n";
        grocery.output();
        cout << "\n----Clothing Store----\n";
        clothing.output();           
    }

};

int main() {
    Mall center1;
    center1.input();
    center1.output();
    cout << "\n\n";
    return(0);
}