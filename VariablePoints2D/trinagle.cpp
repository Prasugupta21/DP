
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

//tabulation
class Solution {
public:

    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[n-1][j]=t[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=t[i][j]+dp[i+1][j];
                int diag=t[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};

//space
class Solution {
public:

    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size();
       vector<int>front(n,0);
        for(int j=0;j<n;j++){
            front[j]=t[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int>curr(n,0);
            for(int j=i;j>=0;j--){
                int down=t[i][j]+front[j];
                int diag=t[i][j]+front[j+1];
                curr[j]=min(down,diag);
            }
            front=curr;
        }
        return front[0];
    }
};
