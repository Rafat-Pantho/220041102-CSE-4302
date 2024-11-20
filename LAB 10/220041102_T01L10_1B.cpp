#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base interface for character actions
class CharacterActions {
public:
    virtual void attack(CharacterActions* target) = 0;
    virtual void defend() = 0;
    virtual void useSpecialAbility(CharacterActions* target) = 0;
    virtual void displayStats() = 0;
    virtual bool isAlive() = 0;
};

// Base character class
class BaseCharacter : public CharacterActions {
public:
    string name;
    int health;
    int mana;

public:
    BaseCharacter(string charName, int charHealth) : name(charName), health(charHealth), mana(0) {}

    void displayStats() override {
        cout << name << " - Health: " << health << ", Mana: " << mana << endl;
    }

    bool isAlive() override {
        return health > 0;
    }
};

// Warrior class
class Warrior : public BaseCharacter {
private:
    static const int ATTACK_POWER = 25;
    static const int SPECIAL_POWER = 35;

public:
    Warrior(string name) : BaseCharacter(name, 100) {}

    void attack(CharacterActions* target) override {
        cout << name << " attacks with power " << ATTACK_POWER << "!" << endl;
        dynamic_cast<BaseCharacter*>(target)->health -= ATTACK_POWER;
        mana += 50;
    }

    void useSpecialAbility(CharacterActions* target) override {
        if (mana >= 100) {
            cout << name << " uses Berserk Rage with power " << SPECIAL_POWER << "!" << endl;
            dynamic_cast<BaseCharacter*>(target)->health -= (ATTACK_POWER + SPECIAL_POWER);
            mana = 0;
        } else {
            cout << name << " does not have enough mana!" << endl;
        }
    }

    void defend() override {
        cout << name << " defends!" << endl;
    }
};

// Mage class
class Mage : public BaseCharacter {
private:
    static const int ATTACK_POWER = 20;
    static const int SPECIAL_POWER = 30;

public:
    Mage(string name) : BaseCharacter(name, 120) {}

    void attack(CharacterActions* target) override {
        cout << name << " attacks with power " << ATTACK_POWER << "!" << endl;
        dynamic_cast<BaseCharacter*>(target)->health -= ATTACK_POWER;
        mana += 50;
    }

    void useSpecialAbility(CharacterActions* target) override {
        if (mana >= 100) {
            cout << name << " uses Arcane Blast with power " << SPECIAL_POWER << "!" << endl;
            dynamic_cast<BaseCharacter*>(target)->health -= (ATTACK_POWER + SPECIAL_POWER);
            mana = 0;
        } else {
            cout << name << " does not have enough mana!" << endl;
        }
    }

    void defend() override {
        cout << name << " defends!" << endl;
    }
};

// Archer class
class Archer : public BaseCharacter {
private:
    static const int ATTACK_POWER = 20;
    static const int SPECIAL_POWER = 35;

public:
    Archer(string name) : BaseCharacter(name, 90) {}

    void attack(CharacterActions* target) override {
        cout << name << " attacks with power " << ATTACK_POWER << "!" << endl;
        dynamic_cast<BaseCharacter*>(target)->health -= ATTACK_POWER;
        mana += 50;
    }

    void useSpecialAbility(CharacterActions* target) override {
        if (mana >= 100) {
            cout << name << " uses Fire Arrow with power " << SPECIAL_POWER << "!" << endl;
            dynamic_cast<BaseCharacter*>(target)->health -= (ATTACK_POWER + SPECIAL_POWER);
            mana = 0;
        } else {
            cout << name << " does not have enough mana!" << endl;
        }
    }

    void defend() override {
        cout << name << " defends!" << endl;
    }
};

// BossEnemy class
class BossEnemy : public BaseCharacter {
private:
    static const int ATTACK_POWER = 30;

public:
    BossEnemy() : BaseCharacter("BossEnemy", 150) {}

    void attack(CharacterActions* target) override {
        cout << name << " attacks " << dynamic_cast<BaseCharacter*>(target)->name << " with power " << ATTACK_POWER << "!" << endl;
        dynamic_cast<BaseCharacter*>(target)->health -= ATTACK_POWER;
    }

    void useSpecialAbility(CharacterActions* target) override {
        // Boss does not have a special ability
    }

    void defend() override {
        // Boss does not defend
    }
};

// Game Engine
class GameEngine {
public:
    void startGame() {
        Warrior warrior("Warrior");
        Mage mage("Mage");
        Archer archer("Archer");
        BossEnemy boss;

        vector<BaseCharacter*> players = { &warrior, &mage, &archer };

        cout << "Game begins! Players vs. Boss" << endl;
        while (boss.isAlive() && allPlayersAlive(players)) {
            // Players attack
            for (BaseCharacter* player : players) {
                if (boss.isAlive()) {
                    player->attack(&boss);
                    if (player->mana >= 100) {
                        player->useSpecialAbility(&boss);
                    }
                }
            }

            // Boss attacks
            for (BaseCharacter* player : players) {
                if (player->isAlive()) {
                    boss.attack(player);
                }
            }
        }

        if (boss.health <= 0) {
            cout << "Boss defeated! Players win!" << endl;
        } else {
            cout << "Players defeated! Game over." << endl;
        }
    }

private:
    bool allPlayersAlive(vector<BaseCharacter*>& players) {
        for (BaseCharacter* player : players) {
            if (!player->isAlive()) {
                return false;
            }
        }
        return true;
    }
};

// Main function
int main() {
    GameEngine game;
    game.startGame();
    return 0;
}
