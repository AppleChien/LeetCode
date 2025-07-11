class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=0,r=1LL*ranks[0]*cars*cars;

        while(l<r){
            long long mid=(l+r)>>1;
            long long cnt=0;
            for(int r:ranks)cnt+=sqrt(mid/r);

            if(cnt>=cars)r=mid;
            else l=mid+1;
        }

        return l;
    }
};
