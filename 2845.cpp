class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            arr[i]=int(nums[i]%modulo==k);
        }

        unordered_map<int,int>cnt;
        cnt[0]=1;
        long long ans=0;
        int sum=0;

        for(int a:arr){
            sum+=a;
            ans+=cnt[(sum-k+modulo)%modulo];
            cnt[sum%modulo]++;
        }

        return ans;
    }
};
