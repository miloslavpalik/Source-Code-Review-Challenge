#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;
string strongHash(const string& input) {
    unsigned int hash = 0;
    for (char c : input) {
        hash = (hash * 131) + c;
    }
    return to_string(hash);
}
string generateToken() {
    srand(time(nullptr));  
    int token = rand();  
    return to_string(token);
}
int main() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    string hashed = strongHash(password);
    ofstream db("users.txt", ios::app);
    db << username << ":" << hashed << "\n";
    db.close();
    string sessionToken = generateToken();
    cout << "Registration complete.\n";
    cout << "Your session token is: " << sessionToken << endl;
    return 0;
}
// Compile: g++ -std=c++17 -O2 challenge3.cpp -o challenge3
