class Solution {
public:
    
    
    int minFallingPathSum(vector<vector<int>>& A) {
        auto rows = A.size();
        auto columns = A[0].size();
        for (int i = 1; i < rows; i ++) {
            auto current_row = A[i - 1];
            for (int j = 0; j < columns; j++) {
                int column_ending_post_fix = 2;
                int column_starting_prefix = 1;
                if (j == (columns - 1)) {
                    column_ending_post_fix = 1;
                }
                if (j == 0) {
                    column_starting_prefix = 0;
                }
                int min_element_to_add = *min_element(current_row.begin() + (j - column_starting_prefix), current_row.begin() + (j + column_ending_post_fix));
                A[i][j] = A[i][j] + min_element_to_add; 
            }
        }
        auto result_raw = A[rows - 1];
        return *min_element(result_raw.begin(), result_raw.end());
    }
};
