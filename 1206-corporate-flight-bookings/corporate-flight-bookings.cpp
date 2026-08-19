class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        vector<int>pre(n+2,0);
        for(auto it : bookings){
            pre[it[0]]+=it[2];
            pre[it[1]+1]-=it[2];
        }
        vector<int>ans(n);
        int tot=0;
        for(int i=0;i<n;i++){
            tot+=pre[i+1];
            ans[i]=tot;
        }
        return ans;
        
    }
};