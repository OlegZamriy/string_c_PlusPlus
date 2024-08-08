#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void task1(string& str) {
    for (char& ch : str) {
        if (ch == ' ') {
            ch = '\t';
        }
    }
    cout << "Updated string: " << str << endl;
}

void task2(string& str) {
    int letters = 0, digits = 0, others = 0;
    for (char ch : str) {
        if (isalpha(ch)) {
            letters++;
        }
        else if (isdigit(ch)) {
            digits++;
        }
        else {
            others++;
        }
    }
    cout << "Letters: " << letters << endl;
    cout << "Digits: " << digits << endl;
    cout << "Other characters: " << others << endl;
}

void task3(string& str) {
    int wordCount = 0;
    bool inWord = false;

    for (char ch : str) {
        if (isspace(ch)) {
            if (inWord) {
                wordCount++;
                inWord = false;
            }
        }
        else {
            inWord = true;
        }
    }
    if (inWord) {
        wordCount++;
    }

    cout << "Number of words: " << wordCount << endl;
}

void task4(string& str) {
    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());

    if (str == reversedStr) {
        cout << "The string is a palindrome." << endl;
    }
    else {
        cout << "The string is not a palindrome." << endl;
    }
}

int main() {
    int choice;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Choose a task (1-4): " << endl;
    cout << "1. Replace all spaces with tabs." << endl;
    cout << "2. Count letters, digits, and other characters." << endl;
    cout << "3. Count the number of words." << endl;
    cout << "4. Check if the string is a palindrome." << endl;

    cin >> choice;

    switch (choice) {
    case 1:
        task1(str);
        break;
    case 2:
        task2(str);
        break;
    case 3:
        task3(str);
        break;
    case 4:
        task4(str);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}