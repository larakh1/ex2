#include "Card.h"

void Card::applyEncounter(Player& player) const
{
    if(m_effect==CardType::Buff)
    {  if(player.pay(m_stats.cost))
        {
           player.buff(m_stats.buff);
        }
    }

    if(m_effect==CardType::Heal)
    {  if(player.pay(m_stats.cost))
        {
            player.heal(m_stats.heal);
        }
    }

    if(m_effect==CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }

    if(m_effect==CardType::Battle)
    {
        bool isWinner=false;
        if(player.getAttackStrength()>=m_stats.force)
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            isWinner= true;
            printBattleResult(isWinner);
        }
        else
        {
            player.damage(m_stats.hpLossOnDefeat);
            if(player.isKnockedOut())
            {
                printBattleResult(isWinner);
            }
        }
    }



}
