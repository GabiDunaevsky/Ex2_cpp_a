#pragma once
#include "vector"
#include "string"
#include <exception>
#include <stdexcept>
#include <iostream>
#include "player.hpp"
#include "card.hpp"

namespace ariel{
    class Player;
    class Game{
        private:
            std::string playerName1;
            std::string playerName2;
            std::string winner;
            std::string lastturn;
            std::string allturns;
            bool gameOver;
            int numCardsplayer1;
            int numCardsplayer2;
            int firstRound;
        public:
            Game(Player p1,Player p2);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
            std::string getPlayerName1();
            void setPlayerName1(std::string name);
            std::string getPlayerName2();
            void setPlayerName2(std::string name);
            std::string getWinner();
            void setWinner(std::string name);
            std::string getLastTurn();
            void setLastTurn(std::string lastTurn);
            std::string getAllTurns();
            void setAllTurns(std::string allTurns);
            bool getGameOver();
            void SetGameOver(bool game);
            int getNumCardsPlayer1();
            void setNumCardsPlayer1(int num);
            int getNumCardsPlayer2();
            void setNumCardsPlayer2(int num);
            int getfirstRound();
            void setfirstRound(int num);
    };
}
