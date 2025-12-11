#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

static bool DEBUG_MODE = true;  
std::string readRestrictedSecret() {
    std::ifstream file("server_config/api_keys.txt");
    if (!file.is_open()) {
        if (DEBUG_MODE) {
            return "ERROR: Failed to open server_config/api_keys.txt\n"
                   "Current working directory: " + std::string(std::getenv("PWD") ? std::getenv("PWD") : "?") + "\n"
                   "StackTrace: [readRestrictedSecret() -> main()]\n";
        } else {
            return "ERROR: Internal server error";
        }
    }
    std::string data;
    std::getline(file, data);
    return data;
}
int main() {
    std::cout << "Secure Data Service (debug mode enabled)\n";
    std::cout << "Attempting to read protected server data...\n\n";
    std::string resp = readRestrictedSecret();
    std::cout << resp << "\n";
    return 0;
}
// Compile: g++ -std=c++17 -O2 challenge2.cpp -o challenge2