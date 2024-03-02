
int f(int i,vector<vector<int>>&dp,vector<int>&val,vector<int>&w,int W){
    if(i==0){
   
         int x=val[0];
         x*=(W/w[0]);
         return x;

    
    }
    if(dp[i][W]!=-1)return dp[i][W];
    int take=-1e9;
    int notTake=0+f(i-1,dp,val,w,W);
    if(W>=w[i])take=val[i]+f(i,dp,val,w,W-w[i]);
    return dp[i][W]=max(take,notTake);
}
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &w){
    // Write Your Code Here.

    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    return f(n-1,dp,val,w,W);
}

//tabulation
int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &w){
    // Write Your Code Here.

    vector<vector<int>>dp(n,vector<int>(W+1,-1));
    for(int i=0;i<=W;i++){
        dp[0][i]=(i/w[0])*val[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=W;j++){
            int take=-1e9;
            int notTake=0+dp[i-1][j];
            if(j>=w[i])take=val[i]+dp[i][j-w[i]];
            dp[i][j]=max(take,notTake);
        }
    }
    return dp[n-1][W];
}

//space opti.

int unboundedKnapsack(int n, int W, vector<int> &val, vector<int> &w){
    // Write Your Code Here.

    vector<int>dp(W+1,0);
    for(int i=0;i<=W;i++){
        dp[i]=(i/w[0])*val[0];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=W;j++){
            int take=-1e9;
            int notTake=0+dp[j];
            if(j>=w[i])take=val[i]+dp[j-w[i]];
            dp[j]=max(take,notTake);
        }
    }
    return dp[W];
}