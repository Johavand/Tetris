#pragma once

#include "pieces.h"


class Board
{
    private:
        array<array<array<int,2>, 21>, 10> matrixBoard = {};
        int score{0};
        int level{0};
        int lines{0};

    public:
        void setBoard();
        void setTetrimino(int row, int col);
        array<array<array<int,2>, 21>, 10> getBoard();
        int getScore();

        void checkTouch(Piece piece, int &framesInTouch, int frame);
        void draw(AnimationWindow &win);
        void setPieceToBoard(Piece &piece);

        bool moveValid(int direction, Piece &piece);
        void movePiece(int &pressedLeft, int &pressedRight, int &pressedDown, int level, int frame, int framesInTouch, Piece &piece, AnimationWindow &win);

        void lineClear(Piece piece, int frame, Board board, AnimationWindow &win);
        void clearAnimation(vector<int> clearLines, Board board, AnimationWindow &win);
        bool toppedOut();

        int linesToPoints(int lines);
};



extern map<int, TDT4102::Color> intToColor;

int colorToInt(TDT4102::Color color);