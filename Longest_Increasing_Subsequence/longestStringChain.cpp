class Solution {
public:

bool isPossible(string &s1,string&s2){
    if(s1.size()!=s2.size()+1)return false;
    int i=0,j=0;
    while(i<s1.size()){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }
        else i++;
    }
    return i==s1.size() && j==s2.size();
}
static bool comp(string &s1,string&s2){
    return s1.size()<s2.size();
    }
    int longestStrChain(vector<string>& w) {
        sort(w.begin(),w.end(),comp);
         int maxi=0;
         int n=w.size();
      vector<int>dp(n,1);

       for(int i=0;i<n;i++){
         
           
           for(int prev=0;prev<i;prev++){
               if(isPossible(w[i],w[prev])){
                  
                  if(dp[i]<dp[prev]+1){
                      dp[i]=dp[prev]+1;
                     
                  }
                  
                  
               }
           }
          if(maxi<dp[i]){
              maxi=dp[i];
            
          }
          
       }
  
      return maxi;
    }
};


//print the longest string chain for this same approach as print LIS and 