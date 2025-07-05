class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int mx=0,mxdiff=0;
        for(int n:nums){
            ans=max(ans,1LL*mxdiff*n);
            mx=max(mx,n);
            mxdiff=max(mxdiff,mx-n);
        }

        return ans;
    }
};
