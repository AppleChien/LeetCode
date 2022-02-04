static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> res;
        DFS(num, 0, res);
        return res;
    }
    void DFS(vector<int>& num, int start, vector<vector<int>>& res) {
        if (start >= num.size()) res.push_back(num);
        for (int i = start; i < num.size(); ++i) {
            swap(num[start], num[i]);
            DFS(num, start + 1, res);
            swap(num[start], num[i]);
        }
    }
};