#include <bits/stdc++.h> 
int f(int i,vector<vector<int>>&dp,int target,vector<int>&c){
    if(i==0){
        if(target%c[i]==0)return target/c[i];
        return 1e9;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notTake=0+f(i-1,dp,target,c);
    int take=INT_MAX;
    if(target>=c[i])take=1+f(i,dp,target-c[i],c);
    return dp[i][target]=min(take,notTake);
}
int minimumElements(vector<int> &c, int target)
{
    int n=c.size();
    vector<int>dp(target+1,0),curr(target+1,0);
    for(int j=0;j<=target;j++){
        if(j%c[0]==0)dp[j]=j/c[0];
        else dp[j]=1e9;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int take=1e9;
            int notTake=0+dp[j];
            if(j>=c[i])take=1+curr[j-c[i]];
            curr[j]=min(take,notTake);
        }
dp=curr;
    }

    return (dp[target]>=1e9)?-1:dp[target];
    
    // Write your code here.
}