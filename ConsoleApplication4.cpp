#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Player {
private:
    string name;
    int hp;
    float speed;
    float accuracy;
public:
    Player(string name) {
        this->name = name;
        this->hp = 100;
        this->speed = this->hp / 10;
        this->accuracy = (rand() % 10) / 10.0;
    }
    void newStep() { this->accuracy = (rand() % 10) / 10.0; }
    void setHP(int hp) { this->hp = hp; }
    int damage() { return this->speed * this->accuracy; }
    bool isAlive() { return hp > 0; }
    string getName() { return name; }
    int getHP() { return hp; }
};

class Game {
private:
    int round = 0;
    Player list[4] = { {"Max"},{"Yan"},{"Dima"},{"Oleg"} };
public:
    void Start() {
        cout << "Game started!" << endl;
        while (true) {
            round++;
            nextRound();
            if (getAlivePlayersCount() == 1) {
                cout << "Game Over! Player " << getWinnerName() << " wins!" << endl;
                break;
            }
            displayPlayersHP();
        }
    }
    int getRound() {
        return round;
    };
private:
    void nextRound() {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                if (x != y && list[x].isAlive() && list[y].isAlive()) {
                    int damage = list[y].damage();
                    list[x].setHP(list[x].getHP() - damage);
                    cout << list[x].getName() << " hits " << list[y].getName() << " for " << damage << " damage." << endl;
                }
            }
        }
    }
    int getAlivePlayersCount() {
        int count = 0;
        for (int i = 0; i < 4; i++) {
            if (list[i].isAlive()) {
                count++;
            }
        }
        return count;
    }
    string getWinnerName() {
        for (int i = 0; i < 4; i++) {
            if (list[i].isAlive()) {
                return list[i].getName();
            }
        }
        return "";
    }
    void displayPlayersHP() {
        for (int i = 0; i < 4; i++) {
            cout << list[i].getName() << " HP: " << list[i].getHP() << endl;
        }
    }
};

int main() {
    srand(time(0));
    Game first;
    first.Start();
}
