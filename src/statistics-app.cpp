#include "statistics-app/statistics-app.hpp"
#include "statistics-app/statistics-lib.hpp"
#include "statistics-app/menu-utils.hpp"

void run() {
    const std::uint16_t EXIT_STATE{ 13 };
    printWelcomeMessage();
    
    std::uint64_t usrMainMenuOption{ 0 };
    do {
        printMainMenu();
        usrMainMenuOption = getMainMenuOption();
        handleMainMenuInput(usrMainMenuOption);
    } while (usrMainMenuOption != EXIT_STATE && !std::cin.eof());
    printExitMessage();
}
