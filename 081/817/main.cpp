#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

typedef BaseListNode<int> ListNode;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (head == NULL) return 0;

        int count = 0;
        ListNode* s = head;;
        unordered_set<int> gSet;
        for (auto g : G) {
            gSet.insert(g);
        }

        bool sExist = (gSet.find(s->val) != gSet.end());
        if (sExist) ++count;
        while (s->next != NULL) {
            if (gSet.find(s->next->val) != gSet.end()) {
                if (!sExist) ++count;
                sExist = true;
            } else {
                sExist = false;
            }
            s = s->next;
        }
        return count;
    }
};


int main(int argc, char* argv[])
{
    // input
    ListNode* head = NULL;
    Input(head);
    vector<int> G;
    Input(G);
		
    // solution
    Solution solution;
	int ret = solution.numComponents(head, G);

    // output
    Output(ret);

    return 0;
}
