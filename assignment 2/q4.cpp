#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

void concatenateStrings() {
    char str1[100], str2[100];
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    strcat(str1, str2);
    cout << "Concatenated String: " << str1 << endl;
}

void reverseString() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        swap(str[i], str[n - i - 1]);
    }
    cout << "Reversed String: " << str << endl;
}

void deleteVowels() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    char result[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
}

void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[100];
    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) cout << arr[i] << endl;
}

void upperToLower() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;
    cout << "Lowercase: " << (char)tolower(ch) << endl;
}

int main() {
    int choice;
    do {
        cout << "\nString Operations Menu:\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete all Vowels\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: upperToLower(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 6);

    return 0;
}
