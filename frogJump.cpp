#include <bits/stdc++.h> 
int f(int n,vector<int>&dp,vector<int>&heights){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int left=f(n-1,dp,heights)+abs(heights[n-1]-heights[n]);
    int right=INT_MAX;
    if(n>1)
     right=f(n-2,dp,heights)+abs(heights[n-2]-heights[n]);
    return dp[n]=min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
return f(n-1,dp,heights);

    // Write your code here.
}


//tabulation

#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,0);
dp[0]=0;
for(int i=1;i<n;i++){
   int  left=dp[i-1]+abs(heights[i]-heights[i-1]);
  int right=INT_MAX;
  if(i>1)
  right=dp[i-2]+abs(heights[i]-heights[i-2]);
  dp[i]=min(left,right);
}
return dp[n-1];

    // Write your code here.
}

//space optimization

#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
int prev=0,prev2=0;
for(int i=1;i<n;i++){
   int  left=prev+abs(heights[i]-heights[i-1]);
  int right=INT_MAX;
  if(i>1)
  right=prev2+abs(heights[i]-heights[i-2]);
int curr=min(left,right);
prev2=prev;
prev=curr;
}
return prev;

    // Write your code here.
}