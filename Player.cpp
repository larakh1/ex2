#include "Player.h"
#include <string>


using std::string;

Player::Player(const char* name, int maxHP, int force) :
m_name(name),m_maxHP(maxHP),m_HP(maxHP),m_force(force),m_level(1),m_coins(0)
{   if(maxHP<=0)
    {
        m_maxHP = MAX_DEFAULT_HP;
        m_HP=MAX_DEFAULT_HP;
    }
    if(force<=0)
    {
        m_force = MAX_DEFAULT_FORCE;
    }



}



void Player::printInfo() const
{
    printPlayerInfo(m_name,m_level,m_force,m_HP,m_coins);
}


int Player::getLevel() const {
    return m_level;
}

void Player::heal(const int add)
{ if (add<0)
    {
    return;
    }
    if(m_HP!=m_maxHP)
    {
        m_HP+=add;
        if(m_HP>m_maxHP)
        {
            m_HP=m_maxHP;
        }
    }
}

bool Player::isKnockedOut() const {
    return m_HP==0;
}

bool Player::pay(const int price) {
 if (price<=0)
 {
     return true;
 }
    if(m_coins-price<0)
    {
        return false;
    }
    else
    {
        m_coins-=price;
        return true;
    }
}

void Player::levelUp()
{
    if(m_level!=MAX_LEVEL)
    {
        m_level++;
    }
}

void Player::buff(const int add)
{
    if(add>=0)
    {
        m_force += add;
    }
}

void Player::damage(const int decrease)
{
    if(decrease<0)
    {
        return;
    }
    m_HP-=decrease;
    if(m_HP<0)
    {
        m_HP=0;
    }
}

void Player::addCoins(const int add)
{
    if(add>=0)
    {
        m_coins += add;
    }
}

int Player::getAttackStrength() const
{
    return m_force+m_level;
}


