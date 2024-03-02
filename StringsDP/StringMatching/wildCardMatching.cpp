Wildcard Matching

class Solution {
public:
// bool f(int i,int j,string s,string p, vector<vector<int>>&dp){
//     if(i<0 && j<0)return true;
//     if(i<0 && j>=0)return false;
//     if(i>=0 && j<0){
//         for(int k=0;k<=i;k++){
//             if(s[k]!='*')return false;
//         }
//         return true;
//     }
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(s[i]==p[j] || s[i]=='?')return dp[i][j]=f(i-1,j-1,s,p,dp);
//     if(s[i]=='*') return dp[i][j]=f(i-1,j,s,p,dp) | f(i,j-1,s,p,dp);
//     return dp[i][j]=false;

// }
    bool isMatch(string s, string p) {
        int n=p.size(),m=s.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            int flag=1;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    flag=0;
                    break;
                }

            }
            if(flag)dp[i][0]=1;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1]==s[j-1] || p[i-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(p[i-1]=='*')dp[i][j]=dp[i-1][j]  | dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[n][m];
    }
};