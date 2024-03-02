class Solution {
public:
int f(int i, int trans,int k,vector<vector<int>>&dp,vector<int>&p){
    int n=p.size();
    if(i==n || trans==2*k)return 0;
    if(dp[i][trans]!=-1)return  dp[i][trans];
    int maxProfit=0;
    if(trans%2==0){
        int take=-p[i]+f(i+1,trans+1,k,dp,p);
        int notTake=0+f(i+1,trans,k,dp,p);
        maxProfit=max(take,notTake);
    }
    else{
              int take=p[i]+f(i+1,trans+1,k,dp,p);
        int notTake=0+f(i+1,trans,k,dp,p);
        maxProfit=max(take,notTake);

    }
    return dp[i][trans]=maxProfit;
}
    int maxProfit(int k,vector<int>& p) {

        int n=p.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
       
      return f(0,0,k,dp,p);
    }
};