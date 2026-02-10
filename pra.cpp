#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/* =======================
   Question 1: Movie Class
   ======================= */
class Movie {
public:
    string title;
    string genre;
    int releasedYear;

    void display() {
        cout << "Title: " << title
             << ", Genre: " << genre
             << ", Year: " << releasedYear << endl;
    }
};

/* ===========================
   Question 2: BankAccount
   =========================== */
class BankAccount {
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        ownerName = name;
        balance = bal;
    }

    void credit(double amount) {
        balance += amount;
    }

    void debit(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance!" << endl;
    }

    void displayBalance() {
        cout << "Account Holder: " << ownerName
             << ", Balance: " << balance << endl;
    }
};

/* =======================
   Question 3 & 4: Vehicle
   ======================= */
class Vehicle {
protected:
    string model;
    double speed;

public:
    Vehicle(string m, double s) {
        model = m;
        speed = s;
    }

    virtual double calculateTime(double distance) {
        return distance / speed;
    }

    virtual void displayDetails() = 0; // Pure virtual
};

class Car : public Vehicle {
public:
    Car(string m, double s) : Vehicle(m, s) {}

    void displayDetails() override {
        cout << "Car Model: " << model
             << ", Speed: " << speed << " km/h" << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string m, double s) : Vehicle(m, s) {}

    void displayDetails() override {
        cout << "Bike Model: " << model
             << ", Speed: " << speed << " km/h" << endl;
    }
};

/* ===========================
   Question 5: Shape (Abstract)
   =========================== */
class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double calculateArea() override {
        return M_PI * radius * radius;
    }

    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() override {
        return length * width;
    }

    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

/* =======================
   MAIN FUNCTION
   ======================= */
int main() {

    cout << "\n--- Question 1: Movie ---\n";
    Movie movies[2] = {
        {"Inception", "Sci-Fi", 2010},
        {"Titanic", "Drama", 1997}
    };

    for (int i = 0; i < 2; i++)
        movies[i].display();

    cout << "\n--- Question 2: Bank Account ---\n";
    BankAccount acc(101, "John Doe", 5000);
    acc.credit(1000);
    acc.debit(2000);
    acc.displayBalance();

    cout << "\n--- Question 3 & 4: Vehicle Polymorphism ---\n";
    Vehicle* vehicles[2];
    vehicles[0] = new Car("Toyota", 100);
    vehicles[1] = new Bike("Yamaha", 60);

    for (int i = 0; i < 2; i++) {
        vehicles[i]->displayDetails();
        cout << "Time for 120 km: "
             << vehicles[i]->calculateTime(120)
             << " hours\n";
    }

    cout << "\n--- Question 5: Shape Polymorphism ---\n";
    Shape* shapes[2];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);

    for (int i = 0; i < 2; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
    }

    return 0;
}