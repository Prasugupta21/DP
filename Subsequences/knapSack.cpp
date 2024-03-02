#include <bits/stdc++.h>
int f (int i,vector<int>& w,vector<int> &v,int W,vector<vector<int>>&dp){
	if(i==0){
		if(W>=w[0])return v[0];
		return 0;
	}
	if(dp[i][W]!=-1)return dp[i][W];
	int pick=INT_MIN;
	int notPick=0+f(i-1,w,v,W,dp);
	if(W>=w[i]){
		pick=v[i]+f(i-1,w,v,W-w[i],dp);
	}
	return dp[i][W]=max(pick,notPick);
}
int knapsack(vector<int> w, vector<int> v, int n, int W) 
{
	vector<vector<int>>dp(n,vector<int>(W+1,0));
	for(int j=w[0];j<=W;j++)dp[0][j]=v[0];
	
	for(int i=1;i<n;i++){
		for(int j=0;j<=W;j++){
			int pick=INT_MIN;
			int notPick=0+dp[i-1][j];
			if(j>=w[i])pick=v[i]+dp[i-1][j-w[i]];
			dp[i][j]=max(pick,notPick);
		}
	}
	return dp[n-1][W];
	// Write your code here
}

//single Array DP  space 

int knapsack(vector<int> w, vector<int> v, int n, int W) 
{
	vector<int>dp(W+1,0);
	for(int j=w[0];j<=W;j++)dp[j]=v[0];
	
	for(int i=1;i<n;i++){
		for(int j=W;j>=0;j--){
			int pick=INT_MIN;
			int notPick=0+dp[j];
			if(j>=w[i])pick=v[i]+dp[j-w[i]];
			dp[j]=max(pick,notPick);
		}
	}
	return dp[W];
	// Write your code here
}