static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int up = 0, down = n - 1, left = 0, right = n - 1, val = 1;
        while (true) {
            for (int j = left; j <= right; ++j) res[up][j] = val++;
            if (++up > down) break;
            for (int i = up; i <= down; ++i) res[i][right] = val++;
            if (--right < left) break;
            for (int j = right; j >= left; --j) res[down][j] = val++;
            if (--down < up) break;
            for (int i = down; i >= up; --i) res[i][left] = val++;
            if (++left > right) break;
        }
        return res;
    }
};