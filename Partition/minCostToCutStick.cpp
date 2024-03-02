class Solution {
public:
int f(int i,int j,  vector<vector<int>>&dp,vector<int>&cuts){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=1e9;
    for(int k=i;k<=j;k++){
        int cost=cuts[j+1]-cuts[i-1]+f(i,k-1,dp,cuts)+f(k+1,j,dp,cuts);
        mini=min(mini,cost);
    }
    return dp[i][j]=mini;
}
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
      for(int i=c;i>=1;i--){
          for(int j=i;j<=c;j++){
              int mini=1e9;
              for(int k=i;k<=j;k++){
                   int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
        mini=min(mini,cost);
              }
              dp[i][j]=mini;
          }
      }
      return dp[1][c];
    }
};