class Solution {
public:
    
    int nextStepDims[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    
    int orangesRotting(vector<vector<int>>& grid) {
        return stepsNeededForSpreadingRotOverGrid(grid);
    }
    
    int stepsNeededForSpreadingRotOverGrid(vector<vector<int>>& grid) {
        int gridWidth = grid[0].size();
        int gridHeight = grid.size();
        int currentSteps = -1;
        int currentFreshItemCount = 0;
        queue<pair<int,int>> rottenItemLocations;
        addCurrentRotItemsToQueue(grid, rottenItemLocations, currentFreshItemCount, gridWidth, gridHeight);
        pair<int,int> currentRotItemLocation = rottenItemLocations.front();
        while(!rottenItemLocations.empty()) {
            int levelSize = rottenItemLocations.size();
            for(int i = 0; i < levelSize; i++) {
                pair<int,int> currentRotItemLocation = rottenItemLocations.front();
                rottenItemLocations.pop();
                int yCoord = currentRotItemLocation.first;
                int xCoord = currentRotItemLocation.second;
                for(auto stepToAdjacentLoc : nextStepDims) {
                    int adjacentXCoord = xCoord + stepToAdjacentLoc[0];
                    int adjacentYCoord = yCoord + stepToAdjacentLoc[1];
                    if(adjacentXCoord >= 0 && adjacentXCoord < gridWidth && adjacentYCoord >= 0 && adjacentYCoord < gridHeight && grid[adjacentYCoord][adjacentXCoord] == 1) {
                        grid[adjacentYCoord][adjacentXCoord] = 2;
                        currentFreshItemCount--;
                        rottenItemLocations.push({adjacentYCoord, adjacentXCoord});
                    } 
                }
            }
            currentSteps++;
        }
        
        if(currentFreshItemCount > 0) {
            return -1;
        }
        if (currentSteps == -1) {
            return 0;
        }
        return currentSteps;
    }
    
    void addCurrentRotItemsToQueue(vector<vector<int>>& grid, queue<pair<int,int>>& rottenItemLocations, int& currentFreshItemCount, int& gridWidth, int& gridHeight) {
        for(int  i = 0; i < gridHeight; i++) {
            for(int j = 0; j < gridWidth; j++) {
                if(grid[i][j] == 2) {
                    rottenItemLocations.push({i, j});
                }
                if(grid[i][j] == 1) {
                    currentFreshItemCount++;
                }
            }
        }
    }
    
   
};
