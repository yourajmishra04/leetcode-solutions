class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        set<int> st;
        for (int x : nums) {
            mp[x]++;
            st.insert(x);
        }
        vector<int>v;
        for(int x: st) v.push_back(x);
        sort(v.begin(),v.end());
        int i=0,n=v.size();
        while(i<n){
            int fre=mp[v[i]];
            mp[v[i]]=0;
            for(int j=i+1;j<i+k;j++){
                if( j>=n || mp[v[j]]<fre || v[j]!=v[j-1]+1  ) return 0;
                mp[v[j]]-=fre;
                
            }
            while(i<n && mp[v[i]]==0) i++;
        }
        return 1;
    }
};