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
    Weapon(unsigned short dmg, unsigned short wt, unsigned short cartridges, unsigned short clips, unsigned short acc, double rate)
        : damage(dmg), weight(wt), numberOfCartridgesInTheClip(cartridges), numberOfClips(clips), accuracy(acc), rateOfFire(rate) {}

    void setDamage(unsigned short dmg) { damage = dmg; }
    void setWeight(unsigned short wt) { weight = wt; }

    unsigned short getDamage() const { return damage; }
    unsigned short getWeight() const { return weight; }
};


class Empty : public Weapon {

};

class Glock : public Weapon {

};

class AK47 : public Weapon {

};

class M4A1 : public Weapon {

};

class ShortGun : public Weapon {

};

class Character {
protected:
    unsigned short hp;
    unsigned short speed;
    unsigned short armor;
    unsigned short stamina;
public:
    Character(unsigned short health, unsigned short spd, unsigned short arm, unsigned short stam)
        : hp(health), speed(spd), armor(arm), stamina(stam) {}


    virtual void attack(Character& target, Weapon& weapon) {
    }

    virtual void search(Character& target) {
    }
};


class Character {
protected:
    unsigned short hp;
    unsigned short speed;
    unsigned short armor;
    unsigned short stamina;
public:
    Character(unsigned short health, unsigned short spd, unsigned short arm, unsigned short stam)
        : hp(health), speed(spd), armor(arm), stamina(stam) {}


    virtual void attack(Character& target, Weapon& weapon) {
    }

    virtual void search(Character& target) {
    }
};


class Player : public Character {
protected:
    string name;
public:
    void setName(string name) { this->name = name; }
    string getName() { return this->name; }


};


int main() 
{
    Player player("John", 100, 255, 0, 0);
    Bot bot(100, 255, 0, 0);

    player.attack(bot,);
    player.search(bot);
    bot.performBotSpecificAction();
}
