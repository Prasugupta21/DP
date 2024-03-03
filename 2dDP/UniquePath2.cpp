class Solution {
public:
int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&o){
    if(i<0 || j<0)return 0;
    if(o[i][j]==1)return 0;
    if(i==0 && j==0){
        return 1;
        }
    
    if(dp[i][j]!=-1)return dp[i][j];
    int left=f(i,j-1,dp,o);
    int up=f(i-1,j,dp,o);
    return dp[i][j]=left+up;
}
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o[0].size(),m=o.size();
           vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,o);
    }
};
//tabulation


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n=o[0].size(),m=o.size();
           vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        if(o[0][0]==1 || o[m-1][n-1]==1)return 0;
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(i==0 && j==0)continue;
                 if(o[i][j]==1){
                     dp[i][j]=0;
                     continue;
                 }
                 int left=0,up=0;
                 if(j>0)
                  left=dp[i][j-1];
                 if(i>0)
                 up=dp[i-1][j];
                 dp[i][j]=left+up;
             }
         }
        return dp[m-1][n-1];
    }
};
//tabulation
