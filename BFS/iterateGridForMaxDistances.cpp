class Solution {
public:
    
    int gridHeight;
    int gridWidth; 
    pair<int, int> directions[4] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    
    int maxDistance(vector<vector<int>>& grid) {     
        return resolveMaxDistanceOnGridBFS(grid) - 1;
        
    }
    
    int resolveMaxDistanceOnGridBFS(vector<vector<int>>& grid) {
        gridHeight = grid.size();
        gridWidth = grid[0].size();
        int max_distance = 0;
        queue<pair<int,int>> grid_positions_to_investigate_for_distance_to_land;
        fillqueueWithLandPositionsOnGrid(grid_positions_to_investigate_for_distance_to_land, grid);
        while(!grid_positions_to_investigate_for_distance_to_land.empty()) {
            auto current_loc_to_investigate = grid_positions_to_investigate_for_distance_to_land.front();
            grid_positions_to_investigate_for_distance_to_land.pop(); 
            for(auto& dir : directions) {
                int next_y = current_loc_to_investigate.first + dir.first;
                int next_x = current_loc_to_investigate.second + dir.second;
                if(next_y >=0 && next_y < gridHeight && next_x >= 0 && next_x < gridWidth && grid[next_y][next_x] == 0) {
                    grid[next_y][next_x] = grid[current_loc_to_investigate.first][current_loc_to_investigate.second] + 1;
                    grid_positions_to_investigate_for_distance_to_land.push({next_y, next_x});
                    max_distance = max(max_distance, grid[next_y][next_x]);
                }
            }  
        }
        return max_distance;
    }
    
    void fillqueueWithLandPositionsOnGrid(queue<pair<int,int>>& queue, vector<vector<int>>& orig_grid) {
        for(int i = 0; i < gridHeight; i++) {
            for(int j = 0; j < gridWidth; j++) {
                if (orig_grid[i][j] == 1) {
                    queue.push({i, j});
                }
            }
        }
    }
};
