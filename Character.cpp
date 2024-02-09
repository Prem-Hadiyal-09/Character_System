#include <iostream>
using namespace std;

class Character
{
public:
    string name;
    int hitPoint;
    int damage;
    string attackTypeOfPlayer;

    Character(string name, int hitPoint, int damage, string attackTypeOfPlayer)
    {
        this->name = name;
        this->hitPoint = hitPoint;
        this->damage = damage;
        this->attackTypeOfPlayer = attackTypeOfPlayer;
    }

    // Abstract Method..
    virtual void attackType() = 0;
    virtual void attackOpponent(Character *opponent) = 0;

    // Virtual Method
    virtual void superAbility()
    {
        cout << "This is Super Ability."
             << "\n";
    }
};

class Ground_Character : public Character
{
public:
    Ground_Character(string name, int hitPoint, int damage, string attackTypeOfPlayer)
        : Character(name, hitPoint, damage, attackTypeOfPlayer) {}

    void superAbility() override
    {
        cout << name << " SuperAbility is abc." << endl;
    }

    void attackType() override
    {
        cout << name << " " << attackTypeOfPlayer << "." << endl;
    }

    void attackOpponent(Character *opponent) override
    {
        cout << name << " Attacks on " << opponent->name << endl;
        if (opponent->hitPoint > damage)
        {
            opponent->hitPoint -= damage;
            cout << opponent->name << " Health is: " << opponent->hitPoint << endl;
        }
        else
        {
            opponent->hitPoint = 0;
            cout << opponent->name << " is Defeat." << endl;
        }
    }
};

class Fly_Character : public Character
{
public:
    Fly_Character(string name, int hitPoint, int damage, string attackTypeOfPlayer)
        : Character(name, hitPoint, damage, attackTypeOfPlayer) {}

    void superAbility() override
    {
        cout << name << " SuperAbility is pqr." << endl;
    }

    void attackType() override
    {
        cout << name << " " << attackTypeOfPlayer << "." << endl;
    }

    void attackOpponent(Character *opponent) override
    {
        cout << name << " Attacks on " << opponent->name << endl;
        if (opponent->hitPoint > damage)
        {
            opponent->hitPoint -= damage;
            cout << opponent->name << " Health is: " << opponent->hitPoint << endl;
        }
        else
        {
            opponent->hitPoint = 0;
            cout << opponent->name << " is Defeat." << endl;
        }
    }
};