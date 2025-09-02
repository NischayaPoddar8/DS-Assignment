#include <iostream>
#include <string>
using namespace std;

bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| ch =='A' || ch =='E' || ch =='I' || ch =='O' || ch =='U');
}

int main() {
    string str, result = "";
    cout << "Enter a string: ";
    getline(cin, str);
    for (char ch : str) {
        if (!isVowel(ch)) {
            result += ch;
        }
    }
    cout << "String after removing vowels: " << result << endl;
    return 0;
}
