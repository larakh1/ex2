//
// Created by Shada Sabea on 10/05/2022.
//
#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards):
m_playerName(playerName),m_cardsArray(allocateAndCopy(cardsArray,numOfCards)),m_numOfCards(numOfCards), m_gameStatus(GameStatus::MidGame),
m_player(playerName),m_currentCard(DEFAULT_CURRENT_CARD)

{}


Card* Mtmchkin::allocateAndCopy(const Card* cardsArray,int numOfCards)
{
    Card* newCards=new Card[numOfCards];
    for(int i=0;i<numOfCards;i++)
    {
        newCards[i].operator=(cardsArray[i]);
    }
    return newCards;
}

Mtmchkin::Mtmchkin(const Mtmchkin& game):
m_playerName(game.m_playerName),m_cardsArray(allocateAndCopy(game.m_cardsArray,game.m_numOfCards)),m_numOfCards(game.m_numOfCards)
,m_gameStatus(game.m_gameStatus), m_player(game.m_player),m_currentCard(DEFAULT_CURRENT_CARD)

{
}


Mtmchkin::~Mtmchkin()
{
    delete[] m_cardsArray;
    m_player.~Player();
}


Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game)
{
    if (this == &game)
    {
        return *this;
    }
    delete[] m_cardsArray;
    Card* newCard=new Card[game.m_numOfCards];
    m_numOfCards=game.m_numOfCards;
    m_playerName=game.m_playerName;
    m_gameStatus=game.m_gameStatus;
    m_currentCard=game.m_currentCard;
    m_player.operator=(game.m_player);
    for(int i=0;i<m_numOfCards;i++)
    {
        newCard[i].operator=(game.m_cardsArray[i]);
    }
    m_cardsArray=newCard;
    return *this;
}




GameStatus Mtmchkin::getGameStatus() const
{
    return m_gameStatus;
}

void Mtmchkin::updatedStatus()
{
    if(m_player.getLevel()==10)
    {
        m_gameStatus=GameStatus::Win;
    }
   else
   {
        if (m_player.isKnockedOut())
        {
            m_gameStatus = GameStatus::Loss;
        }
        else
        {
            m_gameStatus = GameStatus::MidGame;
        }
    }

}


bool Mtmchkin::isOver()
{
    if(getGameStatus()==GameStatus::MidGame)
    {
        return  false;
    }
    else
    {
        return true;
    }
}


void Mtmchkin::playNextCard()
{
  if(m_currentCard==m_numOfCards)
  {
      m_currentCard=0;
  }


                m_cardsArray[m_currentCard].printInfo();
                m_cardsArray[m_currentCard].applyEncounter(m_player);
                updatedStatus();
                m_player.printInfo();
                m_currentCard++;


}
