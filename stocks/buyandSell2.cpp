class Solution
{
public:
    int f(int i, int buy, vector<int> &p, vector<vector<int>> &dp)
    {
        if (i == p.size())
            return 0;
        if (dp[i][buy] != -1)
            return dp[i][buy];
        int maxProfit;
        if (buy)
        {
            int take = -p[i] + f(i + 1, 0, p, dp);
            int notTake = 0 + f(i + 1, 1, p, dp);
            maxProfit = max(take, notTake);
        }
        else
        {
            int take = p[i] + f(i + 1, 1, p, dp);
            int notTake = 0 + f(i + 1, 0, p, dp);
            maxProfit = max(take, notTake);
        }
        return dp[i][buy] = maxProfit;
    }
    int maxProfit(vector<int> &p)
    {
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, p, dp);
    }
};

//tabulation
class Solution {
public:

    int maxProfit(vector<int>& Arr) {
        int n=Arr.size();
        vector<vector<long>>dp(n+1,vector<long>(2,-1));
        dp[n][0]=0;
        dp[n][1]=0;
        long profit;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==0){
                    dp[i][j]=max(0+dp[i+1][j],Arr[i]+dp[i+1][!j]);
                }
                else{
                    dp[i][j]=max(0+dp[i+1][j],-Arr[i]+dp[i+1][!j]);
                }
            }
        }
      return dp[0][1];
    }
};

//space
class Solution {
public:

    int maxProfit(vector<int>& Arr) {
        int n=Arr.size();
        vector<long>dp(2,0),curr(2,0);
        dp[0]=0;
        dp[1]=0;
        
        long profit;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==0){
                    curr[j]=max(0+dp[j],Arr[i]+dp[!j]);
                }
                else{
                    curr[j]=max(0+dp[j],-Arr[i]+dp[!j]);
                }
            }
            dp=curr;
        }
      return dp[1];
    }
};

//similar problem sell stock cooldown