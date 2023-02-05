
bool grid[5][5];

void initializeGrid(Position blockedPosition[numOfBlockedPositions]){
for(i : int [0,numOfBlockedPositions - 1]) 
    {
        grid[blockedPosition[i].posx][blockedPosition[i].posy] = true;
    }
}

bool checkPosition(Position position){

int x = position.posx;
int y = position.posy;

if((x > dimX || x < 0) ||(y > dimY || y <0)){
    return true;
}

return grid[x][y];

}

