// TLE

#include <bits/stdc++.h>
bool f(int i, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[0] == target;
    bool nonTake = f(i - 1, target, arr);
    bool take = false;
    if (target >= arr[i])
        take = f(i - 1, target - arr[i], arr);
    return take || nonTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.

    return f(n - 1, k, arr);
}

// dp
#include <bits/stdc++.h>
bool f(int i, int target, vector<vector<int>> &dp, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[0] == target;
    if (dp[i][target] != -1)
        return dp[i][target];
    bool nonTake = f(i - 1, target, dp, arr);
    bool take = false;
    if (target >= arr[i])
        take = f(i - 1, target - arr[i], dp, arr);
    return dp[i][target] = take || nonTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, k, dp, arr);
}

// tabulation
