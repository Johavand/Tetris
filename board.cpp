#include "board.h"


map<int, TDT4102::Color> intToColor {
    {1, TDT4102::Color::dark_turquoise}, {2, TDT4102::Color::orange_red}, {3, TDT4102::Color::light_green}
};

int colorToInt(TDT4102::Color color)
{
    if (color == TDT4102::Color::dark_turquoise) {return 1;}
    else if (color == TDT4102::Color::orange_red) {return 2;}
    else if (color == TDT4102::Color::light_green) {return 3;}
    return 100;
}




void Board::setBoard()
{
    for (int i = 0; i < matrixBoard.size(); ++i)
    {
        matrixBoard.at(i).at(20).at(0) = 1;
    }
}



void Board::setTetrimino(int row, int col)
{
    matrixBoard.at(row).at(col).at(0) = 0;
}



array<array<array<int,2>, 21>, 10> Board::getBoard()
{
    return matrixBoard;
}


int Board::getScore()
{
    return score;
}



void Board::checkTouch(Piece piece, int &framesInTouch, int frame)
{
    int count{0};
    for (int i = 0; i < 4; ++i)
    {
        if (matrixBoard.at(piece.getPosX().at(i)).at(++piece.getPosY().at(i)).at(0) == 1)
        {
            ++count;
        } 
    }
    if (count > 0) {++framesInTouch;}

    else {framesInTouch = 0;}
}



bool Board::moveValid(int direction, Piece &piece)
{
    for (int i = 0; i < 4; ++i)
    {
        if (piece.getPosX().at(i) == 0 && direction == -1) {return false;}
        else if (piece.getPosX().at(i) == 9 && direction == 1) {return false;}
        else if (matrixBoard.at(returnIntToArray(piece.getPosX(), direction).at(i)).at(piece.getPosY().at(i)).at(0) == 1) {return false;}
    }
    return true;
}





void Board::movePiece(int &pressedLeft, int &pressedRight, int &pressedDown, int level, int frame, int framesInTouch, Piece &piece, AnimationWindow &win)
{
    if (win.is_key_down(KeyboardKey::LEFT))
    {
        ++pressedLeft;
        if (pressedLeft%15 == 0 && moveValid(-1, piece))
        {
            int validMoveCount{0};
            for (int i = 0; i < 4; ++i)
            {
                if (piece.getPosX().at(i) - 1 > -1) {++validMoveCount;}
            }
            if (validMoveCount == 4) {piece.setPosX(returnIntToArray(piece.getPosX(), -1));}
        }
    }
    else {pressedLeft = 5;}

    if (win.is_key_down(KeyboardKey::RIGHT))
    {
        ++pressedRight;
        if (pressedRight%15 == 0 && moveValid(1, piece))
        {
            int validMoveCount{0};
            for (int i = 0; i < 4; ++i)
            {
                if (piece.getPosX().at(i) + 1 < 10) {++validMoveCount;}
            }
            if (validMoveCount == 4) {piece.setPosX(returnIntToArray(piece.getPosX(), 1));}
        }
    }
    else {pressedRight = 5;}

    if (win.is_key_down(KeyboardKey::DOWN))
    {
        piece.incrementDown(1, framesInTouch, frame, 5);

        if (frame%5 == 0 && framesInTouch == 0) {score += 1;}
    }
    else
    {
        piece.incrementDown(1, framesInTouch, frame, 60);
        pressedDown = 5;
    }
}




void Board::draw(AnimationWindow &win)
{
    for (int i = 0; i < matrixBoard.size(); ++i)
    {
        for (int j = 0; j < matrixBoard.at(0).size()-1; ++j)
        {
            if (matrixBoard.at(i).at(j).at(0) == 1)
            {
                int squareWidth = (int) win.height()*0.8/(20.0);
                TDT4102::Point topLeftPoint{static_cast<int>(win.width()*0.5 - 5*squareWidth), static_cast<int>(win.height()*0.5 - 10*squareWidth)};

                topLeftPoint.x += squareWidth*i;
                topLeftPoint.y += squareWidth*j;

                win.draw_rectangle(topLeftPoint, squareWidth, squareWidth, intToColor.at(matrixBoard.at(i).at(j).at(1)), TDT4102::Color::black);
            }
        }
    }
}



void Board::setPieceToBoard(Piece &piece)
{
    for (int i = 0; i < 4; ++i)
    {
        matrixBoard.at(piece.getPosX().at(i)).at(piece.getPosY().at(i)).at(0) = 1;
        matrixBoard.at(piece.getPosX().at(i)).at(piece.getPosY().at(i)).at(1) = colorToInt(piece.getColor()); 
    }
}



bool Board::toppedOut()
{
    for (int i = 0; i < 10; ++i)
    {
        if (matrixBoard.at(i).at(0).at(0) == 1) {return true;}
    }
    return false;
}




int Board::linesToPoints(int lines)
{
    switch (lines)
    {
    case 1:
        return 40*(level + 1);
    
    case 2:
        return 100*(level + 1);

    case 3: 
        return 300*(level + 1);
    
    case 4:
        return 1200*(level + 1);

    default:
        return 0;
    }
}