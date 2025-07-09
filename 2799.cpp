class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end());
        int ans=0,left=0;
        unordered_map<int,int>cnt;

        for(int right=0;right<size(nums);right++){
            ++cnt[nums[right]];

            for(;size(cnt)==size(s);left++){
                if(--cnt[nums[left]]==0)cnt.erase(nums[left]);
            }

            ans+=left;
        }

        return ans;
    }
};
