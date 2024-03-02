int minSubsetSumDifference(vector<int>& arr, int n)
{  int target=0;
	   for(auto x :arr)target+=x;
         vector<vector<bool>>dp(n,vector<bool>(target+1,0));
    for(int i=0;i<n;i++)dp[i][0]=true;
    if(arr[0]<=target)dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int k=1;k<=target;k++){
            bool take=false;
            bool nonTake=dp[i-1][k];
             if(k>=arr[i])take=dp[i-1][k-arr[i]];
             dp[i][k]=take|nonTake;
        }
    }
        int ans=1e9;
        for(int i=0;i<=target/2;i++){
            if(dp[n-1][i]==true){
               
               ans=min(ans,abs((target-i)-i));
            }
        }
        return ans;
	// Write your code here.
}
