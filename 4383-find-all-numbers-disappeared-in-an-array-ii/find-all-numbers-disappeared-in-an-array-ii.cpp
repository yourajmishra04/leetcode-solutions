class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>ans;
           set<int>st;
           for(int x : nums) st.insert(x);
           while(lower<=upper){
            vector<int>v;
              while(lower<=upper && st.find(lower)==st.end()){
                v.push_back(lower);
                lower++;
              }
              if(!v.empty())
              ans.push_back(v);
              lower++;
           }
           int n=ans.size();
           vector<vector<int>>fans(n);
           for(int i=0;i<n;i++){
            fans[i].push_back(ans[i][0]);
            fans[i].push_back(ans[i].back());
           }
           return fans;
    }
};