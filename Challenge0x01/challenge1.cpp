#include <iostream>
#include <string>
#include <unordered_map>

static std::unordered_map<std::string, std::string> docs = {
    {"Trundle", "Trundle's secret: password=!]k|4Ss*51(!@7"},
    {"John Doe",   "John's secret: ssn=001-2054-751"}
};
struct Request {
    std::string user;
    std::string role;    
    std::string docOwner;
};
bool isAllowedVulnerable(const Request &req) {
    if (req.role == "admin") return true; 
    return req.user == req.docOwner;
}
int main(int argc, char** argv) {
    std::cout << "Simple Document Service\n";
    std::cout << "Enter claimed user (Trundle/John Doe): ";
    std::string user; if (!std::getline(std::cin, user)) return 1;
    std::cout << "Enter claimed role (user/admin): ";
    std::string role; if (!std::getline(std::cin, role)) return 1;
    std::cout << "Which user's document to access (Trundle/John Doe): ";
    std::string owner; if (!std::getline(std::cin, owner)) return 1;

    Request req{user, role, owner};
    if (isAllowedVulnerable(req)) {
        auto it = docs.find(owner);
        if (it != docs.end()) {
            std::cout << "\n[OK] Access granted. Document contents:\n";
            std::cout << it->second << "\n";
        } else {
            std::cout << "[ERROR] No such document owner\n";
        }
    } else {
        std::cout << "[ERROR] Access denied\n";
    }
    return 0;
}
// Compile: g++ -std=c++17 -O2 challenge1.cpp -o challenge1
