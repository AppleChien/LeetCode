class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=accumulate(begin(nums),end(nums),0);
        if(total%2)return false;

        unordered_set<int>sum,next;

        for(int n:nums){
            next=sum;
            for(int s:sum)next.insert(s+n);
            next.insert(n);
            if(next.count(total/2))return true;
            swap(sum,next);
        }

        return false;
    }
};
