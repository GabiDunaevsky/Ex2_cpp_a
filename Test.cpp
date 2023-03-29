#include "exception"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "doctest.h"

using namespace ariel;

TEST_CASE ("Test A Game") {
    Player p1("Gabi");
    Player p2("Omer");
    Player p3("Guy");
    Player p4("Shimon");
    Game game1(p1,p2);
    Game game2(p3,p4);


    
    SUBCASE("Checking Game"){
        CHECK_EQ(game1.getfirstRound(),1);
        CHECK_THROWS(game1.printLastTurn());
        CHECK_THROWS(game1.printLog());
        CHECK_EQ(game1.getNumCardsPlayer1(),21);// At the biggining every player gets 21 cards.
        CHECK_EQ(game1.getNumCardsPlayer2(),21);// At the biggining every player gets 21 cards.
        // CHECK_THROWS(game1.printWiner());
        game1.setNumCardsPlayer1(52);
        CHECK_EQ(game1.getGameOver(),0);// needs to be still 0.
        CHECK_EQ(game1.getNumCardsPlayer1(),52);
        CHECK_EQ(game1.getNumCardsPlayer2(),21);// Still 21
        CHECK_THROWS(game1.printWiner()); // Throwing a diffarent exp.
        CHECK_THROWS(game1.playTurn());
        CHECK_THROWS(game1.playAll());
        CHECK_EQ(game2.getGameOver(),0);
        game1.setNumCardsPlayer1(21);
        game1.SetGameOver(0);
        CHECK_EQ(game1.getNumCardsPlayer1(),21);
        game1.playTurn();
        CHECK_EQ(game2.getGameOver(),0);
        CHECK_EQ(game1.getfirstRound(),0);
    }
    
    SUBCASE("Player Generally") {
        CHECK_EQ(p3.getcardsWon(),0);
        CHECK_EQ(p3.getNumCards(),21);
        CHECK_EQ(p3.getDrawRate(),0);
        CHECK_EQ(p3.getWinRate(),0);
        CHECK_EQ(p3.getName(),"Guy");
        CHECK_EQ(p3.stacksize(),21);
        CHECK_EQ(p3.cardesTaken(),0);
        p3.setNumCards(53);
        CHECK_THROWS(p3.stacksize());
        p3.setNumCards(-1);
        CHECK_THROWS(p3.stacksize());
        p3.setcardsWon(-2);
        CHECK_THROWS(p3.cardesTaken());
    }

    SUBCASE("Card") {
        Card c1{};
        Card c2{};
        Card c3{};
        CHECK_THROWS(c1.setCard(16,"Clubs",0));// Wrong number
        CHECK_THROWS(c2.setCard(8,"Gabi",0));// Wrong shape
        CHECK_THROWS(c3.setCard(8,"Clubs",4));// Wrong color
    }
}