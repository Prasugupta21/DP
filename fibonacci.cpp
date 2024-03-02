#include<bits/stdc++.h>
using namespace std;

//memoization
int f(int n,vector<int>&dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}



int main(){
int n;
cin>>n;

//tabulation 
vector<int>dp(n+1,-1);
// cout<<f(n,dp); for memoization


//tabulation 


// dp[0]=0,dp[1]=1;
// for(int i=2;i<=n;i++){
//     dp[i]=dp[i-1]+dp[i-2];
// }
// cout<<dp[n];



//space optimization

int prev=1,prev2=0,curr;
for(int i=2;i<=n;i++){
    curr=prev+prev2;
    prev2=prev;
    prev=curr;
}
if(n<=1)cout<<n;
else cout<<prev;

    return 0;
}