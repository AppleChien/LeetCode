class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int ans=0,cnt=0;
        for(int i:nums){
            if(i==mx){
                ++cnt;
                ans=max(ans,cnt);
            }
            else cnt=0;
        }
        return ans;
    }
};
