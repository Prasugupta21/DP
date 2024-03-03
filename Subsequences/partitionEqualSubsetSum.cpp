class Solution {
public:
bool f(int i, int target, vector<vector<int>> &dp, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (i == 0)
        return arr[0] == target;
    if (dp[i][target] != -1)
        return dp[i][target];
    bool nonTake = f(i - 1, target, dp, arr);
    bool take = false;
    if (target >= arr[i])
        take = f(i - 1, target - arr[i], dp, arr);
    return dp[i][target] = take || nonTake;
}
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto x :nums)sum+=x;
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return f(n - 1, target, dp, nums);
    }
};