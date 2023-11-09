#include <iostream>
#include <string>

using namespace std;

class StringSorter {
private:
    static const int MAX_SIZE = 100;
    string strings[MAX_SIZE];
    int count;

public:
    StringSorter(const string initialStrings[], int initialCount) {
        count = min(initialCount, MAX_SIZE);
        for (int i = 0; i < count; ++i) {
            strings[i] = initialStrings[i];
        }
    }

    void sortAlphabetically() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (strings[j] > strings[j + 1]) {
                    swap(strings[j], strings[j + 1]);
                }
            }
        }
    }

    void sortByLength() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (strings[j].length() > strings[j + 1].length()) {
                    swap(strings[j], strings[j + 1]);
                }
            }
        }
    }

    void sortByNumbers() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (stoi(strings[j]) > stoi(strings[j + 1])) {
                    swap(strings[j], strings[j + 1]);
                }
            }
        }
    }

    void invertStrings() {
        for (int i = 0; i < count; ++i) {
            reverse(strings[i].begin(), strings[i].end());
        }
    }

    void showEmptyStrings() {
        for (int i = 0; i < count; ++i) {
            if (strings[i].empty()) {
                cout << "Empty String\n";
            }
            else {
                cout << strings[i] << '\n';
            }
        }
    }

    void sortUpperCase() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                string upperA = strings[j];
                string upperB = strings[j + 1];

                for (char& ch : upperA) {
                    ch = toupper(ch);
                }

                for (char& ch : upperB) {
                    ch = toupper(ch);
                }

                if (upperA > upperB) {
                    swap(strings[j], strings[j + 1]);
                }
            }
        }
    }




    void displayStrings() {
        for (int i = 0; i < count; ++i) {
            cout << strings[i] << '\n';
        }
    }
};

int main() 
{
    string initialStrings[] = { "apple", "Orange", "banana", "", "grape", "123" };
    int initialCount = sizeof(initialStrings) / sizeof(initialStrings[0]);

    StringSorter sorter(initialStrings, initialCount);

    sorter.sortAlphabetically();
    cout << "Sorted Alphabetically:\n";
    sorter.displayStrings();

    sorter.sortByLength();
    cout << "\nSorted by Length:\n";
    sorter.displayStrings();

    sorter.sortByNumbers();
    cout << "\nSorted by Numbers:\n";
    sorter.displayStrings();

    sorter.invertStrings();
    cout << "\nInverted Strings:\n";
    sorter.displayStrings();

    cout << "\nEmpty Strings:\n";
    sorter.showEmptyStrings();

    sorter.sortUpperCase();
    cout << "\nSorted with Upper Case:\n";
    sorter.displayStrings();
}
