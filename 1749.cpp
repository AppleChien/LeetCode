class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int a=0,b=0;
        int ans=0;
        for(int &x:nums){
            a=max(a,0)+x;
            b=min(b,0)+x;
            ans=max({ans,a,abs(b)});
        }
        return ans;
    }
};
