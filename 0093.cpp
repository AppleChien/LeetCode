static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        for (int a = 1; a < 4; ++a)
            for (int b = 1; b < 4; ++b)
                for (int c = 1; c < 4; ++c)
                    for (int d = 1; d < 4; ++d)
                        if (a + b + c + d == s.size()) {
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a + b, c));
                            int D = stoi(s.substr(a + b + c, d));
                            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                                string t = to_string(A) + "." + to_string(B) + "." + to_string(C) + "." + to_string(D);
                                if (t.size() == s.size() + 3) res.push_back(t);
                            }
                        }
        return res;
    }
};