class Solution {
public:
// int f(int i ,int j,string & s,string &t,  vector<vector<int>>&dp){
//     if (i<0)return j+1;
//     if(j<0)return i+1;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(s[i]==t[j])return dp[i][j]=0+f(i-1,j-1,s,t,dp);
//     int insert=1+f(i,j-1,s,t,dp);
//     int del=1+f(i-1,j,s,t,dp);//delete
//     int replace=1+f(i-1,j-1,s,t,dp);
//     return dp[i][j]=min(insert,min(del,replace));
// }
    int minDistance(string s, string t) {
        int n=s.size(),m=t.size();
     vector<int>dp(m+1,0),curr(m+1,0);
     for(int j=0;j<=m;j++)dp[j]=j;
     
     for(int i=1;i<=n;i++){
curr[0]=i;
         for(int j=1;j<=m;j++){
             if(s[i-1]==t[j-1])curr[j]=dp[j-1];
             else{
                 int insert=1+curr[j-1],del=1+dp[j],replace=1+dp[j-1];
                 curr[j]=min(insert,min(del,replace));
             }
         }
         dp=curr;
     }

     return dp[m];
    }
};