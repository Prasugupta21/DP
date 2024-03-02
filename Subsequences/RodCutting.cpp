int f(int i, vector<vector<int>> &dp, vector<int> &val, int W)
{
    if (i == 0)
    {

        int x = val[0];
        x *= (W / (i + 1));
        return x;
    }
    if (dp[i][W] != -1)
        return dp[i][W];
    int take = -1e9;
    int notTake = 0 + f(i - 1, dp, val, W);
    if (W >= i + 1)
        take = val[i] + f(i, dp, val, W - (i + 1));
    return dp[i][W] = max(take, notTake);
}

int cutRod(vector<int> &val, int W)
{
    int n = val.size();
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    for (int i = 0; i <= W; i++)
    {
        dp[0][i] = (i)*val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            int take = -1e9;
            int notTake = 0 + dp[i - 1][j];
            if (j >= i + 1)
                take = val[i] + dp[i][j - i - 1];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}
