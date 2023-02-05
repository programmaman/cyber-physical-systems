// Place local declarations here.

bool myGrid[5][5];
Position path[100];
int pathCounter = 0;

int[1, 4] direction = 1; // 1 = East, 2 = North, 3 = West, 4 = South

Position myPosition = {0, 2};

Position setNextPosition()
{

    if (myPosition.posx + 1 < dimX)
    {
        if (myGrid[myPosition.posx + 1][myPosition.posy] == 0)
        {
            Position nextPosition = {myPosition.posx + 1, myPosition.posy};
            pathCounter++;
            return nextPosition;
        }
    }

    if (myPosition.posy + 1 < dimY)
    {
        if (myGrid[myPosition.posx][myPosition.posy + 1] == 0)
        {
            Position nextPosition = {myPosition.posx, myPosition.posy + 1};
            pathCounter++;
            return nextPosition;
        }
    }

    if (myPosition.posx - 1 > 0)
    {
        if (myGrid[myPosition.posx - 1][myPosition.posy] == 0)
        {
            Position nextPosition = {myPosition.posx - 1, myPosition.posy};
            pathCounter++;
            return nextPosition;
        }
    }

    if (myPosition.posy - 1 > 0)
    {
        if (myGrid[myPosition.posx][myPosition.posy - 1] == 0)
        {
            Position nextPosition = {myPosition.posx, myPosition.posy - 1};
            pathCounter++;
            return nextPosition;
        }
    }

    return path[pathCounter - 1];
}

void updateMyGrid(Position newPosition)
{

    path[pathCounter - 1] = myPosition;
    myPosition = newPosition;
    myGrid[myPosition.posx][myPosition.posy] = true;
}

void markGridPosition(Position blockedPosition)
{
    myGrid[blockedPosition.posx][blockedPosition.posy] = true;
}

Position syncWithRobot(Position nextPosition)
{
    if (nextPosition == robot1Position && robot1Position != destinationPosition1)
    {
        return myPosition;
    }

    if (nextPosition == robot1Position && robot1Position == destinationPosition1)
    {
        markGridPosition(nextPosition);
        return myPosition;
    }
    return nextPosition;
}
