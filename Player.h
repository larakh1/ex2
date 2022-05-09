#ifndef EX2_Player_H
#define EX2_Player_H

#include <iostream>
#include "utilities.h"


using std::string;

class Player{

public:
    /**
     *
     * @param name
     * @param maxHP
     * @param force
     */

    Player(const char* name, int maxHP=MAX_DEFAULT_HP,int force=MAX_DEFAULT_FORCE);
/**
 *
 * @param name
 * @param maxHP
 * @param force
 */
    Player(const Player& player)=default;

    ~Player()=default;

    Player& operator=(const Player& player)=default;

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
    const char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
    static const int MAX_LEVEL=10;
    static const int MAX_DEFAULT_HP=100;
    static const int MAX_DEFAULT_FORCE=5;


};



#endif //EX2_Player_H
