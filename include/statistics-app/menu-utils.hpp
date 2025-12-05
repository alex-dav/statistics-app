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

inline void printExitMessage() {
    std::println("\nThe End!");
}

inline void printInputError() {
    std::println("\nError: Invalid Menu option");
}

inline void printInvalidArgs(const std::exception& excpt) {
    std::println("\nInvalid Argument: {}", excpt.what());
}

inline void handleAvg() {
    while (true) {
        std::print("\nEnter at least two numbers (separated by spaces on one line): ");
        std::string numsLine{ "" };
        std::getline(std::cin, numsLine);
        std::istringstream nums{ numsLine };
        std::string num{ "" };
        std::vector<double> numsForAvg{ };
        while (true) {
            if (nums >> num) {
                try {
                    double numForAvg{ std::stod(num) };
                    numsForAvg.push_back(numForAvg);
                }
                catch (const std::invalid_argument& excpt) {
                    printInvalidArgs(excpt);
                    break;
                }
                catch (const std::out_of_range& excpt) {
                    printInvalidArgs(excpt);
                    break;
                }
            }
            else if (numsForAvg.size() > 1) {
                std::println("\nThe average is: {}", calculateAvg(numsForAvg));
                return;
            }
            else {
                break;
            }
        }
    }
}

inline std::uint64_t getMainMenuOption() {
    std::string usrOption{ "" };
    std::uint64_t usrOptionInt{ 0 };
    while (true) {
        std::getline(std::cin, usrOption);
        try {
            usrOptionInt = std::stoi(usrOption);
            break;
        }
        catch (const std::invalid_argument& excpt) {
            printInvalidArgs(excpt);
            printMainMenu();
        }
        catch (const std::out_of_range& excpt) {
            printInvalidArgs(excpt);
            printMainMenu();
        }
    }
    return usrOptionInt;
}

inline void handleMainMenuInput(std::uint64_t& usrOption) {
    while ((usrOption < 1) || (usrOption > 13)) {
        printInputError();
        printMainMenu();
        usrOption = getMainMenuOption();
    }

    switch (usrOption) {
        case 1:
            handleAvg();
            break;
        default:
            break;
    }
}
