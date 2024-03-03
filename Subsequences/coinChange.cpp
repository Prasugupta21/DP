class Solution {
public:
int f(int i,vector<vector<int>>&dp,int target,vector<int>&c){
    if(i==0){
        if(target%c[i]==0)return target/c[i];
        return 1e9;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notTake=0+f(i-1,dp,target,c);
    int take=INT_MAX;
    if(target>=c[i])take=1+f(i,dp,target-c[i],c);
    return dp[i][target]=min(take,notTake);
}
    int coinChange(vector<int>& c, int target) {
        int n=c.size();
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return  (f(n-1,dp,target,c)>=1e9)?-1:f(n-1,dp,target,c);
    }
};