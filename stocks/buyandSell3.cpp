class Solution
{
public:
    int f(int i, int buy, vector<vector<vector<int>>> &dp, vector<int> &p, int cap)
    {
        int n = p.size();
        if (i == n || cap == 0)
            return 0;
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        int maxProfit = 0;
        if (buy)
        {
            int take = -p[i] + f(i + 1, 0, dp, p, cap);
            int notTake = 0 + f(i + 1, 1, dp, p, cap);
            maxProfit = max(take, notTake);
        }
        else
        {
            int take = p[i] + f(i + 1, 1, dp, p, cap - 1);
            int notTake = 0 + f(i + 1, 0, dp, p, cap);
            maxProfit = max(take, notTake);
        }
        return dp[i][buy][cap] = maxProfit;
    }
    int maxProfit(vector<int> &p)
    {

        int n = p.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, dp, p, 2);
    }
};

// tabulation
class Solution
{
public:
    int maxProfit(vector<int> &p)
    {

        int n = p.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 1; j >= 0; j--)
            {

                for (int k = 2; k >= 1; k--)
                {
                    if (j)
                    {
                        int take = -p[i] + dp[i + 1][!j][k];
                        int notTake = 0 + dp[i + 1][j][k];
                        dp[i][j][k] = max(take, notTake);
                    }
                    else
                    {
                        int take = p[i] + dp[i + 1][!j][k - 1];
                        int notTake = 0 + dp[i + 1][j][k];
                        dp[i][j][k] = max(take, notTake);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
//space
  int maxProfit(vector<int>& p) {

        int n=p.size();
        vector<vector<int>>dp(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
       
       for(int i=n-1;i>=0;i--){
           for(int j=1;j>=0;j--){
              
               for(int k=2;k>=1;k--){
                   if(j){
                       int take=-p[i]+dp[!j][k];
        int notTake=0+dp[j][k];
    curr[j][k]=max(take,notTake);
       
                   }
                   else{
  int take=p[i]+dp[!j][k-1];
        int notTake=0+dp[j][k];
        curr[j][k]=max(take,notTake);
                   }
               }
           }
           dp=curr;
       }
       return dp[1][2];

// Alternate
class Solution
{
public:
    int f(int i, int trans, vector<vector<int>> &dp, vector<int> &p)
    {
        int n = p.size();
        if (i == n || trans == 4)
            return 0;
        if (dp[i][trans] != -1)
            return dp[i][trans];
        int maxProfit = 0;
        if (trans % 2 == 0)
        {
            int take = -p[i] + f(i + 1, trans + 1, dp, p);
            int notTake = 0 + f(i + 1, trans, dp, p);
            maxProfit = max(take, notTake);
        }
        else
        {
            int take = p[i] + f(i + 1, trans + 1, dp, p);
            int notTake = 0 + f(i + 1, trans, dp, p);
            maxProfit = max(take, notTake);
        }
        return dp[i][trans] = maxProfit;
    }
    int maxProfit(vector<int> &p)
    {

        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return f(0, 0, dp, p);
    }
};