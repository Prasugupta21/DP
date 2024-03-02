class Solution {
public:
int f(int i, int buy,vector<vector<vector<int>>>&dp,vector<int>&p,int cap){
    int n=p.size();
    if(i==n || cap==0)return 0;
    if(dp[i][buy][cap]!=-1)return  dp[i][buy][cap];
    int maxProfit=0;
    if(buy){
        int take=-p[i]+f(i+1,0,dp,p,cap);
        int notTake=0+f(i+1,1,dp,p,cap);
        maxProfit=max(take,notTake);
    }
    else{
              int take=p[i]+f(i+1,1,dp,p,cap-1);
        int notTake=0+f(i+1,0,dp,p,cap);
        maxProfit=max(take,notTake);

    }
    return dp[i][buy][cap]=maxProfit;
}
    int maxProfit(vector<int>& p) {

        int n=p.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,dp,p,2);
    }
};