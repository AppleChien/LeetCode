static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            if (i <= maxPos)
                maxPos = max(maxPos, i + nums[i]);
        return maxPos >= n - 1;
    }
};