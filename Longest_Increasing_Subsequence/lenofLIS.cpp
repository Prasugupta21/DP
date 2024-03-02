class Solution {
public:
int f(int i,int prev, vector<vector<int>>&dp,vector<int>&v){
    if(i==v.size())return 0;
    if(dp[i][prev]!=-1)return dp[i][prev];
    int l=0+f(i+1,prev,dp,v);
    int len=0;
    if(prev==0 || v[i]>v[prev-1])len=1+f(i+1,i+1,dp,v);
    return dp[i][prev]=max(l,len);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,0,dp,nums);
    }
};


