class Solution
{
public:
    int f(int i, vector<int> &arr, int k, vector<int> &dp)
    {
        int n = arr.size();
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int sum = arr[i];
        int ans = -1e9;
        for (int j = i; j < i + k && j < n; j++)
        {
            int partition = j - i + 1;

            sum = max(sum, arr[j]);
            partition *= sum;
            int x = partition + f(j + 1, arr, k, dp);
            ans = max(ans, x);
        }
        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = arr[i];
            int ans = -1e9;
            for (int j = i; j < i + k && j < n; j++)
            {
                int partition = j - i + 1;

                sum = max(sum, arr[j]);
                partition *= sum;
                int x = partition + dp[j + 1];
                ans = max(ans, x);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};