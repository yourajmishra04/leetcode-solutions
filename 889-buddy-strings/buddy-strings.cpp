class Solution {
public:
    bool buddyStrings(string s, string goal) {
       vector<pair<int,char>>v;
       map<char,int>mp;
        int n=s.size(), m=goal.size();
        if(m!=n) return 0;

        for(int i=0;i<n;i++){
            mp[s[i]]++;

            if(s[i]!=goal[i]) v.push_back({i,s[i]});
        } 
     
             

        if(  v.size()==2 && v[0].second== goal[v[1].first] && v[1].second== goal[v[0].first]  ) return 1;
         if(v.size()==0){
            for(auto it : mp) if(it.second >=2) return 1;
         }
         return 0;
    }
};