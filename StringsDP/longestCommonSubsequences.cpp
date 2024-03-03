class Solution {
public:
int f(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(t1[i]==t2[j])return dp[i][j]= 1+f(i-1,j-1,t1,t2,dp);
    return dp[i][j]=max(f(i-1,j,t1,t2,dp),f(i,j-1,t1,t2,dp));
}
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(),m=t2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,t1,t2,dp);
    }
};


//tabulation

 int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(),m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    //space
     int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(),m=t2.size();
     vector<int>dp(m+1,0),curr(m+1,0);
        
        for(int j=0;j<=m;j++)dp[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])curr[j]=1+dp[j-1];
                else curr[j]=max(dp[j],curr[j-1]);
            }
            dp=curr;
        }
        return dp[m];
    }

2.// longest palindrome subsequence 

// given string t just reverse string t reversed string is s and call lcs(s,t)

//3.Min insertion to make string palindrome
class Solution {
public:
int f(int i,int j,string &t1,string &t2,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(t1[i]==t2[j])return dp[i][j]= 1+f(i-1,j-1,t1,t2,dp);
    return dp[i][j]=max(f(i-1,j,t1,t2,dp),f(i,j-1,t1,t2,dp));
}
    int minInsertions(string s) {
    string t=s;
    reverse(s.begin(),s.end());
          int n=t.size(),m=s.size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
        int l= f(n-1,m-1,t,s,dp);
        return n-l;
    }
};



///4 Min operation(insertion/deletion) to convert string a to b
int canYouMake(string &t1, string &t2){
    // Write your code here.
      int n=t1.size(),m=t2.size();
     vector<int>dp(m+1,0),curr(m+1,0);
        
        for(int j=0;j<=m;j++)dp[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])curr[j]=1+dp[j-1];
                else curr[j]=max(dp[j],curr[j-1]);
            }
            dp=curr;
        }
        int lcs=dp[m];
        return n+m-(2*lcs);
}