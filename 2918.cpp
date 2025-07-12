class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1=0,s2=0;
        bool haszero=false;

        for(int x:nums1){
            haszero|=x==0;
            s1+=max(x,1);
        }
        for(int x:nums2)s2+=max(x,1);

        if(s1>s2)return minSum(nums2,nums1);
        if(s1==s2)return s1;

        return haszero?s2:-1;
    }
};
