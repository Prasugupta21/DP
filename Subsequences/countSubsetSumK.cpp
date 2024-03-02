//for nums[i] starting from 1

int solve(int idx,vector<int>& nums,int target,vector<vector<int>>& dp){
    if(target==0) return 1;
    if(idx==0){
        return nums[0]==target;
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int notTake=solve(idx-1,nums,target,dp);
    int take=0;
    if(nums[idx]<=target){
        take=solve(idx-1,nums,target-nums[idx],dp);
    }
    return dp[idx][target]=(take+notTake)%1000000007;
    
}

int findWays(vector<int>& arr, int k)
{      int MOD=1000000007;
	// Write your code here.
	    int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        int ans=solve(n-1,arr,k,dp);
       

       return ans%MOD;
}

//tabulation  for elements starting 1

int findWays(vector<int>& arr, int target)
{      
    int MOD=1000000007;
	// Write your code here.
	    int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        

               for(int i=0;i<n;i++){
            dp[i][0]=1;
        
    }
       
    
   if(arr[0]<=target)dp[0][arr[0]]=1;
   
  
   
    for(int i=1;i<n;i++){
        for (int k = 1; k <= target; k++) {
            int take = 0;
            int nonTake = dp[i - 1][k];
            if (k >= arr[i])
              take = dp[i - 1][k - arr[i]];
            dp[i][k] = (take + nonTake)%MOD;
        }
    }
        return dp[n-1][target]%MOD;
    }



////for nums[i] starting from 0







// remove    if(target==0) return 1;
// // modification on base case 



// if(idx==0){
//         if(target==0 && nums[0]==0)return 2;
//         if(target==0 || target==nums[0])return 1;
//         return 0;
//     }


..

int findWays(vector<int>& arr, int target)
{      
    int MOD=1000000007;
	// Write your code here.
	    int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        
if(arr[0]==0)dp[0][0]=2;
else dp[0][0]=1;

if(arr[0]!=0 && arr[0]<=target)dp[0][arr[0]]=1;        
        
 for(int i=1;i<n;i++){
      for (int k = 0; k <= target; k++) {
            int take = 0;
            int nonTake = dp[i - 1][k];
            if (k >= arr[i])
              take = dp[i - 1][k - arr[i]];

            dp[i][k] = (take + nonTake)%MOD;
        }
    }
        return dp[n-1][target]%MOD;
    }


    //space 

    

int findWays(vector<int>& arr, int target)
{      
    int MOD=1000000007;
	// Write your code here.
	    int n=arr.size();
        vector<int>dp(target+1,0);
        
        
if(arr[0]==0)dp[0]=2;
else dp[0]=1;

if(arr[0]!=0 && arr[0]<=target)dp[arr[0]]=1;        
        
 for(int i=1;i<n;i++){
     vector<int>curr(target+1,0);
      for (int k = 0; k <= target; k++) {
            int take = 0;
            int nonTake = dp[k];
            if (k >= arr[i])
              take = dp[k - arr[i]];

            curr[k] = (take + nonTake)%MOD;
        }
        dp=curr;
    }
        return dp[target]%MOD;
    }