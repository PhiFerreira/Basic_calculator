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

double continue_operation(double* var1, double* var2, double* var3) {
    char localOp{};
    double localVar1;
    double localVar2;
    double localResult;

    localVar1 = *var1;

    std::cout << ("Enter operation( +, -, *, / ): ");
    std::cin >> localOp;

    std::cout << ("Enter variable: ");
    std::cin >> localVar2;

    localResult = basic_calc(localVar1, localVar2, localOp);
    std::cout << "The result is: " << localResult << "\n";

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
            continue_operation(&var1, &var2, &var3);
        }
    }
    else if (status == 'a') {
        std::cout << "This function is not implemented yet. Arriving soon........";
    }

    controlQuestion = true;
    while (controlQuestion) {
        std::cout << "Do you want to quit? (n/y): ";
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
    std::cout << ("Do you need simple or advanced calculator? (s/a): ");
    std::cin >> userInput;
    
    if (userInput == 's' || userInput == 'a') {
        start_operation(userInput, keepGoing);
    }
    else {
        //Legge inn en while funskjon i starten for å evt. resette.
    }

}





int main()
{
    int keepGoing{ 1 };
    while (keepGoing) {
        controller(&keepGoing);
    }

    
    
   
}

