class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos,neg;
        for(auto it:nums){
            if(it>0)pos.push_back(it);
            else neg.push_back(it);
        }
        vector<int> ans;
        int i=0;
        while(i<neg.size()){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }
};