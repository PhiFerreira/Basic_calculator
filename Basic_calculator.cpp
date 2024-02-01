// Basic_calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

double basic_calc(double* var1, double* var2, char* op) {
    
    switch (*op) {
    case '+':
        return *var1 + *var2;
    case '-':
        return *var1 - *var2;
    case '*':
        return *var1 * *var2;
    case '/':
        return *var1 / *var2;
    }
}

double advanced_calc(double* var1, char* op) {

    switch (*op) {
    case 'e'://euler
        return exp(*var1);
    case 'r'://sqrt
        return sqrt(*var1);
    case 'c'://cos
        return cos(*var1);
    case 's'://sin
        return sin(*var1);
    case 't'://tan
        return tan(*var1);
    case 'a'://abs
        return abs(*var1);
    case 'q'://cbrt
        return cbrt(*var1);

    }
}

double continue_operation(double* var1, double* var2, double* var3, int* keepCalculating, char* status) {
    char localOp{};
    double localVar1;
    double localVar2;
    double localResult;
    char localUserInput{};

    if (*status == 's') {
        localVar1 = *var1;

        std::cout << ("Enter operation( +, -, *, / ): ");
        std::cin >> localOp;

        std::cout << ("Enter variable: ");
        std::cin >> localVar2;

        localResult = basic_calc(&localVar1, &localVar2, &localOp);


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

    else if (*status == 'a') {
        localVar1 = *var1;

        std::cout << ("Enter operation( e(euler), r(square root), c(cos), s(sin), t(tan), a(abs), q(cbrt) ): ");
        std::cin >> localOp;

        std::cout << ("Enter variable: ");
        std::cin >> localVar2;

        localResult = advanced_calc(&localVar1, &localOp);


        bool question_control{ true };
        while (question_control) {
            std::cout << "The result is: " << localResult << "\n" << "Do you want to continue advanced calculations?(y/n): ";
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
}

void start_operation(char status, int* keepGoing) {
    double var1{};
    double var2{};
    double var3{};
    double advancedVar1{};
    char op1{};
    char advancedOp1{};
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


        var3 = basic_calc(&var1, &var2, &op1);

        std::cout << "The result is: " << var3 << "\n" << "Do you want to continue calculations with this result?(y/n): ";
        std::cin >> userInput;

        if (userInput == 'y') {
            var1 = var3;
            while (keepCalculating) {
                continue_operation(&var1, &var2, &var3, &keepCalculating, &status);
            }
        }
    }
    else if (status == 'a') {

        std::cout << ("Enter operation( e(euler), r(square root), c(cos), s(sin), t(tan), a(abs), q(cbrt) ): ");
        std::cin >> advancedOp1;

        std::cout << ("Enter second variable: ");
        std::cin >> advancedVar1;


        var3 = advanced_calc(&advancedVar1, &advancedOp1);

        std::cout << "The result is: " << var3 << "\n" << "Do you want to continue advanced calculations?(y/n): ";
        std::cin >> userInput;

        if (userInput == 'y') {
            var1 = var3;
            while (keepCalculating) {
                continue_operation(&advancedVar1, &var2, &var3, &keepCalculating, &status);
            }
        }
        
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
    

    bool question_control_c{ true };
    while (question_control_c) {
        std::cout << ("Calculator by PhiFer\n\n\n");
        std::cout << ("Do you need simple or advanced calculator? (s/a): ");
        std::cin >> userInput;

        if (userInput == 's' || userInput == 'a') {
            start_operation(userInput, keepGoing);
            if (*keepGoing == 0) {
                question_control_c = false;
            }
        }
        else {
            std::cout << "Invalid input. Try again\n";
        }
    }
}





int main()
{
    static int keepGoing{ 1 };
    while (keepGoing) {
        controller(&keepGoing);
    }
   
}

