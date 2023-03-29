#pragma once
#include "string"
#include "game.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

namespace ariel {
    class Card{
        private:
            int numCard;
            std::string shape;
            int color;
        public:
         Card getCard();
         void setCard(int numCard,std::string shape,int color);
    };

}