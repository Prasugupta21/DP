class Solution {
public:
int f(int i,vector<int>&nums,int target){
    if(i==nums.size()){
        
        if(target==0)return 1;
      return 0;


    }
    
    int pos=f(i+1,nums,target-nums[i]);
    int neg=f(i+1,nums,target+nums[i]);
    return pos+neg;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
       
        return f(0,nums,target);
    }
};

//


class Solution {
public:
int solve(int idx,vector<int>& nums,int target,vector<vector<int>>& dp){
    if(idx==0){
        if(target==0 && nums[0]==0)return 2;
        if(target==0 || target==nums[0])return 1;
        return 0;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int notTake=solve(idx-1,nums,target,dp);
    int take=0;
    if(nums[idx]<=target){
        take=solve(idx-1,nums,target-nums[idx],dp);
    }
    return dp[idx][target]=(take+notTake);
    
}

int findWays(vector<int>& arr, int k)
{      int MOD=1000000007;
	// Write your code here.
	    int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int ans=solve(n-1,arr,k,dp);
       

       return ans;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
     int sum=0;
	  for(auto x :arr)sum+=x;
        int target=(sum-d)/2;
        if(target<0 || (sum-d)%2)return 0;
         return findWays(arr, target);
        
        
}

int f(int i,  vector<vector<int>>&dp,vector<int>&nums,int target){
    if(i==nums.size()){
        
        if(target==0)return 1;
      return 0;


    }
    if(dp[i][target+1001]!=INT_MAX)return dp[i][target+1001];
    int pos=f(i+1,dp,nums,target-nums[i]);
    int neg=f(i+1,dp,nums,target+nums[i]);
    return dp[i][target+1001]=pos+neg;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return countPartitions(nums.size(),target,nums);
    }
};