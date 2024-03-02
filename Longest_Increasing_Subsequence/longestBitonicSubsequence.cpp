int longestBitonicSubsequence(vector<int>& nums, int n)
{
	  int maxi=0;
    
      vector<int>dp(n,1),dp2(n,1);
      
       
      
       for(int i=0;i<n;i++){
         
           
           for(int prev=0;prev<i;prev++){
               if( nums[i]>nums[prev]){
                  
                  if(dp[i]<dp[prev]+1){
                      dp[i]=dp[prev]+1;
                      
                  }
                  
                  
               }
           }
        
          
       }
	   for(int i=n-1;i>=0;i--){
		   for(int next=n-1;next>i;next--){
			   if(nums[i]>nums[next] && dp2[i]<dp2[next]+1){
				   dp2[i]=dp2[next]+1;
			   }
		   }
	   }
	   for(int i=0;i<n;i++){
		   int x=dp[i]+dp2[i]-1;
		   maxi=max(maxi,x);
	   }
	   return maxi;
	
	// Write your code here.
}
