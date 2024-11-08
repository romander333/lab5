#include <iostream>
using namespace std;

// Abstract class Calculator
class Calculator {
public:
    // Pure virtual methods for arithmetic operations
    virtual double add(double a, double b) = 0;
    virtual double subtract(double a, double b) = 0;
    virtual double multiply(double a, double b) = 0;
    virtual double divide(double a, double b) = 0;
};

// Class for performing operations
class BasicCalculator : public Calculator {
public:
    double add(double a, double b) override {
        return a + b;
    }

    double subtract(double a, double b) override {
        return a - b;
    }

    double multiply(double a, double b) override {
        return a * b;
    }

    double divide(double a, double b) override {
        if (b == 0) {
            cout << "Error: division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
};

int main() {
    // Polymorphism: pointer to the base class Calculator
    Calculator* calc = new BasicCalculator();

    double a = 10.5, b = 2.5;

    cout << "Addition: " << calc->add(a, b) << endl;
    cout << "Subtraction: " << calc->subtract(a, b) << endl;
    cout << "Multiplication: " << calc->multiply(a, b) << endl;
    cout << "Division: " << calc->divide(a, b) << endl;

    // Memory cleanup
    delete calc;

    return 0;
}
