class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        auto f=[&](int x){
            int cnt=0,j=-2;

            for(int i=0;i<nums.size();i++){
                if(nums[i]>x||i==j+1)continue;

                ++cnt;
                j=i;
            }
            return cnt>=k;
        };

        int l=0,r=*max_element(nums.begin(),nums.end());
        while(l<r){
            int mid=(l+r)>>1;
            if(f(mid))r=mid;
            else l=mid+1;
        }

        return l;
    }
};
