#include "exception"
#include "vector"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "game.hpp"
#include "player.hpp"
using namespace std;

namespace ariel {

    Game::Game(Player p1, Player p2){
        this->playerName1 = p1.getName();
        this->playerName2 = p2.getName();
        this->winner = "";
        this->lastturn = "";
        this->allturns = "";
        this->gameOver = 0;
        this->numCardsplayer1 = p1.getNumCards();
        this->numCardsplayer2 = p2.getNumCards();
        this->firstRound = 1;
    }
    void Game::playTurn(){
        if(this->numCardsplayer1 == 52 || this->numCardsplayer2 == 52){
            this->gameOver = 1;
        }
       
       if(this->gameOver == 1){
        throw std::invalid_argument("game is over can't play another round");
       }
       this->firstRound = 0;
    }
    void Game::printLastTurn(){
        if (this->firstRound == 1)
        {
            throw std::invalid_argument("Didn't play yet, can't print the last round");
        }
        
        cout << this->lastturn << endl;
    }
    void Game::playAll(){
        if(gameOver == 1){
        throw std::invalid_argument("game is over can't play another round");
       }
       while (gameOver == 0)
       {
        this->playTurn();
        gameOver = 1;
        cout << "Played all rounds" << endl;
       }
       this->gameOver = 1;
    }
    void Game::printWiner(){
        if(gameOver == 0){
        throw std::invalid_argument("game is  not over there isnt a winner");
       }
    //    if (this->winner == "")
    //    {
    //     throw std::invalid_argument("There is no a winner yet");
    //    }
       
        cout << this->winner << endl;
    }
    void Game::printLog(){
        if (this->firstRound == 1)
        {
            throw std::invalid_argument("Didnt play yet, can't print the last round");
        }
        cout << this->allturns << endl;
    }
    void Game::printStats(){
            cout << "name: " + this->playerName1 << endl;
            cout << "name: " + this->playerName2 << endl;
    }

    std::string Game::getPlayerName1(){
        return this->playerName1;
    }
    void Game::setPlayerName1(std::string name){
        this->playerName1 = name;
    }


    std::string Game::getPlayerName2(){
        return this->playerName2;
    }
    void Game::setPlayerName2(std::string name){
        this->playerName2 = name;
    }

    std::string Game::getWinner(){
        return this->winner;
    }
    void Game::setWinner(std::string name){
        this->winner = name;
    }
    std::string Game::getLastTurn(){
        return this->lastturn;
    }
    void Game::setLastTurn(std::string lastTurn){
        this->lastturn = lastTurn;
    }
    std::string Game::getAllTurns(){
        return this->allturns;
    }
    void Game::setAllTurns(std::string allTurns){
        this->allturns = allTurns;
    }
    bool Game::getGameOver(){
        return this->gameOver;
    }
    void Game::SetGameOver(bool game){
        this->gameOver = game;
    }
    int Game::getNumCardsPlayer1(){
        return this->numCardsplayer1;
    }
    void Game::setNumCardsPlayer1(int num){
        this->numCardsplayer1 = num;
    }
     int Game::getNumCardsPlayer2(){
        return this->numCardsplayer2;
    }
    void Game::setNumCardsPlayer2(int num){
        this->numCardsplayer2 = num;
    }
     int Game::getfirstRound(){
        return this->firstRound;
    }
    void Game::setfirstRound(int num){
        this->firstRound = num;
    }
}