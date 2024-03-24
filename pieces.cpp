#include "pieces.h"
#include "rotation.h"


Piece::Piece(array<int,4> xPos, array<int,4> yPos, TDT4102::Color color, void (*rotate)(Piece &piece)):
    xPos{xPos}, yPos{yPos}, color{color}, rotate{rotate} {}



void Piece::embedPos(array<array<int, 20>, 10> &arr)
{
    for (int i = 0; i < xPos.size(); ++i)
    {
        arr.at(xPos.at(i)).at(yPos.at(i)) = 1;
    }
}


TDT4102::Color Piece::getColor()
{
    return color;
}


array<int,4> Piece::getPosX()
{
    return xPos;
}


array<int,4> Piece::getPosY() 
{
    return yPos;
}


void Piece::setPosX(array<int, 4> input)
{
    xPos = input;
}


void Piece::draw(AnimationWindow &win)
{
    // draw arr_last - arr to reduce computational power

    int squareWidth = (int) win.height()*0.8/(20.0);
    

    for (int i = 0; i < xPos.size(); ++i)
    {
            
        TDT4102::Point topLeftPoint{static_cast<int>(win.width()*0.5 - 5*squareWidth), static_cast<int>(win.height()*0.5 - 10*squareWidth)};

        topLeftPoint.x += squareWidth*xPos.at(i);
        topLeftPoint.y += squareWidth*yPos.at(i);

        win.draw_rectangle(topLeftPoint, squareWidth, squareWidth, color, TDT4102::Color::black);
    } 
}



void Piece::incrementDown(int level, int framesInTouch, int frame, int interval)
{
    // Replace 60 by level enum
    if (framesInTouch > 0) {return;}

    else if (frame%interval == 0)
    {
        for (int i = 0; i < yPos.size(); ++i)
        {
            yPos.at(i)++;
        }
    }
}











Piece genRndPiece()
{
    map<int, Piece> intToPiece
    {
        {1, Piece{{4,5,4,5}, {0,0,1,1}, TDT4102::Color::light_green, rotateO}}, {2, Piece{{3,4,5,6}, {0,0,0,0}, TDT4102::Color::light_green, rotateI}}, 
        {3, Piece{{4,5,6,6}, {0,0,0,1}, TDT4102::Color::orange_red, rotateJ}}, {4, Piece{{4,5,6,4}, {0,0,0,1}, TDT4102::Color::dark_turquoise, rotateL}}, 
        {5, Piece{{5,6,4,5}, {0,0,1,1}, TDT4102::Color::dark_turquoise, rotateS}}, {6, Piece{{4,5,5,6}, {0,0,1,1}, TDT4102::Color::orange_red, rotateZ}},
        {7, Piece{{4,5,6,5}, {0,0,0,1}, TDT4102::Color::light_green, rotateT}}
    };

    random_device rd;
    default_random_engine gen(rd());
    uniform_int_distribution<int> dist(1,7);
    int randInt = dist(gen);

    return intToPiece.at(randInt);
}
