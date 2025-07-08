class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        long long ans=0,current=0;
        int i=0;
        
        for(int &n:nums){
            current+=cnt[n]++;
            while(current-cnt[nums[i]]+1>=k)current-=--cnt[nums[i++]];

            if(current>=k)ans+=i+1;
        }

        return ans;
    }
};
