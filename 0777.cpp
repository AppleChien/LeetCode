static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool canTransform(string start, string end) {
        for (int i = 0, j = 0, n = start.size(); i < n or j < n; i++, j++)
        {
            while (i < n and start[i] == 'X') ++i;
            while (j < n and end[j] == 'X') ++j;
            if ((i < n) ^ (j < n)) {
                //cout << "Output: false";
                return false;
            }
            if (i < n and ((start[i] != end[j]) or (start[i] == 'R' && i > j) or (start[i] == 'L' and i < j))) {
                //cout << "Output: false";
                return false;
            }
        }
        //cout << "Output: true";
        return true;
    }
};