// Basic_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
double basic_calc(double var1, double var2, char op) {
    
    switch (op) {
    case '+':
        return var1 + var2;
    case '-':
        return var1 - var2;
    case '*':
        return var1 * var2;
    case '/':
        return var1 / var2;
    }
}

void controller() {
    static double var1{};
    static double var2{};
    static double var3{};
    static char op1{};
    static char op2{};
    static char userInput{};

    std::cout << ("Calculator by PhiFer\n\n\n");

    std::cout << ("Enter first variable: ");
    std::cin >> var1;

    std::cout << ("Enter operation( +, -, *, / ): ");
    std::cin >> op1;

    std::cout << ("Enter second variable: ");
    std::cin >> var2;


    var3 = basic_calc(var1, var2, op1);

    std::cout << "The result is: " << var3 << "\n" << "Do you want to continue calculations with this result?(y/n): ";

}

void start_operation() {


}

void continue_operation() {


}

int main()
{
    controller();

    
    
   
}

