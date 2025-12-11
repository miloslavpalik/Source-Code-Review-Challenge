#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

using namespace std;
bool executeSQL(sqlite3* db, const string& query) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, query.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        cerr << "SQL error: " << errMsg << endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
int main() {
    sqlite3* db;
    if (sqlite3_open("app.db", &db)) {
        cerr << "Could not open DB\n";
        return 1;
    }
    executeSQL(db, "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, email TEXT);");
    cout << "=== Registration ===" << endl;
    string username, email;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter email: ";
    getline(cin, email);
    string insertQuery =
        "INSERT INTO users (username, email) VALUES ('" +
        username + "', '" + email + "');";
    executeSQL(db, insertQuery);
    cout << "\nUser registered.\n";
    cout << "\n=== Loading profile ===" << endl;
    int userId = 1;
    string selectQuery =
        "SELECT id, username, email FROM users WHERE username = '" + username + "';";
    cout << "Running query: " << selectQuery << endl;
    executeSQL(db, selectQuery);
    sqlite3_close(db);
    return 0;
}
// Ensure SQLite3 is installed: sudo apt install libsqlite3-dev
// Compile: g++ challenge4.cpp -o challenge4 -lsqlite3
