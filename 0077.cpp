static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> out(k, 0);
        int i = 0;
        while (i >= 0) {
            ++out[i];
            if (out[i] > n) --i;
            else if (i == k - 1) res.push_back(out);
            else {
                ++i;
                out[i] = out[i - 1];
            }
        }
        return res;
    }
};