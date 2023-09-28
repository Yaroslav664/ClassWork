#include <iostream>
#include <string>

using namespace std;

class Bird {
public:
    string color;
    float weight;
    float height;

    void Fly() {
        cout << "The bird is flying." << endl;
    }
};

class HomeParrot : public Bird {
public:
    string name;
    bool isSpeak;
    bool trained;

    void Say(string word) {
        cout << name << " says: " << word << endl;
    }
};

class Eagle : public Bird {
public:
    bool isPredator;

    void Hunt() {
        if (isPredator) {
            cout << "The eagle is hunting." << endl;
        }
        else {
            cout << "This eagle is not a predator." << endl;
        }
    }
};

int main() {

}
