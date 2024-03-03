class Solution {
public:
int f(int i,int prev, vector<vector<int>>&dp,vector<int>&v){
    if(i==v.size())return 0;
    if(dp[i][prev]!=-1)return dp[i][prev];
    int l=0+f(i+1,prev,dp,v);
    int len=0;
    if(prev==0 || v[i]>v[prev-1])len=1+f(i+1,i+1,dp,v);
    return dp[i][prev]=max(l,len);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,0,dp,nums);
    }
};


//binary Search

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(),len=1;
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
            temp[idx]=nums[i];
            }
        }

       return len;
    }
};