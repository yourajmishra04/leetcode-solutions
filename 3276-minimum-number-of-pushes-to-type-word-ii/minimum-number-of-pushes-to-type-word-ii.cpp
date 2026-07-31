class Solution {
public:
    int minimumPushes(string word) {
       map<char,int>mp;
       for(auto x : word) mp[x]++;
       vector<int>v;
       for(auto it : mp){
         v.push_back(it.second);
       }
       sort(v.rbegin(),v.rend());
       int ans=0, n=v.size();

       for(int i=0;i<n;i++){
        int k=i/8;
         k++;
         ans+=( k*(v[i]));
          
       }
       return ans;
    }
};