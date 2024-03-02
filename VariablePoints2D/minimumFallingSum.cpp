class Solution {
public:

    int minFallingPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=INT_MAX;
        vector<int>dp(n,0);
       for(int j=0;j<n;j++){
           dp[j]=grid[0][j];
       }
       for(int i=1;i<m;i++){
           vector<int>curr(n,0);
           for(int j=0;j<n;j++){
               int up=1e9,right=1e9,left=1e9;
               if(i-1>=0 && j-1>=0)left=grid[i][j]+dp[j-1];
               if(i-1>=0)up=grid[i][j]+dp[j];
               if(i-1>=0 && j+1<n)right=grid[i][j]+dp[j+1];
              curr[j]=min(left,min(up,right));
           }
           dp=curr;
       }
    for(int j=0;j<n;j++){
        ans=min(ans,dp[j]);
    }
    return ans;
    }
};