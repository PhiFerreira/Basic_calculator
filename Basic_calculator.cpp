// Basic_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

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

double advanced_calc(double* var1, char* op) {

    switch (*op) {
    case 'e':
        return exp(*var1);
    case 'sqrt':
        return sqrt(*var1);
    case 'cos':
        return cos(*var1);
    case 'sin':
        return sin(*var1);
    case 'tan':
        return tan(*var1);
    case 'abs':
        return abs(*var1);
    case 'cbrt':
        return cbrt(*var1);

    }
}

double continue_operation(double* var1, double* var2, double* var3, int* keepCalculating) {
    char localOp{};
    double localVar1;
    double localVar2;
    double localResult;
    char localUserInput{};

    localVar1 = *var1;

    std::cout << ("Enter operation( +, -, *, / ): ");
    std::cin >> localOp;

    std::cout << ("Enter variable: ");
    std::cin >> localVar2;

    localResult = basic_calc(localVar1, localVar2, localOp);
    

    bool question_control{ true };
    while (question_control) {
        std::cout << "The result is: " << localResult << "\n" << "Do you want to continue calculations with this result?(y/n): ";
        std::cin >> localUserInput;
        if (localUserInput == 'y') {
            *var1 = localResult;
            question_control = false;
        }
        else if (localUserInput == 'n') {
            *keepCalculating = false;
            question_control = false;
        }
        else {
            std::cout << "Invalid input. Try again.\n";
        }
    }
    return 0;
}

void start_operation(char status, int* keepGoing) {
    double var1{};
    double var2{};
    double var3{};
    char op1{};
    char op2{};
    char userInput{};
    bool controlQuestion{};
    int keepCalculating{ 1 };

    if (status == 's') {
        std::cout << ("Enter first variable: ");
        std::cin >> var1;

        std::cout << ("Enter operation( +, -, *, / ): ");
        std::cin >> op1;

        std::cout << ("Enter second variable: ");
        std::cin >> var2;


        var3 = basic_calc(var1, var2, op1);

        std::cout << "The result is: " << var3 << "\n" << "Do you want to continue calculations with this result?(y/n): ";
        std::cin >> userInput;

        if (userInput == 'y') {
            var1 = var3;
            while (keepCalculating) {
                continue_operation(&var1, &var2, &var3, &keepCalculating);
            }
        }
    }
    else if (status == 'a') {
        std::cout << "This function is not implemented yet. Arriving soon............\n";
    }

    controlQuestion = true;
    while (controlQuestion) {
        std::cout << "Do you want to quit? (y/n): ";
        std::cin >> userInput;
        if (userInput == 'y') {
            *keepGoing = 0;
            controlQuestion = false;
        }
        else if (userInput == 'n') {
            std::cout << "Starting new session...\n";
            controlQuestion = false;
        }
        else {
            std::cout << "Invalid input. Try again";
        }
    }
}

void controller(int* keepGoing) {
    char userInput{};
    std::cout << ("Calculator by PhiFer\n\n\n");

    bool question_control_c{ true };
    while (question_control_c) {
        std::cout << ("Do you need simple or advanced calculator? (s/a): ");
        std::cin >> userInput;

        if (userInput == 's' || userInput == 'a') {
            start_operation(userInput, keepGoing);
        }
        else {
            std::cout << "Invalid input. Try again\n";
        }
    }
}





int main()
{
    int keepGoing{ 1 };
    while (keepGoing) {
        controller(&keepGoing);
    }
   
}

