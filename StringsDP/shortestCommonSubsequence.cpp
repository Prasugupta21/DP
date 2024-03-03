class Solution {
public:
    string shortestCommonSupersequence(string t1, string t2) {
        int n=t1.size(),m=t2.size();
   
        
         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++)dp[i][0]=0;
        for(int j=0;j<=m;j++)dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(t1[i-1]==t2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int lcs= dp[n][m];
        int l=n+m-lcs;
        int i=n,j=m;
        string ans;
        while(i>0 && j>0){
            if(t1[i-1]==t2[j-1]){
               ans=t2[j-1]+ans;
               i--;
               j--;


            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans=t1[i-1]+ans;
                i--;
            }
            else{
                ans=t2[j-1]+ans;
                j--;
            }
        }
        while(i>0){ans=t1[i-1]+ans;i--;}
        while(j>0){ans=t2[j-1]+ans;j--;}
return ans;
    }
};