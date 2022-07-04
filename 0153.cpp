static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] <= nums.back()) return nums[0];
        for (int num : nums) {
            if (num < nums[0]) return num;
        }
        return -1;
    }
};