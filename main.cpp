#include <iostream>
#include <windows.h>

#ifdef DELETE
#undef DELETE
#endif

#include "game.h"
#include "GUI.h"
#include "mmsystem.h"
#include "windows.h"

AnimationWindow window{50, 50, 1024, 768, "Tetris"};


int main()
{
    bool prevLeft;
    bool prevRight;
    int frame{0};


    while (!window.should_close())
    {
        // PlaySound(TEXT("tetris1.wav"), NULL, SND_FILENAME | SND_ASYNC);
        bool gameOver{false};
        Board board;
        board.setBoard();   // Integrate into constructor

        while (!gameOver)
        {
            Piece piece = genRndPiece();
            
            placePiece(piece, board, window, gameOver);
    
            // updateScore();
            // updateNextPiece();

            gameOver = board.toppedOut();
            window.next_frame();
        }
        
        // gameOverScreen();
        
        
        // Score, lines, level
        window.next_frame();
    }

    return 0;
}
