class Solution {
public:
    int countSquares(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)dp[i][0]=grid[i][0];
        for(int j=0;j<n;j++)dp[0][j]=grid[0][j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)ans+=dp[i][j];
        }
        return ans;
    }
};