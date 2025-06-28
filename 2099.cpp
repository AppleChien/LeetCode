class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>val;
        for(int i=0;i<n;i++)val.push_back({i,nums[i]});

        sort(val.begin(),val.end(),[&](auto x1,auto x2){
            return x1.second>x2.second;
        }
        );
        sort(val.begin(),val.begin()+k);

        vector<int>ans;
        for(int i=0;i<k;i++)ans.push_back(val[i].second);
        return ans;
    }
};
