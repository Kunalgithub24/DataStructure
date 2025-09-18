class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<vector<string>>> dp(n + 1, vector<vector<string>>(n + 1));
        dp[0][0] = {""};

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                vector<string> t;
                if (i != j) {
                    for (string& s: dp[i - 1][j]) {
                        t.push_back(s + "(");
                    }

                }
                if (j != 0) {
                    for (string& s: dp[i][j - 1]) {
                        t.push_back(s + ")");
                    }
                }
                dp[i][j] = std::move(t);
            }
        }

        return dp[n][n];
    }
};
