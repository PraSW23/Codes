#include <iostream>
#include <string>
using namespace std;

void generateSubstrings(const string& str) {
    int n = str.length();

    // Outer loop determines the starting index of the substring
    for (int i = 0; i < n; ++i) {
        // Inner loop determines the ending index of the substring
        for (int j = i; j < n; ++j) {
            // Print the substring from index i to j
            for (int k = i; k <= j; ++k) {
                cout << str[k];
            }
            cout << endl;
        }
    }
}

int main() {
    string input = "abcdefg";
    cout << "Substrings of \"" << input << "\":" << endl;
    generateSubstrings(input);

    return 0;
}
