//m
#include <bits/stdc++.h> 
int f(int i,vector<int>&dp,vector<int>&nums){
    if(i==0)return nums[i];
    if(i<0)return 0;
    if(dp[i]!=-1)return dp[i];
    int pick=nums[i]+f(i-2,dp,nums);
    int notPick=0+f(i-1,dp,nums);
    return dp[i]=max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,dp,nums);
}

//tabu
#include <bits/stdc++.h> 

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<int>dp(n,0);
    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1)take+=dp[i-2];
        int nonTake=0+dp[i-1];
        dp[i]=max(take,nonTake);
    }
    return dp[n-1];
}