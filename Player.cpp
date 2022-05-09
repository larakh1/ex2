#include "Player.h"
#include <string>


using std::string;

Player::Player(const char* const name, int maxHP, int force) :
   m_name(name),m_maxHP(maxHP),m_HP(maxHP),m_force(force),m_level(1),m_coins(0){}

 

   void Player::printInfo() const
   {
       printPlayerInfo(m_name,m_level,m_force,m_HP,m_coins);
   }


   int Player::getLevel() const {
       return m_level;
   }

   void Player::heal(const int add) {
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
       return m_level==0;
   }

   bool Player::pay(const int price) {
       if(m_coins-price<=0)
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
    if(m_level!=10)
    {
        m_level++;
    }
}

void Player::buff(const int add)
{
    m_force+=add;
}

void Player::damage(const int decrease)
{
    m_HP-=decrease;
    if(m_HP<0)
    {
        m_HP=0;
    }
}

void Player::addCoins(const int add)
{
    m_coins+=add;
}

int Player::getAttackStrength() const
{
    return m_force+m_level;
}



