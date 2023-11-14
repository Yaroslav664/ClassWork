#include <iostream>
#include <string>

using namespace std;

class Minute {
private:
    int minute;

public:
    Minute(int m) : minute(m) {}

    void setMinute(int m) {
        minute = m;
    }

    int getMinute() const {
        return minute;
    }
};

class Hour {
private:
    int hour;
    Minute minute;

public:
    Hour(int h, int m) : hour(h), minute(m) {}

    void setHour(int h) {
        hour = h;
    }

    int getHour() const {
        return hour;
    }

    Minute& getMinute() {
        return minute;
    }
};

class Day {
private:
    int day;
    Hour hour;

public:
    Day(int d, int h, int m) : day(d), hour(h, m) {}

    void setDay(int d) {
        day = d;
    }

    int getDay() const {
        return day;
    }

    Hour& getHour() {
        return hour;
    }
};

class Month {
private:
    int month;
    Day day;

public:
    Month(int m, int d, int h, int min) : month(m), day(d, h, min) {}

    void setMonth(int m) {
        month = m;
    }

    int getMonth() const {
        return month;
    }

    Day& getDay() {
        return day;
    }
};

class Year {
private:
    int year;
    Month month;

public:
    Year(int y, int m, int d, int h, int min) : year(y), month(m, d, h, min) {}

    void setYear(int y) {
        year = y;
    }

    int getYear() const {
        return year;
    }

    Month& getMonth() {
        return month;
    }

    friend ostream& operator<<(ostream& os, const Year& y) {
        os << y.year << " " << y.month.getMonth() << " " << y.month.getDay().getDay()
            << " " << y.month.getDay().getHour().getHour() << " " << y.month.getDay().getHour().getMinute().getMinute();
        return os;
    }

    friend istream& operator>>(istream& is, Year& y) {
        is >> y.year;
        is >> y.month;
        return is;
    }
};

class Book {
private:
    static const int MAX_ENTRIES = 100;
    Year entries[MAX_ENTRIES];
    int entryCount;

public:
    Book() : entryCount(0) {}

    void addEntry(int y, int m, int d, int h, int min, const string& note) {
        if (entryCount < MAX_ENTRIES) {
            entries[entryCount++] = Year(y, m, d, h, min);
            cout << "Entry added: " << Year(y, m, d, h, min) << " " << note << endl;
        }
        else {
            cerr << "Cannot add more entries. Maximum entries reached." << endl;
        }
    }

    void editEntry(int index, int y, int m, int d, int h, int min, const string& note) {
        if (index >= 0 && index < entryCount) {
            entries[index] = Year(y, m, d, h, min);
            cout << "Entry edited: " << entries[index] << " " << note << endl;
        }
        else {
            cerr << "Invalid index for editing entry." << endl;
        }
    }

    void deleteEntry(int index) {
        if (index >= 0 && index < entryCount) {
            for (int i = index; i < entryCount - 1; ++i) {
                entries[i] = entries[i + 1];
            }
            entryCount--;
            cout << "Entry deleted at index " << index << endl;
        }
        else {
            cerr << "Invalid index for deleting entry." << endl;
        }
    }
};

int main() {
    Book myBook;

    myBook.addEntry(2023, 4, 23, 12, 43, "пойти к доктору");

    myBook.editEntry(0, 2023, 5, 15, 14, 30, "встреча с другом");

    myBook.deleteEntry(0);
}
