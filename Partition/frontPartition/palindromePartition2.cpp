class Solution {
public:
int dp[2001];
bool isPalindrome(string &s,int i,int j){
    
    while(i<j){
        if(s[i++]!=s[j--])return false;
    }
    return true;
}

int f(int i,string &s,int dp[]){
    int n=s.size();
    if(i==n)return 0;
    if(dp[i]!=-1)return dp[i];
    int cuts=1e9;
    for(int k=i;k<n;k++){
        if(isPalindrome(s,i,k)){
           int x=1+f(k+1,s,dp);
            cuts=min(cuts,x);
        }
    }
   
    return dp[i]=cuts;

}
    int minCut(string s) {
        int n=s.size();
      
      memset(dp,-1,sizeof(dp));
        
        int x=f(0,s,dp);
        return x-1;
    }
};