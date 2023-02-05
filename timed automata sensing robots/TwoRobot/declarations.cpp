// Place global declarations here.

typedef struct
{
    int posx;
    int posy;
} Position;

const int dimX = 5;
const int dimY = 5;
const int numOfBlockedPositions = 5;

chan blocked, notblocked, requested;

bool ob;

//Configuration Vars

Position positionRequest;
Position robot1Position;
Position robot2Position;

//Blocked Positions Array
Position blockedPositions[numOfBlockedPositions] = {{1, 1}, {2, 2}, {3, 1}, {3, 3}, {4, 1}};

//Final Values

Position destinationPosition1 = {4, 4};
Position destinationPosition2 = {3, 4};