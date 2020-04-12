class Solution {
public:
    
    int nextStepDims[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int gridWidth;
    int gridHeight;
    
    int shortestBridge(vector<vector<int>>& A) {
        return resolveShortestPathJoiningIslandsDFSBFS(A);
    }
    
    int resolveShortestPathJoiningIslandsDFSBFS(vector<vector<int>>& grid) {
        gridWidth = grid[0].size();
        gridHeight = grid.size();
        
        int stepsFromIslandValAdjust = 3;
        int stepsFromIslandNonClashingWithIslandVals = 0 + stepsFromIslandValAdjust;
        queue<pair<int,int>> gridPositionToInvstigate;
        markStartingIslandBFS(grid, gridPositionToInvstigate);
        vector<vector<bool>> visitedLocations = vector<vector<bool>>(gridHeight, vector<bool>(gridWidth, false));
        pair<int,int> inslandStartLoc = gridPositionToInvstigate.front();
        floodfillIsland(grid, gridPositionToInvstigate, inslandStartLoc.second, inslandStartLoc.first, visitedLocations, false);
        while(!gridPositionToInvstigate.empty()) {
            int currentLevelSize = gridPositionToInvstigate.size();
            for(int i = 0; i < currentLevelSize; i++) {
                pair<int,int> currentLoc = gridPositionToInvstigate.front();
                gridPositionToInvstigate.pop();
                int yCoord = currentLoc.first;
                int xCoord = currentLoc.second;
                for(auto stepToAdjacentLoc : nextStepDims) {
                    int adjacentXCoord = xCoord + stepToAdjacentLoc[0];
                    int adjacentYCoord = yCoord + stepToAdjacentLoc[1];
                    if(adjacentXCoord >= 0 && adjacentXCoord < gridWidth && adjacentYCoord >= 0 && adjacentYCoord < gridHeight) {
                        if(grid[adjacentYCoord][adjacentXCoord] == 0) {
                            grid[adjacentYCoord][adjacentXCoord] = stepsFromIslandNonClashingWithIslandVals + 1;
                            gridPositionToInvstigate.push({adjacentYCoord, adjacentXCoord});
                        }
                        if(grid[adjacentYCoord][adjacentXCoord] == 1) {
                            return stepsFromIslandNonClashingWithIslandVals - stepsFromIslandValAdjust;
                        }
                    }
                }
            }
            stepsFromIslandNonClashingWithIslandVals++;
        }
        return 0;
    }
    
    void markStartingIslandBFS(vector<vector<int>>& grid, queue<pair<int,int>>& gridPositionToInvstigate) {
        for (int i = 0; i < gridHeight; i++) {
            for (int j = 0; j < gridWidth; j++) {
                if (grid[i][j] == 1) {
                    gridPositionToInvstigate.push({i, j});
                    return;
                }
            }
        }
    }
    
    void floodfillIsland(vector<vector<int>>& grid, queue<pair<int,int>>& gridPositionToInvstigate, int x, int y, vector<vector<bool>>& visited, bool newLoc) {
        if(x < 0 || y < 0 || x >= gridWidth || y >= gridHeight || visited[y][x] || grid[y][x] != 1) {
            return;
        }
        visited[y][x] = true;
        grid[y][x] = 2;
        if (newLoc) {
            gridPositionToInvstigate.push({y, x});
        }
        for(int i = 0; i < 4; i++) {
            int nextY = y + nextStepDims[i][0];
            int nextX = x + nextStepDims[i][1];
            floodfillIsland(grid, gridPositionToInvstigate, nextX, nextY, visited, true);
        }
    }
};
