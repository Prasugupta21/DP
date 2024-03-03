class Solution {
public:
int f(int i,int j1,int j2,vector<vector<vector<int>>>&dp,vector<vector<int>>& grid){
    int n=grid[0].size(),m=grid.size();
    if(j1<0 || j1 >=n || j2<0 || j2>=n)return -1e9;
    if(i==m-1){
        if(j1==j2)return grid[i][j1];
        return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi=-1e9;
    for(int dr=-1;dr<=1;dr++){
        for(int dc=-1;dc<=1;dc++){
            if(j1==j2){
                int l=grid[i][j1]+f(i+1,j1+dr,j2+dc,dp,grid);
                maxi=max(maxi,l);

            }
            else{
                 int l=grid[i][j1]+grid[i][j2]+f(i+1,j1+dr,j2+dc,dp,grid);
                maxi=max(maxi,l);
            }
        }
    }
    return dp[i][j1][j2]=maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
       for(int j=0;j<n;j++){
           for(int k=0;k<n;k++){
               if(j==k)dp[m-1][j][k]=grid[m-1][k];
               else dp[m-1][j][k]=grid[m-1][j]+grid[m-1][k];
           }
       }
       for(int i=m-2;i>=0;i--){
           for(int j1=0;j1<n;j1++){
               for(int j2=0;j2<n;j2++){
                   int maxi=-1e9;
                   for(int dr=-1;dr<=1;dr++){
                       int val;
                       for(int dc=-1;dc<=1;dc++){
                           if(j1+dr>=0 && j1+dr<n && j2+dc<n && j2+dc>=0){
                             
                               if(j1==j2)val=grid[i][j1]+dp[i+1][j1+dr][j2+dc];
                               else val=dp[i+1][j1+dr][j2+dc]+grid[i][j1]+grid[i][j2];
                                   maxi=max(maxi,val);
                              
                           }
              
                       }
                   }
                   dp[i][j1][j2]=maxi;
                   
               }
           }
       }
       return dp[0][0][n-1];
    }
};

//space
class Solution {
public:

    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(n,0));
       for(int j=0;j<n;j++){
           for(int k=0;k<n;k++){
               if(j==k)dp[j][k]=grid[m-1][k];
               else dp[j][k]=grid[m-1][j]+grid[m-1][k];
           }
       }
       for(int i=m-2;i>=0;i--){
           vector<vector<int>>curr(n,vector<int>(n,0));
           for(int j1=0;j1<n;j1++){
               for(int j2=0;j2<n;j2++){
                   int maxi=-1e9;
                   for(int dr=-1;dr<=1;dr++){
                       int val;
                       for(int dc=-1;dc<=1;dc++){
                           if(j1+dr>=0 && j1+dr<n && j2+dc<n && j2+dc>=0){
                             
                               if(j1==j2)val=grid[i][j1]+dp[j1+dr][j2+dc];
                               else val=dp[j1+dr][j2+dc]+grid[i][j1]+grid[i][j2];
                                   maxi=max(maxi,val);
                              
                           }
              
                       }
                   }
                   curr[j1][j2]=maxi;
                   
               }
           }
           dp=curr;
       }
       return dp[0][n-1];
    }
};