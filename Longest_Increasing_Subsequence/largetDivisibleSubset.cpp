//MEMORY LIMIT EXCEDED

class Solution {
public:
void f(int i,vector<int>& nums,vector<int>& ans,vector<int>temp){
    if(i==0){
        if(temp.size()==0)temp.push_back(nums[i]);
        else {
            int flag=1;
            for(auto x :temp){
                if(!(x%nums[i]==0 || nums[i]%x==0)){flag=0;break;}
            }
            if(flag)temp.push_back(nums[0]);
        }
        if(temp.size()>ans.size())ans=temp;
        return;

    }
    f(i-1,nums,ans,temp);
    if(temp.size()==0)temp.push_back(nums[i]);
    else {
        int flag=1;
            for(auto x :temp){
                if(!(x%nums[i]==0 || nums[i]%x==0)){flag=0;break;}
            }
            if(flag)temp.push_back(nums[i]);
    }
    f(i-1,nums,ans,temp);
}
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans,temp;
        int n=nums.size();
        f(n-1,nums,ans,temp);
        return ans;
    }
};

//accepted

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