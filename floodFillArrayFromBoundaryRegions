class Solution {
    
private:
    int nextStepDims[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
    int boardWidth, boardHeight;
    vector<vector<bool>>visited;
    vector<vector<bool>>isX;
    
public:
    
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0)
			return;
        resolveBoardBoundaryRegions(board);
    
    }
    
    void resolveBoardBoundaryRegions(vector<vector<char>>& board) {
        boardWidth = board[0].size();
        boardHeight = board.size();
        visited = vector<vector<bool>>(boardHeight, vector<bool>(boardWidth, false));
        isX = vector<vector<bool>>(boardHeight, vector<bool>(boardWidth, true));
        
        for(int i = 0; i < boardHeight; i ++) {
            for(int j = 0; j < boardWidth; j ++) {
                if ((i == 0 || j == 0 || i==boardHeight-1 || j==boardWidth-1) && board[i][j]=='O') {
                    exploreBoundaryFloodFill(board, visited, isX, i , j);
                }
            }  
        }
        for(int i = 0; i < boardHeight; i++) {
            for(int j = 0; j < boardWidth; j++) {
                if (isX[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void exploreBoundaryFloodFill(vector<vector<char>>& board, vector<vector<bool>>& visited, vector<vector<bool>>& isX, int x, int y){
        if (x < 0 || y < 0 || x >= boardHeight || y >= boardWidth || visited[x][y] || board[x][y] == 'X')
			return;
        visited[x][y] = true;
        isX[x][y] = false;
        for(int i = 0; i < 4; i++) {
            int nextY = y + nextStepDims[i][1];
            int nextX = x + nextStepDims[i][0];
            exploreBoundaryFloodFill(board, visited, isX, nextX, nextY);
        }
    }
};
