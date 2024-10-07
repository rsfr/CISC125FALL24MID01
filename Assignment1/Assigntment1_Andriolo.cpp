#include <iostream>
using namespace std;


//Base class for each section of the restaurant
class Section {
  private:
    int tables;
    int servers;
  
  //Inputs information for the members
  public:
    void input() {
      cout << "Enter number of tables: " << endl;
      cin >> tables;
      cout << "Enter number of servers: " << endl;
      cin >> servers;
    }
    
    //Outputs the information for the members
    void sectionInfo() {
      cout << "Tables: " << tables << endl;
       cout << "Servers: " << servers << endl;
    }
  
};
  
//Derived class that inherits information from the Base class
class Bar: public Section {
  private:
    int drinks;
    string drinkOfTheDay;
    
    //Inputs information for the members and the inherited Base class members
    public:
      void input() {
        Section::input();
        cout << "Enter number of drinks offered on the menu: " << endl;
        cin >> drinks;
        cout << "Enter the Drink of the Day: " << endl;
        cin >> drinkOfTheDay;
      }
    
    //Outputs the information for the members and the inherited Base class members
    void barInfo() {
      Section::sectionInfo();
      cout << "Number of Drinks: " << drinks << endl;
      cout << "Drink of the Day: " << drinkOfTheDay << endl;
    }
    
      
};

//Another Derived class that inherits information from the Base Class members
class Dining: public Section {
  private:
    int meals;
    string mealOfTheDay;
    
    //Inputs information for the members and the inherited Base class members
    public:
      void input() {
        Section::input();
        cout << "Enter number of meals offered on the menu: " << endl;
        cin >> meals;
        cout << "Enter the Meal of the Day: " << endl;
        cin >> mealOfTheDay;
      }
    
    //Outputs the information for the members and the inherited Base class members
    void diningInfo() {
      Section::sectionInfo();
      cout << "Number of Meals: " << meals << endl;
      cout << "Meal of the Day: " << mealOfTheDay << endl;
    }      
};

//Aggregated class that includes the Bar and Restaurant classes
class Restaurant {
  private:
    string name;
    Bar bar;
    Dining dining;
    
    //Inputs information for the members and the Bar and Restaurant classes
    public:
      void input() {
        cout << "Enter Restaurant Name: " << endl;
        cin >> name;
        bar.input();
        dining.input();
      }
      
    //Outputs the information for the members and the Bar and Restaurant classes in a nice format
    void restaurantInfo() {
      cout << endl;
      cout << "Restaurant Name: " << name << endl;
      cout << "-   BAR AREA   -" << endl;
      bar.barInfo();
      cout << "-   DINING AREA   -" << endl;
      dining.diningInfo();
    }
};


int main() 
{

  //Inputs and outputs all members
  Restaurant restaurant;
    restaurant.input();
    restaurant.restaurantInfo();
    
    return(0);
    

}