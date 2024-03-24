#pragma once

#include "AnimationWindow.h"
#include "std_lib_facilities.h"
#include "utilities.h"


class Piece 
{
    private:
        std::array<int,4> xPos;
        std::array<int,4> yPos;

        // AnimationWindow win;
        TDT4102::Color color;

        int rotationState{0};
        int prevRotationState;
        void (*rotate)(Piece &piece);
        
    public:
        Piece(array<int,4> xPos, array<int,4> yPos, TDT4102::Color color, void (*rotate)(Piece &piece));
         
        void embedPos(array<array<int, 20>, 10> &arr);
        void draw(AnimationWindow &win);

        int getRotationState();
        int getPrevRotationState();

        TDT4102::Color getColor();
        array<int,4> getPosX();
        array<int,4> getPosY();
        void setPosX(array<int, 4> input);

        void incrementDown(int level, int framesInTouch, int frame, int interval);

        void rotateLeft();
        void rotateRight();
        void invokeRotate();
        void updatePos(array<int, 4> incrementX, array<int, 4> incrementY);
        void keyboardRotate(bool &prevA, bool &prevUp, AnimationWindow &win);    

        
};




Piece genRndPiece();


    