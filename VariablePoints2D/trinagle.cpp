
class Solution {
public:
int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&t){
    int n=t.size();
    if(i==n-1)return t[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
   int down=t[i][j]+f(i+1,j,dp,t);
   int diag=t[i][j]+f(i+1,j+1,dp,t);
   return dp[i][j]=min(down,diag);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,dp,triangle);
    }
};