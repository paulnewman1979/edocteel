#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return NULL;
        }

        vector<int> heap;

    }
};

int main(int argc, char* argv[])
{
    int list_size;
    int list_len;
    int i;
    int j;
    int value;
    vector<ListNode*> lists;
    ListNode* tail;
    ListNode* node;

    cin >> list_size;
    for (i=0; i<list_size; ++i)
    {
        cin >> list_len;
        for (j=0; j<list_len; ++j)
        {
            cin >> value;
            node = new ListNode(value);
            if (j == 0)
            {
                lists.push_back(node);
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }
}
