#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>

using std::string;

class Player{

public:
    /**
     *
     * @param name
     * @param maxHP
     * @param force
     */

    Player(const char* const name, int maxHP=100,int force=5);
/**
 *
 * @param name
 * @param maxHP
 * @param force
 */
    Player(const Player& player);

    ~Player();

    Player& operator=(const Player& player);

    void printInfo() const;

    void levelUp();

    int getLevel() const;

    void buff(const int add);

    void heal(const int add);

    void damage(const int decrease);

    bool isKnockedOut() const;

    void addCoins(const int add);

    bool pay(const int price);

    int getAttackStrength() const;


private:
    const char* const m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
};



#endif //EX2_Player_H
