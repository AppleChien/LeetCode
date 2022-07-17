static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
    }
    int rob(vector<int>& nums, int left, int right) {
        int robEven = 0, robOdd = 0;
        for (int i = left; i < right; ++i) {
            if (i % 2 == 0) {
                robEven = max(robEven + nums[i], robOdd);
            }
            else {
                robOdd = max(robEven, robOdd + nums[i]);
            }
        }
        return max(robEven, robOdd);
    }
};