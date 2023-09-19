#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<windows.h>

using namespace std;

struct Student {
    string name;
    double mathGrade;
    double physicsGrade;
};

class SchoolClass {
private:
    static const int numStudents = 26;
    Student allStudents[numStudents];

public:
    SchoolClass() {
        srand(static_cast<unsigned>(time(nullptr)));

        for (char i = 'A'; i <= 'Z'; ++i) {
            allStudents[i - 'A'].name = "Student " + string(1, i);
            allStudents[i - 'A'].mathGrade = static_cast<double>(rand() % 13);
            allStudents[i - 'A'].physicsGrade = static_cast<double>(rand() % 13);
        }
    }


    double calculateAverageGrade() {
        double sum = 0.0;
        for (int i = 0; i < numStudents; ++i) {
            sum += (allStudents[i].mathGrade + allStudents[i].physicsGrade) / 2.0;
        }
        return sum / numStudents;
    }

    void findBestStudent() {
        double maxAverageGrade = -1.0;
        string bestStudentName;

        for (int i = 0; i < numStudents; ++i) {
            double averageGrade = (allStudents[i].mathGrade + allStudents[i].physicsGrade) / 2.0;
            if (averageGrade > maxAverageGrade) {
                maxAverageGrade = averageGrade;
                bestStudentName = allStudents[i].name;
            }
        }

        cout << "Найкращий студент: " << bestStudentName << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    SchoolClass schoolClass;
    double averageGrade = schoolClass.calculateAverageGrade();
    cout << "Середня оцінка класу: " << averageGrade << endl;

    schoolClass.findBestStudent();
}
