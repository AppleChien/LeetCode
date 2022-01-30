static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;
        auto tmp = head->next;
        head->next = swapPairs(head->next->next);
        tmp->next = head;
        return tmp;
    }
};