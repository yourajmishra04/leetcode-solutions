class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, curr=prices[0] , n=prices.size();

        for(int i=1;i<n;i++)
        {
           if(prices[i]>curr){
                 profit+=curr-prices[i];
                 curr=prices[i];
           }
           else{
             curr=prices[i];
           }
        }
        return -profit;
    }
};