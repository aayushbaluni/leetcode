class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        map<int,vector<char>> mp1;
        for(auto it:s)mp[it]++;
        for(auto it:mp){
            mp1[it.second].push_back(it.first);
        }
        string ans="";
        for(auto it:mp1){
            for(auto i:it.second){
                for(int j=0;j<it.first;j++){
                    ans+=i;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};