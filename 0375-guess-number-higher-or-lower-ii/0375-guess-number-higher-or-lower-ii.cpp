class Solution {
public:
    int recursion(int s, int e) {
        if (s >= e) return 0;
        int ans = INT_MAX;
        for (int i = s; i < e; i++) {
            ans = min(ans, i + max(recursion(i + 1, e), recursion(s, i - 1)));
        }
        return ans;
    }

    int memo(int s, int e, vector<vector<int>>& dp) {
        if (s >= e) return 0;
        if (dp[s][e] != -1) return dp[s][e];
        int ans = INT_MAX;
        for (int i = s; i < e; i++) {
            ans = min(ans, i + max(memo(i + 1, e, dp), memo(s, i - 1, dp)));
        }
        return dp[s][e] = ans;
    }

    int tab(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        for (int s = n; s >= 1; s--) {
            for (int e = s + 1; e <= n; e++) {
                int ans = INT_MAX;
                for (int i = s; i <= e; i++) {
                    ans = min(ans, i + max(dp[s][i - 1], dp[i + 1][e]));
                }
                dp[s][e] = ans;
            }
        }
        return dp[1][n];
    }

    int getMoneyAmount(int n) {
        return tab(n);  
    }
};