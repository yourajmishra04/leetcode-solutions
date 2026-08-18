class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int ta=target[0], tb=target[1];
        int n=drones.size();
        vector<int>ans(n, INT_MAX);
        for(int i=0;i<n;i++){
            int k= abs(ta-drones[i][0]) + abs(tb-drones[i][1]);
            if(k<=drones[i][2]) ans[i]=k;
        }
        int idx=0;
        int fans=ans[0];
        for(int i=1;i<n;i++){
            if (fans > ans[i]){
                idx=i;
                fans=ans[i];
            }
        }
        if(fans==INT_MAX) return -1;
        return idx;
    }
};