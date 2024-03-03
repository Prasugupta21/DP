class Solution {
public:

int f(int i,vector<int>&dp,vector<int>&nums){
    if(i==0){
        return nums[i];
    }
     if(i<0)return 0;
     if(dp[i]!=-1)return dp[i];
     
     int pick=nums[i]+f(i-2,dp,nums);
   
     int notPick=0+f(i-1,dp,nums);
     return dp[i]=max(pick,notPick);
}
int f2(int i,vector<int>&dp,vector<int>&nums){
    int n=nums.size();
    if(i==nums.size()-1){
        return nums[i];
    }
     if(i>=n)return 0;
     if(dp[i]!=-1)return dp[i];
     
     int pick=nums[i]+f2(i+2,dp,nums);
   
     int notPick=0+f2(i+1,dp,nums);
     return dp[i]=max(pick,notPick);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        bool  taken=false;
        if(n==1)return nums[0];
        
        vector<int>dp(n,-1);
        int ans1=f(n-2,dp,nums);
        for(int i=0;i<n;i++)dp[i]=-1;
        int ans2=f2(1,dp,nums);
        return max(ans1,ans2);
    }
};