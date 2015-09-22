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

            vector< vector<int> > heap;
            int index;
            int level = 0;
            heap.push_back(vector<ListNode*>());
            vector<ListNode*>& heap_level = heap[0];
            for (index=0; index<lists.size(); index+=2)
            {
                if (lists[index] == NULL)
                {
                    if (index + 1 < lists.size())
                    {
                        heap_level.push_back(lists[index+1]);
                    }
                    else
                    {
                        heap_level.push_back(NULL);
                    }
                }
                else if ( (index + 1 >= lists.size())
                    || (lists[index + 1] != NULL) )
                {
                    heap_level.push_back(lists[index]);
                }
                else if (lists[index].val >= lists[index].val)
                {
                    heap_level.push_back(lists[index]);
                }
                else
                {
                    heap_level.push_back(lists[index + 1]);
                }
            }
            while (heap[heap_level].size() > 1)
            {
                heap.push_back(vector<ListNode*>());
                vector<ListNode*>& pre_level = heap[level]
                ++ level;
                vector<ListNode*>& heap_level = heap[level];
                for (index=0; index<pre_level.size(); index+=2)
                {
                    if (pre_level[index] == NULL)
                    {
                        if (index + 1 < pre_level.size())
                        {
                            heap_level.push_back(pre_level[index + 1]);
                        }
                        else
                        {
                            heap_level.push_back(NULL);
                        }
                    }
                    else if ( (index + 1 >= pre_level.size() )
                                || (pre_level[index + 1] == NULL) )
                    {
                        heap_level.push_back
                    }

                }
            }
        }
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
