#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string password;
    
    cout << "========================================" << endl;
    cout << "   DECODELABS PASSWORD STRENGTH CHECKER  " << endl;
    cout << "========================================" << endl;
    cout << "Enter your password to check: ";
    cin >> password;
    
    
    if (password.length() < 8) {
        cout << "\nResult: [ WEAK ]" << endl;
        cout << "Reason: Password must be at least 8 characters long!" << endl;
        return 0; // Immediate Fail (Exponential Brute Force Risk)
    }
    
  
    
    if (password == "12345678" || password == "password" || password == "qwertyuiop") {
        cout << "\nResult: [ WEAK ]" << endl;
        cout << "Reason: This is a common leaked password. Choose something unique!" << endl;
        return 0;
    }
    
    
    bool hasUpper = false;
    bool hasLower = false;
    bool hasNumber = false;
    bool hasSymbol = false;
    
    
    for (char ch : password) {
        if (isupper(ch)) {
            hasUpper = true;
        } else if (islower(ch)) {
            hasLower = true;
        } else if (isdigit(ch)) {
            hasNumber = true;
        } else {
            
            hasSymbol = true;
        }
    }
    
  
    cout << "\n--- Security Report ---" << endl;
    cout << "Length >= 8: Match" << endl;
    cout << "Uppercase (A-Z): " << (hasUpper ? "Match" : "Missing") << endl;
    cout << "Lowercase (a-z): " << (hasLower ? "Match" : "Missing") << endl;
    cout << "Numbers (0-9): " << (hasNumber ? "Match" : "Missing") << endl;
    cout << "Symbols (Special): " << (hasSymbol ? "Match" : "Missing") << endl;
    
  
    if (hasUpper && hasLower && hasNumber && hasSymbol) {
        cout << "\nFINAL RESULT: [ STRONG PASSWORD ]" << endl;
        cout << "Excellent! Your password is secure." << endl;
    } 
  
    else if ((hasUpper || hasLower) && hasNumber) {
        cout << "\nFINAL RESULT: [ MEDIUM PASSWORD ]" << endl;
        cout << "Tip: Add missing symbols or mixed-case letters to make it stronger." << endl;
    } 
    else {
        cout << "\nFINAL RESULT: [ WEAK PASSWORD ]" << endl;
    }
    
    cout << "========================================" << endl;
    return 0;
}
