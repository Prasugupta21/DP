

int lcs(string &s1, string &s2){
    // Write your code here.
    int n=s1.size(),m=s2.size(),ans=INT_MIN;
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=0;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
return ans;
}