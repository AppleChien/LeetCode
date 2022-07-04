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
        int robEven = 0, robOdd = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
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