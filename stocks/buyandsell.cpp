class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini=p[0],maxProfit=0;
        for(int i=1;i<p.size();i++){
            int profit=p[i]-mini;
            maxProfit=max(maxProfit,profit);
            mini=min(mini,p[i]);
        }
        return maxProfit;
    }
};