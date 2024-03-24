#include "GUI.h"


// MAKE DISPLAY CLASS

void drawOutline(AnimationWindow &win)
{
    int squareWidth = (int) win.height()*0.8/(20.0);
    
    int xLeft = static_cast<int>(win.width()*0.5 - 5*squareWidth);
    int xRight = static_cast<int>(win.width()*0.5 + 5*squareWidth);

    int yUp = static_cast<int>(win.height()*0.5 + 10*squareWidth);
    int yDown = static_cast<int>(win.height()*0.5 - 10*squareWidth);

    
    win.draw_rectangle({xLeft - squareWidth/2, yUp - 20*squareWidth - squareWidth/2}, squareWidth*10 + squareWidth, squareWidth*20 + squareWidth, TDT4102::Color::dodger_blue);
    win.draw_rectangle({xLeft, yUp - 20*squareWidth}, squareWidth*10, squareWidth*20, TDT4102::Color::black);


    win.draw_line({xLeft, yUp}, {xRight, yUp});
    win.draw_line({xLeft, yUp}, {xLeft, yDown});

    win.draw_line({xLeft, yDown}, {xRight, yDown});
    win.draw_line({xRight, yDown}, {xRight, yUp});
}


void displayScore(AnimationWindow &win, int score)
{
    int squareWidth = (int) win.height()*0.8/(20.0);
    int xRight = static_cast<int>(win.width()*0.5 + 5*squareWidth);
    int yUp = static_cast<int>(win.height()*0.5 - 10*squareWidth);

    array<int, 6> scoreText = intToDigits(score);

    win.draw_rectangle({static_cast<int>(xRight + (3.0/2)*squareWidth), yUp + squareWidth}, 4*squareWidth + 0.5*squareWidth , 3*squareWidth + 0.5*squareWidth , TDT4102::Color::dodger_blue);
    win.draw_rectangle({static_cast<int>(xRight + 2*squareWidth - (1.0/4)*squareWidth), static_cast<int>(yUp + (3.0/2)*squareWidth - (1.0/4)*squareWidth)}, 4*squareWidth, 3*squareWidth, TDT4102::Color::black);

    win.draw_text({static_cast<int>(xRight + (5.0/2)*squareWidth), static_cast<int>(yUp + (1.2)*squareWidth)}, "Score", TDT4102::Color::white, 30, TDT4102::Font::arial);

    
    for (int i = 0; i < scoreText.size(); ++i)
    {
    win.draw_text({static_cast<int>(xRight + (1.88)*squareWidth + i*0.6*squareWidth), static_cast<int>(yUp + (2.5)*squareWidth)}, to_string(scoreText.at(i)), TDT4102::Color::white, 30, TDT4102::Font::arial);
    }
    
}



void drawLogo(AnimationWindow &win)
{
    int squareWidth = (int) win.height()*0.8/(20.0);
    Image logo("logo.png");
    win.draw_image({static_cast<int>(win.width()/2.0 - 2*squareWidth), static_cast<int>(0.6*squareWidth)}, logo, 4.5*squareWidth, 1.5*squareWidth);
}