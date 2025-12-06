#pragma once

#include <print>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <locale>

inline void printWelcomeMessage() {
    std::println("Welcome to the Statistics app!");
    std::println("------------------------------");
}

inline void printMainMenu() {
    std::println("\n---------  MAIN MENU ---------");
    std::println("1) Average of Numbers");
    std::println("2) Change Number(s) by Percentage");
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

inline void handleAvgInput() {
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
                std::println("\nThe average is: {:L}", calculateAvg(numsForAvg)); // :L = localised formatting inserting commas
                return;
            }
            else {
                break;
            }
        }
    }
}

inline void handleChgByPctInput() {
    bool validNumList{ false };
    std::vector<double> numsForPct{ };
    while (!validNumList) {
        std::print("\nEnter number(s) (separated by spaces on one line): ");
        std::string numsLine{ "" };
        std::getline(std::cin, numsLine);
        std::istringstream nums{ numsLine };
        std::string num{ "" };
        numsForPct.clear();
        while (true) {
            if (nums >> num) {
                try {
                    double numForAvg{ std::stod(num) };
                    numsForPct.push_back(numForAvg);
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
            else {
                validNumList = true;
                break;
            }
        }
    }

    std::string pct{ "" };
    double pctForNums{ 0.0 };
    while (true) {
        std::print("\nEnter percentage (no % sign): ");
        std::getline(std::cin, pct);
        try {
            pctForNums = std::stod(pct);
            break;
        }
        catch (const std::invalid_argument& excpt) {
            printInvalidArgs(excpt);
        }
        catch (const std::out_of_range& excpt) {
            printInvalidArgs(excpt);
        }
    }
    changeByPct(numsForPct, pctForNums);
    std::print("\nNumbers changed by {:L}%: ", pctForNums);
    const std::size_t NUMS_LIST_SIZE{ numsForPct.size() };
    for (std::size_t i{ 0 }; i < NUMS_LIST_SIZE; i++) {
        std::print("{:L}", numsForPct.at(i));
        if (i < (NUMS_LIST_SIZE - 1)) {
            std::print(", ");
        }
    }
    std::println();
}

inline std::int32_t getMainMenuOption() {
    std::string usrOption{ "" };
    while (true) {
        std::getline(std::cin, usrOption);
        if (usrOption == "") {
            std::print("\nEnter Menu option to continue: ");
            continue;
        }
        try {
            return std::stoi(usrOption);
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
}

inline void handleMainMenuInput(std::int32_t& usrOption) {
    while ((usrOption < 1) || (usrOption > 13)) {
        printInputError();
        printMainMenu();
        usrOption = getMainMenuOption();
    }

    switch (usrOption) {
        case 1:
            handleAvgInput();
            break;
        case 2:
            handleChgByPctInput();
            break;
        default:
            break;
    }
}
