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
bool subsetSumToK(int n, int target, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int k = 1; k <= target; k++)
        {
            bool take = false;
            bool nonTake = dp[i - 1][k];
            if (k >= arr[i])
                take = dp[i - 1][k - arr[i]];
            dp[i][k] = take | nonTake;
        }
    }
    return dp[n - 1][target];
}

//space
bool subsetSumToK(int n, int target, vector<int> &arr) {
    // Write your code here.
    vector<bool>dp(target+1,0);
       vector<bool>curr(target+1,0);
     curr[0]=true;
    
dp[0]=true;
    dp[arr[0]]=true;
    for(int i=1;i<n;i++){
    
        for(int k=1;k<=target;k++){
            bool take=false;
            bool nonTake=dp[k];
             if(k>=arr[i])take=dp[k-arr[i]];
             curr[k]=take|nonTake;
        }
        dp=curr;
    }
     return dp[target];

     //space 
         // Write your code here.
    vector<bool>dp(target+1,0);
     
    
dp[0]=true;
    dp[arr[0]]=true;
    for(int i=1;i<n;i++){
      vector<bool>curr(target+1,0);
     curr[0]=true;
        for(int k=1;k<=target;k++){
            bool take=false;
            bool nonTake=dp[k];
             if(k>=arr[i])take=dp[k-arr[i]];
             curr[k]=take|nonTake;
        }
        dp=curr;
    }
     return dp[target];
}