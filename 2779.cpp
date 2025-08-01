class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int m=*max_element(nums.begin(),nums.end())+k*2+2;
        vector<int>d(m);
        for(int x:nums){
            d[x]++;
            d[x+k*2+1]--;
        }

        int ans=0,sum=0;
        for(int x:d){
            sum+=x;
            ans=max(ans,sum);
        }

        return ans;
    }
};
