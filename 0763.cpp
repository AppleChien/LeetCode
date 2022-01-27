static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> v, lastIdx(26);
        for (int i = 0; i < n; ++i) lastIdx[s[i] - 'a'] = i;
        for (int i = 0; i < n; ++i)
        {
            r = max(r, lastIdx[s[i] - 'a']);
            if (i == r) v.push_back(r - l + 1), l = ++r;
        }
        return v;
    }
};