class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
       

        vector<int> ans(n, INT_MAX);
        ans[src] = 0;
       
        for (int j = 0; j <= k; j++) {
           vector<int>temp=ans;
           for(auto &it : flights){
            int u= it[0] , v=it[1] , d= it[2];
            if(ans[u]==INT_MAX) continue;
             
             temp[v]=min(temp[v], d+ans[u]);
           }
           ans=temp;
        }

        if (ans[dst] == INT_MAX)
            return -1;
        return ans[dst];
    }
};