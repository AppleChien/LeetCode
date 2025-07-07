class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>s;
        int mi=INT_MAX;

        for(int n:nums){
            if(n<k)return -1;

            mi=min(mi,n);
            s.insert(n);
        }

        return s.size()-(mi==k);
    }
};
