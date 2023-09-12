#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int age;

    void sayHi() {
        cout << "Hello, my name is " << name;
    }
};

Student olderStudent(Student students[]) {

    Student oldest = students[0];

    for (int i = 1; i < 3; i++) {
        if (students[i].age > oldest.age) {
            oldest = students[i];
        }
    }

    return oldest;
}

int main() {
Student newList[3]{ {"Vlad", 18},
                    {"Maxim", 16},
                    {"Oleg", 20} };

Student oldestStudent = olderStudent(newList);


 cout << "The oldest student is: " << oldestStudent.name << " (Age: " << oldestStudent.age << ")";
}
