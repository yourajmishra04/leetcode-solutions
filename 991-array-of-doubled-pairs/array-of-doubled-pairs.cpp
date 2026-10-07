class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n= arr.size();
       map<int,int>mp;
       sort(arr.begin(),arr.end());
       for(int x : arr) mp[x]++;
       for(int i=0;i<n;i++){
        int num=arr[i];
        if(mp[num]<=0) continue;
        if(mp[2*num]>0){
             mp[num]--;
             mp[2*num]--;
        }
        else if(num%2==0  && mp[num/2]>0){
               mp[num]--;
               mp[num/2]--;
        }
       }
       for(auto it : mp) if(it.second>0) return 0;
       return 1;
    }
};