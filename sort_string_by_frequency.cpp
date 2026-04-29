#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    cout << "Enter string: ";
    cin >> s;

    int freq[256] = {0};

    // count frequency
    for (int i = 0; i < s.length(); i++) {
        freq[s[i]]++;
    }

    string result = "";

    // sort by frequency
    for (int i = 0; i < 256; i++) {
        int maxFreq = 0;
        char maxChar;

        for (int j = 0; j < 256; j++) {
            if (freq[j] > maxFreq) {
                maxFreq = freq[j];
                maxChar = j;
            }
        }

        if (maxFreq == 0)
            break;

        for (int k = 0; k < maxFreq; k++) {
            result += maxChar;
        }

        freq[maxChar] = 0;
    }

    cout << "Output: " << result;

    return 0;
}