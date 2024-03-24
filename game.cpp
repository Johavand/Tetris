#include "game.h"
#include "GUI.h"





void placePiece(Piece piece, Board &board, AnimationWindow &win, bool &gameOver)
{
    bool prevLeft{false};
    bool prevRight{false};

    // Frame counters (level dependent)
    int frame{0};
    int framesInTouch{0};
    int pressedLeft{0};
    int pressedRight{0};
    int pressedDown{0};

    while (framesInTouch < 60 && !win.should_close())
    {
        drawOutline(win); // draw in main or make a general gameDraw()
        drawLogo(win);
        board.draw(win);
        piece.draw(win);
        
        frame++;
        piece.keyboardRotate(prevLeft, prevRight, win);
        board.checkTouch(piece, framesInTouch, frame);

        board.movePiece(pressedLeft, pressedRight, pressedDown, 1, frame, framesInTouch, piece, win);
        displayScore(win, board.getScore());

        win.next_frame();
    }
    board.setPieceToBoard(piece);
    board.lineClear(piece, frame, board, win);

    drawOutline(win);
    drawLogo(win);
    
}




void Board::lineClear(Piece piece, int frame, Board board, AnimationWindow &win)
{
    vector<int> clearLines;
    for (int i = 0; i < 4; ++i)
    {
        if (allOnes(matrixBoard, piece.getPosY().at(i))) {clearLines.push_back(piece.getPosY().at(i));}
    }
    sort(clearLines.begin(), clearLines.end());
    clearLines.erase(unique(clearLines.begin(), clearLines.end()), clearLines.end());

    clearAnimation(clearLines, board, win);

    for (int i = 0; i < clearLines.size(); ++i)
    {
        pushDown(matrixBoard, clearLines.at(i));
    }

    score += linesToPoints(clearLines.size());
}





void Board::clearAnimation(vector<int> clearLines, Board board, AnimationWindow &win)
{
    int squareWidth = (int) win.height()*0.8/(20.0);
    if (clearLines.size() > 0)
    {
        int frame{1};
        while (frame < 20)
        {
            drawOutline(win);
            drawLogo(win);
            board.draw(win);
            displayScore(win, board.getScore());
            
            if (frame%5 == 0 or frame == 1)
            {
                for (int elem : clearLines)
                {
                    board.setTetrimino(4 - frame/5, elem);
                    board.setTetrimino(5 + frame/5, elem);
                }
            }
            
            ++frame;
            win.next_frame();
        }
    }
}