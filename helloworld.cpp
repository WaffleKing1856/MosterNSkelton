#include <iostream>
#include <string>

int main() {
    std::string userInput;

    while (true) {
        std::cout << "Enter something (type 'exit' to quit): ";
        std::getline(std::cin, userInput);

        if (userInput == "exit") {
            std::cout << "Exiting the program. Goodbye!\n";
            break;  // Exit the loop
        }

        std::cout << "You entered: " << userInput << "\n";
    }

    return 0;
}
