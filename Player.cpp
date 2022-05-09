#include "Player.h"
#include <string>
#include "utilities.h"

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


