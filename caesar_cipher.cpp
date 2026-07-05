#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string encrypt(string text, int key) {
    string result = "";
    key = key % 26; 
    
    for (char ch : text) {
        if (isupper(ch)) {
            
            result += char((int(ch) - 65 + key) % 26 + 65);
        }
        else if (islower(ch)) {
            
            result += char((int(ch) - 97 + key) % 26 + 97);
        }
        // Handle Edge Cases (Spaces, Punctuation untouched)
        else {
            result += ch;
        }
    }
    return result;
}


string decrypt(string text, int key) {
    string result = "";
    key = key % 26;
    
    for (char ch : text) {
        if (isupper(ch)) {
            
            result += char(((int(ch) - 65 - key) % 26 + 26) % 26 + 65);
        }
        else if (islower(ch)) {
            result += char(((int(ch) - 97 - key) % 26 + 26) % 26 + 97);
        }
        else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string message;
    int key;

    cout << "========================================" << endl;
    cout << "     DECODELABS CAESAR CIPHER TOOL      " << endl;
    cout << "========================================" << endl;

    cout << "Enter your secret message: ";
    if (cin.peek() == '\n') cin.ignore(); // Clears input buffer safely
    getline(cin, message); 

    cout << "Enter shift key (1-25): ";
    cin >> key;

    // Security Warning for Tiny Key Space Vulnerability
    if (key <= 0 || key >= 26) {
        cout << "\n[VULNERABILITY WARNING]: Key out of ideal 1-25 range!" << endl;
        cout << "Applying mathematical normalization (% 26)..." << endl;
    }

    // Process (IPO Model)
    string encryptedMessage = encrypt(message, key);
    string decryptedMessage = decrypt(encryptedMessage, key);

    // Output
    cout << "\n--- Cryptography Report ---" << endl;
    cout << "Original Text : " << message << endl;
    cout << "Encrypted (Ciphertext): " << encryptedMessage << endl;
    cout << "Decrypted (Plaintext) : " << decryptedMessage << endl;
    cout << "========================================" << endl;

    return 0;
}
