long long f(int i,int j,bool isTrue,vector<vector<vector<int>>>&dp,string &exp){
    if(i>j)return 0;
    int mod=1000000007;
    if(i==j){
        if(isTrue)return exp[i]=='T';
        return exp[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
    long long ways=0;
    for(int k=i+1;k<=j-1;k+=2){
        long long lT=f(i,k-1,1,dp,exp);
        long long rT=f(k+1,j,1,dp,exp);
          long long lF=f(i,k-1,0,dp,exp);
          long long rF=f(k+1,j,0,dp,exp);
        if(exp[k]=='&'){
           if(isTrue) ways=(ways+((rT*lT)%mod))%mod;
           else ways=(ways+((lF*rT)%mod)+((lT*rF)%mod)+((lF*rF)%mod))%mod;
        }
        else if(exp[k]=='|'){
           if(isTrue) ways=(ways+((lT*rT)%mod)+((lT*rF)%mod)+((lF*rT)%mod))%mod;
           else ways=(ways+((rF*lF)%mod))%mod;
        }
        else{
           if(isTrue) ways=(ways+((lT*rF)%mod)+((lF*rT)%mod))%mod;
           else ways=(ways+((lT*rT)%mod)+((lF*rF)%mod))%mod;
        }
        
    }
    return dp[i][j][isTrue]=ways;
}

int evaluateExp(string & exp) {
    // Write your code here.
    int n=exp.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    return f(0,n-1,1,dp,exp);
}