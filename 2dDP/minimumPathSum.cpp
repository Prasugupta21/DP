class Solution {
public:
int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
    if(i==0 && j==0)return grid[i][j];
    if(i<0 || j<0)return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    long long left=grid[i][j]+(long long)f(i,j-1,dp,grid);
    long long up=grid[i][j]+(long long)f(i-1,j,dp,grid);
    return dp[i][j]=min(left,up);
}
    int minPathSum(vector<vector<int>>& grid) {
   

    int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
  
    }
};

//tabulation
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
   

    int m=grid.size(),n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(i==0 && j==0)continue;
                 int left=INT_MAX,up=INT_MAX;
                 if(j>0)
                  left=grid[i][j]+dp[i][j-1];
                 if(i>0)
                 up=grid[i][j]+dp[i-1][j];
                 dp[i][j]=min((int)left,(int)up);
             }
         }
        return dp[m-1][n-1];
  
    }
};

//space
class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
   

    int m=grid.size(),n=grid[0].size();
   
    vector<int>dp(n,0);
       
         for(int i=0;i<m;i++){
             vector<int>temp(n,0);
             for(int j=0;j<n;j++){
                 if(i==0 && j==0)temp[j]=grid[0][0];
                 else{
  int left=INT_MAX,up=INT_MAX;
                 if(j>0)
                  left=grid[i][j]+temp[j-1];
                
                if(i>0) up=grid[i][j]+dp[j];
                 temp[j]=min((int)left,(int)up);
                 }
               
             }
             dp=temp;
         }   
         
         return dp[n-1];
     
  
    }
};