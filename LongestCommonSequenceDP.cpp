class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       
        int DP[text1.size() + 1][text2.size() + 1];
        for(int i = 0; i <= text1.size(); i++) {
            for(int j = 0; j <= text2.size(); j++) {
                if (i == 0 || j == 0) {
                    DP[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    DP[i][j] = DP[i - 1][j - 1] + 1;
                } else {
                    DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                }
            }
        }
        return DP[text1.size()][text2.size()];
    }
};
