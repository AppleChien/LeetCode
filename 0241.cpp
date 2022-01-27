static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int a = 0;
        while (m != n) {
            m = m >> 1;
            n = n >> 1;
            a++;
        }
        return m << a;
    }
};