class Solution {
public:
vector<int> largestDivisibleSubset(vector<int>& nums) {
     int maxi=0,maxIdx=-1;
     int n=nums.size();
      vector<int>dp(n,1),hash(n,0);
      for(int i=0;i<n;i++)hash[i]=i;
       vector<int>v;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
         
           
           for(int prev=0;prev<i;prev++){
               if( nums[i]%nums[prev]==0){
                  
                  if(dp[i]<dp[prev]+1){
                      dp[i]=dp[prev]+1;
                      hash[i]=prev;
                  }
                  
                  
               }
           }
          if(maxi<dp[i]){
              maxi=dp[i];
              maxIdx=i;
          }
          
       }
       v.push_back(nums[maxIdx]);
while(hash[maxIdx]!=maxIdx){
    maxIdx=hash[maxIdx];
    v.push_back(nums[maxIdx]);
    
}
reverse(v.begin(),v.end());
return v;
    }
};