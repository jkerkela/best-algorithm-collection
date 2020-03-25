class Solution {
    
private:
int nextStepDims[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int boardWidth, boardHeight;
vector<vector<bool>>visited;
    
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        
        return resolveAmountOfIndependentlyConnectedRegions(grid);
    }
    
    int resolveAmountOfIndependentlyConnectedRegions(vector<vector<char>>& grid) {
        int islandCount = 0;
        boardWidth = grid[0].size();
        boardHeight = grid.size();
        visited = vector<vector<bool>>(boardHeight, vector<bool>(boardWidth, false));
        
        for(int i = 0; i < boardHeight; i++) {
            for(int j = 0; j < boardWidth; j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    floodfillConnectedRegions(grid, j, i, visited);
                    islandCount ++;
                }
            }
        }
        return islandCount;
    }
    
    void floodfillConnectedRegions(vector<vector<char>>& grid, int x, int y, vector<vector<bool>>& visited) {
        if(x < 0 || y < 0 || x >= boardWidth || y >= boardHeight || visited[y][x] || grid[y][x] == '0') {
            return;
        }
        visited[y][x] = true;
        for(int i = 0; i < 4; i++) {
            int nextY = y + nextStepDims[i][0];
            int nextX = x + nextStepDims[i][1];
            floodfillConnectedRegions(grid, nextX, nextY, visited);
        }
    }
};
