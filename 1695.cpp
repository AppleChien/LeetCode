class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int d[10001]{};
        int n=nums.size();
        int sum[n+1];
        sum[0]=0;

        for(int i=0;i<n;i++)sum[i+1]=sum[i]+nums[i];

        int ans=0,j=0;
        for(int i=1;i<=n;i++){
            int v=nums[i-1];
            j=max(j,d[v]);
            ans=max(ans,sum[i]-sum[j]);
            d[v]=i;
        }

        return ans;
    }
};
