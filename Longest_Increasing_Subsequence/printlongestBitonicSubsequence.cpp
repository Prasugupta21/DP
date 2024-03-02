 #include<bits/stdc++.h>
 using namespace std;

 void f(vector<int>&nums,int n){
 int maxi=0,maxIdx=-1;
    
      vector<int>dp(n,1),dp2(n,1),hash(n),hash2(n);
	  
      
       
      
       for(int i=0;i<n;i++){
         hash[i]=i;
           
           for(int prev=0;prev<i;prev++){
               if( nums[i]>nums[prev]){
                  
                  if(dp[i]<dp[prev]+1){
                      dp[i]=dp[prev]+1;
					  hash[i]=prev;
                      
                  }
                  
                  
               }
           }
        
          
       }
	   for(int i=n-1;i>=0;i--){
		   hash2[i]=i;
		   for(int next=n-1;next>i;next--){
			   if(nums[i]>nums[next] && dp2[i]<dp2[next]+1){
				   dp2[i]=dp2[next]+1;
				   hash2[i]=next;
			   }
		   }
	   }
	   for(int i=0;i<n;i++){
		   int x=dp[i]+dp2[i]-1;
		 if(x>maxi){
			 maxi=x;
			 maxIdx=i;
		 }
	   }
	   vector<int>v;
	   int idx=maxIdx;
	   v.push_back(nums[maxIdx]);
	   while(hash[maxIdx]!=maxIdx){
		   maxIdx=hash[maxIdx];
		   v.push_back(nums[maxIdx]);
	   }
	   reverse(v.begin(),v.end());
	   
	   while(hash2[idx]!=idx){
		   idx=hash2[idx];
		   v.push_back(nums[idx]);
	   }
	   for(auto x :v)cout<<x<<" ";
 }

 int main(){
    vector<int>x={1,11,2,10,4,5,2,1};
    f(x,5);
    return 0;
 }