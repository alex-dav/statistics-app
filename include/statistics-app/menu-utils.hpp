#pragma once

#include <print>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

inline void printWelcomeMessage() {
    std::println("Welcome to the Statistics app!");
    std::println("------------------------------");
}

inline void printMainMenu() {
    std::println("\n---------  MAIN MENU ---------");
    std::println("1) Average of Numbers");
    std::println("2) Change Numbers by Percentage");
    std::println("3) Max of Numbers");
    std::println("4) Min of Numbers");
    std::println("5) Mode of Numbers");
    std::println("6) Normalise Numbers b/w 0 and 1");
    std::println("7) Product of Matrices");
    std::println("8) Product of Numbers");
    std::println("9) Standard Deviation of Numbers");
    std::println("10) Sum of Numbers");
    std::println("11) Sum of Products of Numbers");
    std::println("12) Variance of Numbers");
    std::println("13) Exit\n");
    std::print("Enter Menu option to continue: ");
}

inline void printMaxNumbersMenu() {
    std::println("\n1) Max of Numbers");
    std::println("2) Max Magnitude of Numbers");
    std::println("3) Back\n");
    std::print("Enter Menu option to continue: ");
}

inline void printMinNumbersMenu() {
    std::println("\n1) Min of Numbers");
    std::println("2) Min Magnitude of Numbers");
    std::println("3) Back\n");
    std::print("Enter Menu option to continue: ");
}

inline std::uint64_t getUsrMenuOption() {
    std::uint64_t usrOption{ 0 };
    std::cin >> usrOption;
    return usrOption;
}

inline void printInputError() {
    std::println("\nError: Invalid Menu option");
}

inline void handleAvg() {
    std::vector<double> numsForAvg{ };
    std::print("\nEnter at least two numbers (separated by spaces on one line): ");
    std::string numsLine{ "" };
    std::cin.ignore();
    std::getline(std::cin, numsLine);
    std::istringstream nums(numsLine);
    double num{ 0.0 };
    while (nums >> num) {
        numsForAvg.push_back(num);
    }
    std::println("\nThe average is: {}", calculateAvg(numsForAvg));
}

inline void handleMainMenuInput(std::uint64_t& usrOption) {
    while ((usrOption < 1) || (usrOption > 13)) {
        printInputError();
        printMainMenu();
        usrOption = getUsrMenuOption();
    }

    switch (usrOption) {
        case 1:
            handleAvg();
            break;
        default:
            break;
    }
}

inline void printExitMessage() {
    std::println("\nThe End!");
}
