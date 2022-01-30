static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> v;
        unordered_map<string, vector<string>> _m;
        for (auto s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            _m[tmp].push_back(s);
        }
        for (auto m : _m) v.push_back(m.second);
        return v;
    }
};