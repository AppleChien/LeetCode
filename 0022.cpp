static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(n, n, "", res);
        return res;
    }
    void DFS(int left, int right, string out, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) DFS(left - 1, right, out + '(', res);
            if (right > 0) DFS(left, right - 1, out + ')', res);
        }
    }
};