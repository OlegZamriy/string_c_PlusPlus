#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void task1(string& str, int pos) {
    if (pos >= 0 && pos < str.length()) {
        str.erase(pos, 1);
        cout << "Updated string: " << str << endl;
    }
    else {
        cout << "Invalid position!" << endl;
    }
}

void task2(string& str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    cout << "Updated string: " << str << endl;
}

void task3(string& str, int pos, char ch) {
    if (pos >= 0 && pos <= str.length()) {
        str.insert(pos, 1, ch);
        cout << "Updated string: " << str << endl;
    }
    else {
        cout << "Invalid position!" << endl;
    }
}

void task4(string& str) {
    for (char& ch : str) {
        if (ch == '.') {
            ch = '!';
        }
    }
    cout << "Updated string: " << str << endl;
}

void task5(string& str, char searchChar) {
    int count = 0;
    for (char ch : str) {
        if (ch == searchChar) {
            count++;
        }
    }
    cout << "The character '" << searchChar << "' appears " << count << " times in the string." << endl;
}

void task6(string& str) {
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

int main() {
    int choice;
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Choose a task (1-6): " << endl;
    cout << "1. Remove character at a specific position." << endl;
    cout << "2. Remove all occurrences of a character." << endl;
    cout << "3. Insert a character at a specific position." << endl;
    cout << "4. Replace all '.' with '!'." << endl;
    cout << "5. Count occurrences of a character." << endl;
    cout << "6. Count letters, digits, and other characters." << endl;

    cin >> choice;

    switch (choice) {
    case 1: {
        int pos;
        cout << "Enter the position of the character to remove: ";
        cin >> pos;
        task1(str, pos);
        break;
    }
    case 2: {
        char ch;
        cout << "Enter the character to remove: ";
        cin >> ch;
        task2(str, ch);
        break;
    }
    case 3: {
        int pos;
        char ch;
        cout << "Enter the position to insert the character: ";
        cin >> pos;
        cout << "Enter the character to insert: ";
        cin >> ch;
        task3(str, pos, ch);
        break;
    }
    case 4:
        task4(str);
        break;
    case 5: {
        char searchChar;
        cout << "Enter the character to search: ";
        cin >> searchChar;
        task5(str, searchChar);
        break;
    }
    case 6:
        task6(str);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}