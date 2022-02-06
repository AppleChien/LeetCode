static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3);
        for (int num : nums) ++colors[num];
        for (int i = 0, cur = 0; i < 3; ++i) {
            for (int j = 0; j < colors[i]; ++j) {
                nums[cur++] = i;
            }
        }
    }
};