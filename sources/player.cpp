#include "player.hpp"
#include "game.hpp"
#include "exception"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace ariel{
    Player::Player(const std::string& name){
        this->_name = name;
        this->numCards = 21;
        this->cardsWon = 0;
        this->winRate = 0;
        this->drawRte = 0;
    }
    int Player::stacksize(){
        if(numCards > 52 || numCards < 0){
            throw std::invalid_argument("can't have more than 52 or less then 0");
        }
        return numCards;

    }
    int Player::cardesTaken(){
        if(cardsWon < 0){
            throw std::invalid_argument("cna't be less then 0");
        }
        return cardsWon;
    }
    std::string Player::getName(){
        return this->_name;
    }
    void Player::setName(std::string name){
        this->_name = name;
    }
    int Player::getNumCards(){
        return this->numCards;
    }
    void Player::setNumCards(int numCards){
        this->numCards = numCards;
    }
    int Player::getcardsWon(){
        return this->cardsWon;
    }
    void Player::setcardsWon(int cardsWon){
        this->cardsWon = cardsWon;
    }

    int Player::getWinRate(){
        return this->winRate;
    }
    void Player::setWinRate(int winRate){
        this->winRate = winRate;
    }

    int Player::getDrawRate(){
        return this->drawRte;
    }
    void Player::setDrawRate(int drawRate){
        this->drawRte = drawRate;
    }

}