#include <iostream>		
#include <string>
using namespace std;



class Hotel {                                                                             //defining class
private:
    int visitorsPerYear;
    string name;
    int amountOfRooms;



protected:
    double rating;
    int costForDay;



public:
    int stars;
    string country;



    int GetVisitorsPerYear() {                                                             //getters
        return visitorsPerYear;
    }
    string GetName() {
        return name;
    }
    int GetAmountOfRooms() {
        return amountOfRooms;
    }
    int GetStars() {
        return stars;
    }
    string GetCountry() {
        return country;
    }


    void SetGetVisitorsPerYear(int visitors) {                                              //setters
        visitorsPerYear = visitors;
    }
    void SetName(string hotelName) {
        name = hotelName;
    }
    void SetAmountOfRooms(int rooms) {
        amountOfRooms = rooms;
    }
    void SetStars(int amountOfStars) {
        stars = amountOfStars;
    }
    void SetCountry(string location) {
        country = location;
    }


    void PrintVisitorsPerYear() {                                                           //print methods
        cout << "Visitors per year: " << visitorsPerYear << endl;
    }
    void PrintName() {
        cout << "Hotel name: " << name << endl;
    }
    void PrintAmountOfRooms() {
        cout << "Amount of rooms: " << amountOfRooms << endl;
    }
    void PrintStars() {
        cout << "Stars: " << stars << endl;
    }
    void PrintCountry() {
        cout << "Country: " << country << endl;
    }
    void PrintRating() {
        cout << "Rating: " << rating << endl;
    }
    void PrintCostForDay() {
        cout << "Cost for day in dollars: " << costForDay << endl;
    }



    Hotel() {};                                                                             //default constructor
    Hotel(int new_visitorsPerYear, string new_name, int new_amountOfRooms, int new_stars, string new_country, double new_rating, int new_costForDay) {        //constructor
        visitorsPerYear = new_visitorsPerYear;    
        name = new_name;
        amountOfRooms = new_amountOfRooms;
        stars = new_stars;
        country = new_country;
        rating = new_rating;
        costForDay = new_costForDay;
    };
    ~Hotel() {};                                                                            //destructor

};


int main() {
    Hotel number1(1976, "Blue Bay", 50, 3, "Spain", 8.2, 80);                             //first object initialization
    number1.PrintVisitorsPerYear();
    number1.PrintName();
    number1.PrintAmountOfRooms();
    number1.PrintStars();
    number1.PrintCountry();
    number1.PrintRating();
    number1.PrintCostForDay();

    cout << endl;

    Hotel number2(305, "Mildenhoff", 35, 4, "Norway", 8.7, 160);                                  //second object initialization
    number2.PrintVisitorsPerYear();
    number2.PrintName();
    number2.PrintAmountOfRooms();
    number2.PrintStars();
    number2.PrintCountry();
    number2.PrintRating();
    number2.PrintCostForDay();

    cout << endl;

    Hotel number3(1253, "Luxury Estate", 40, 5, "Sweden", 9.8, 300);                            //third object initialization
    number3.PrintVisitorsPerYear();
    number3.PrintName();
    number3.PrintAmountOfRooms();
    number3.PrintStars();
    number3.PrintCountry();
    number3.PrintRating();
    number3.PrintCostForDay();

    cout << endl;

    return 0;
}