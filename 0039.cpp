static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        DFS(candidates, target, 0, out, res);
        return res;
    }
    void DFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res) {
        if (target < 0) return;
        if (target == 0) { res.push_back(out); return; }
        for (int i = start; i < candidates.size(); ++i) {
            out.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};