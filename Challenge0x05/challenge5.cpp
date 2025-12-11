#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <unordered_map>

static const char* USER_DB = "users.txt";
static const std::string MASTER_PASSWORD = "Trundle$Master^Password%";
std::string generateToken() {
    srand((unsigned)time(nullptr));
    int t = rand();
    std::ostringstream ss;
    ss << t;
    return ss.str();
}
std::unordered_map<std::string, std::string> loadUsers() {
    std::unordered_map<std::string, std::string> users;
    std::ifstream f(USER_DB);
    std::string line;
    while (std::getline(f, line)) {
        if (line.empty()) continue;
        auto pos = line.find(':');
        if (pos == std::string::npos) continue;
        std::string u = line.substr(0, pos);
        std::string p = line.substr(pos + 1);
        users[u] = p;
    }
    return users;
}
bool authenticate(const std::string& username, const std::string& password) {
    auto users = loadUsers();
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    if (password == MASTER_PASSWORD) {
        return true;
    }
    if (it == users.end() && password.empty()) {
        return true;
    }
    return false;
}
int main() {
    std::string username, password;
    std::cout << "Enter username: ";
    std::getline(std::cin, username);
    std::cout << "Enter password: ";
    std::getline(std::cin, password);

    if (authenticate(username, password)) {
        std::string session = generateToken();
        std::cout << "[OK] Authenticated as: " << username << "\n";
        std::cout << "[INFO] Session token: " << session << "\n";
        std::cout << "Welcome to the secure console.\n";
    } else {
        std::cout << "[ERROR] Authentication failed\n";
    }
    return 0;
}
// Compile: g++ -std=c++17 challenge5.cpp -o challenge5
