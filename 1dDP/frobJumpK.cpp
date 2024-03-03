#include<bits/stdc++.h>
using namespace std;

int f(int n,vector<int>&dp,vector<int>&h,int k){
  if(n==0)return 0;
  if(dp[n]!=-1)return dp[n];
  int minSteps=INT_MAX;
  for(int i=1;i<=k;i++){
    if(n-i>=0)
     {
        int d=f(n-i,dp,h,k)+abs(h[n]-h[n-i]);
   minSteps=min(minSteps,d);
   }
   
  }
  return dp[n]=minSteps;
  
}
int main(){
  int n,k;
  cin>>n>>k;
  vector<int>h(n);
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  vector<int>dp(n+1,-1);
 cout<<f(n-1,dp,h,k);
  return 0;
}


// //tabulation
// #include<bits/stdc++.h>
// using namespace std;


// int main(){
//   int n,k;
//   cin>>n>>k;
//   vector<int>h(n);
//   for(int i=0;i<n;i++){
//     cin>>h[i];
//   }
//   vector<int>dp(n+1,0);
//  dp[0]=0;

//  for(int j=1;j<n;j++){
//     int minSteps=INT_MAX;
//     for(int i=1;i<=k;i++){
//    if(j-i>=0){
//      int d=dp[j-i]+abs(h[j]-h[j-i]);
//      minSteps=min(minSteps,d);
   
//    }
     
//  }
//  dp[j]=minSteps;
//  }
//  cout<<dp[n-1];

//   return 0;
// }
