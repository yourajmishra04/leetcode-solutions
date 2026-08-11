class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        int i=0 ,n = s.size() , j;
       
        while(i<n){
             string temp="";
            while(i<n && s[i]==' ')i++;
             j=i;
             while(j<n && s[j]!=' ') {
                temp+=s[j];
                j++;
             }
             if(temp.size()>0)
              v.push_back(temp);
             i=j;
        }
        reverse(v.begin(), v.end());
        string ans="";
        ans+=v[0];
        for(int i=1;i<v.size();i++){
            ans+=" ";
            ans+=v[i];
        }
        return ans;
    }
};