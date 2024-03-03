class Solution {
public:
int f(int i,vector<vector<int>>&dp,int target,vector<int>&c){
    if(i==0){
        if(target%c[i]==0)return 1;
        return 0;
    }
    if(dp[i][target]!=-1)return dp[i][target];
    int notTake=f(i-1,dp,target,c);
    int take=0;
    if(target>=c[i])take=f(i,dp,target-c[i],c);
    return dp[i][target]=take+notTake;
}
    int change(int target, vector<int>& c) {
        int n=c.size();
    vector<vector<int>>dp(n,vector<int>(target+1,0));
    for(int j=0;j<=target;j++){
        if(j%c[0]==0)dp[0][j]=1;
        else dp[0][j]=0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int take=0;
            int notTake=dp[i-1][j];
            if(j>=c[i])take=dp[i][j-c[i]];
            dp[i][j]=take+notTake;
        }

    }
    return    (dp[n-1][target]==0)?0:dp[n-1][target];
    }
};