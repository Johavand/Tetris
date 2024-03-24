#include "rotation.h"



void Piece::rotateLeft()
{
    rotationState -= 1;
}


void Piece:: rotateRight()
{
    ++rotationState;
}


void Piece::invokeRotate()
{
    rotate(*this);
}



int Piece::getRotationState()
{
    return rotationState;
}

int Piece::getPrevRotationState()
{
    return prevRotationState;
}


void Piece::updatePos(array<int, 4> incrementX, array<int, 4> incrementY)
{
    int invalidRotations{0};
    for (int i = 0; i < 4; ++i)
    {
        if (sumArrays(xPos, incrementX).at(i) < 0 or sumArrays(xPos, incrementX).at(i) > 9) 
        {
            ++invalidRotations;
        }

        if (sumArrays(yPos, incrementY).at(i) < 0) 
        {
            ++invalidRotations;
        }
    }
    if (invalidRotations == 0)
    {
        xPos = sumArrays(xPos, incrementX);
        yPos = sumArrays(yPos, incrementY);
    }
    else {rotationState = prevRotationState;}
}






void rotateO(Piece &piece)
{
    return;
}



void rotateI(Piece &piece)
{
    int index = intToIndex(piece.getRotationState(), 2);

    array<array<int, 4>, 2> increment = {{{-2,-1,0,1}, {2,1,0,-1}}};

    piece.updatePos(increment.at(index), increment.at(intToIndex(index-1, 2)));
}


void rotateJ(Piece &piece)
{
    int index = intToIndex(piece.getRotationState(), 4);
    
    array<array<int, 4>, 4> increment = {{{-1,0,1,0}, {1,0,-1,-2}, {1,0,-1,0}, {-1,0,1,2}}};

    if (piece.getRotationState() - piece.getPrevRotationState() == 1)
    {
        piece.updatePos(increment.at(index), increment.at(intToIndex(index - 1, 4)));
    }
    else {piece.updatePos(increment.at(intToIndex(piece.getPrevRotationState() - 2, 4)), increment.at(intToIndex(piece.getPrevRotationState() - 3, 4)));}
}



void rotateL(Piece &piece)
{
    int index = intToIndex(piece.getRotationState(), 4);

    array<array<int, 4>, 4> increment = {{{-1,0,1,-2}, {1,0,-1,0}, {1,0,-1,2}, {-1,0,1,0}}};

    if (piece.getRotationState() - piece.getPrevRotationState() == 1)
    {
        piece.updatePos(increment.at(index), increment.at(intToIndex(index - 1, 4)));
    }
    else {piece.updatePos(increment.at(intToIndex(piece.getPrevRotationState() - 2, 4)), increment.at(intToIndex(piece.getPrevRotationState() - 3, 4)));}
}



void rotateS(Piece &piece)
{
    int index = intToIndex(piece.getRotationState(), 2);

    array<array<int, 4>, 2> incrementX = {{{-1,0,-1,0}, {1,0,1,0}}};
    array<array<int, 4>, 2> incrementY = {{{0,-1,2,1}, {0,1,-2,-1}}};

    piece.updatePos(incrementX.at(index), incrementY.at(index));
}



void rotateZ(Piece &piece)
{
    int index = intToIndex(piece.getRotationState(), 2);

    array<array<int, 4>, 2> incrementX = {{{-2,-1,0,1}, {2,1,0,-1}}};
    array<array<int, 4>, 2> incrementY = {{{1,0,1,0}, {-1,0,-1,0}}};

    piece.updatePos(incrementX.at(index), incrementY.at(index));
}



void rotateT(Piece &piece)
{
    int index = intToIndex(piece.getRotationState(), 4);

    array<array<int, 4>, 4> incrementX = {{{-1,0,1,-1}, {1,0,-1,-1}, {1,0,-1,1}, {-1,0,1,1}}};
    array<array<int, 4>, 4> incrementY = {{{-1,0,1,1}, {-1,0,1,-1}, {1,0,-1,-1}, {1,0,-1,1}}};

    if (piece.getRotationState() - piece.getPrevRotationState() == 1)
    { 
        piece.updatePos(incrementX.at(index), incrementY.at(index));
    }
    else {piece.updatePos(incrementX.at(intToIndex(piece.getPrevRotationState() - 2, 4)), incrementY.at(intToIndex(piece.getPrevRotationState() - 2, 4)));}
}



void Piece::keyboardRotate(bool &prevA, bool &prevUp, AnimationWindow &win)
{
    if (win.is_key_down(KeyboardKey::A) && !prevA)
    {
        prevRotationState = rotationState;
        rotateLeft();
        invokeRotate();
        prevA = true;
    }
    else if (!win.is_key_down(KeyboardKey::A) && prevA)
    {
        prevA = false;
    }


    if (win.is_key_down(KeyboardKey::UP) && !prevUp)
    {
        prevRotationState = rotationState;
        rotateRight();
        invokeRotate();
        prevUp = true;
    }
    else if (!win.is_key_down(KeyboardKey::UP) && prevUp)
    {
        prevUp = false;
    }
}