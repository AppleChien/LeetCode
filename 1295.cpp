class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int &n:nums)ans+=to_string(n).size()%2==0;
        return ans;
    }
};
