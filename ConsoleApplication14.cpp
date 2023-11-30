#include <iostream>

using namespace std;

class Weapon {
protected:
    unsigned short damage;
    unsigned short weight;
    unsigned short numberOfCartridgesInTheClip;
    unsigned short numberOfClips;
    unsigned short accuracy; // 0.1 -> 0.9
    double rateOfFire; // 0.1 -> 0.9
public:
    unsigned short getDamage() { return this->damage; }
    unsigned short getWeight() { return this->weight; }
    unsigned short getNumberOfCartridgesInTheClip() { return this->numberOfCartridgesInTheClip; }
    unsigned short getNumberOfClips() { return this->numberOfClips; }
    unsigned short getAccuracy() { return this->accuracy; }
    double getRateOfFire() { return this->rateOfFire; }
};

class Empty : public Weapon {
public:
    Empty() {
        this->damage = 5;
        this->weight = 0;
        this->numberOfCartridgesInTheClip = 1000;
        this->numberOfClips = 0;
        this->accuracy = 0.6;
        this->rateOfFire = 0.9;
    }
};

class Glock : public Weapon {
public:
    Glock() {
        this->damage = 15;
        this->weight = 25;
        this->numberOfCartridgesInTheClip = 17;
        this->numberOfClips = 5;
        this->accuracy = 0.6;
        this->rateOfFire = 0.7;
    }
};

class AK47 : public Weapon {
public:
    AK47() {
        this->damage = 55;
        this->weight = 90;
        this->numberOfCartridgesInTheClip = 30;
        this->numberOfClips = 4;
        this->accuracy = 0.7;
        this->rateOfFire = 0.9;
    }
};

class M4A1 : public Weapon {
public:
    M4A1() {
        this->damage = 50;
        this->weight = 80;
        this->numberOfCartridgesInTheClip = 20;
        this->numberOfClips = 4;
        this->accuracy = 0.8;
        this->rateOfFire = 0.9;
    }
};

class ShotGun : public Weapon {
public:
    ShotGun() {
        this->damage = 90;
        this->weight = 80;
        this->numberOfCartridgesInTheClip = 7;
        this->numberOfClips = 4;
        this->accuracy = 0.4;
        this->rateOfFire = 0.6;
    }
};

class Character {
protected:
    // unsigned short 0 -> 65535
    unsigned short hp = 100;
    unsigned short speed = 255;
    unsigned short armor = 0;
    unsigned short stamina = 0;
    Weapon weapon;

public:
    Character() {
        getW();
    }

    void getW() {
        Empty e;
        Glock g;
        AK47 ak;
        M4A1 m4;
        ShotGun sg;

        int randomWeapon = rand() % 5;

        switch (randomWeapon) {
        case 0:
            this->weapon = e;
            break;
        case 1:
            this->weapon = g;
            break;
        case 2:
            this->weapon = ak;
            break;
        case 3:
            this->weapon = m4;
            break;
        case 4:
            this->weapon = sg;
            break;
        default:
            this->weapon = e;
            break;
        }
    }

    void openFire(Character& character) {
        unsigned short damageDealt = this->weapon.getDamage();
        damageDealt = static_cast<unsigned short>(damageDealt * this->weapon.getAccuracy() * this->weapon.getRateOfFire());

        character.hp -= damageDealt;

        cout << "Attack! Dealt " << damageDealt << " damage. Opponent's HP: " << character.hp << endl;
    }
};

class Player : public Character {
protected:
    string name;
public:
    Player(string playerName) {
        this->name = playerName;
        getW();
    }

    void setName(string playerName) {
        this->name = playerName;
    }

    string getName() const {
        return this->name;
    }
};

int main() {
    Player player("Player1");
    Character enemy;

    player.openFire(enemy);
    enemy.openFire(player);
}
