class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>v(1003,0);
        for(auto it : trips){
               v[it[1]]+=it[0];
               v[it[2]]-=it[0];

        }

        int tot=0;
        for(int i=0;i<v.size() ;i++ ){
            tot+=v[i];
            if(tot>capacity) return 0;
        }

        return 1;
    }
};