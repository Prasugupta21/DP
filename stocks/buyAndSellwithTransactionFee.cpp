class Solution
{
public:
    int f(int i, int buy, vector<int> &p, vector<vector<int>> &dp,int fee)
    {
        if (i == p.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int maxProfit;
        if (buy)
        {
            int take = -p[i] + f(i + 1, 0, p, dp,fee);
            int notTake = 0 + f(i + 1, 1, p, dp,fee);
            maxProfit = max(take, notTake);
        }
        else
        {
            int take =( p[i]-fee) + f(i + 1, 1, p, dp,fee);
            int notTake = 0 + f(i + 1, 0, p, dp,fee);
            maxProfit = max(take, notTake);
        }
        return dp[i][buy] = maxProfit;
    }
    int maxProfit(vector<int> &p,int fee)
    {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, p, dp,fee);
    }
};