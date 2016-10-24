#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

/**
 * Definition for undirected graph.
 */
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (NULL == node) {
			return NULL;
		}

		std::unordered_map<int, UndirectedGraphNode*> nodeMap;
		std::unordered_map<int, UndirectedGraphNode*>::iterator miter;

		vector<UndirectedGraphNode*>::const_iterator viter;
		vector<UndirectedGraphNode*> undone;

		UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
		undone.push_back(node);
		nodeMap[node->label] = root;

		UndirectedGraphNode* cur;
		UndirectedGraphNode* ncur;
		UndirectedGraphNode* tmp;

		while (undone.size() > 0) {
			cur = undone.back();
			undone.pop_back();

			ncur = nodeMap[cur->label];

			for (viter=cur->neighbors.begin(); viter!=cur->neighbors.end(); ++viter) {
				miter = nodeMap.find((*viter)->label);
				if (miter != nodeMap.end()) {
					tmp = miter->second;
				} else {
					tmp = new UndirectedGraphNode((*viter)->label);
					nodeMap[(*viter)->label] = tmp;
					undone.push_back(viter);
				}
				ncur->neighbors.push_back(tmp);
			}
		}

		return root;
    }
};

int main(int argc, char* argv[])
{
	Solution solution;

	int n;
	cin >> n;

	int i;
	vector<UndirectedGraphNode*> nodes;
	vector<int> serials;


	int max;
	cin >> n;
	while (n != -999999) {
		serials.push_back(n);
		if (n > max) {
			max = n;
		}
	}

	for (i=0; i<max; ++i) {
		UndirectedGraphNode* tmp = new UndirectedGraphNode(i);
		nodes.push_back(tmp);
	}

	vector<UndirectedGraphNode*>::iterator iter = nodes.begin();
	for (i=0; i<serials.size(); ++i) {
		if (serials[i] == -999998) {
			++ iter;
		} else {
			(*iter)->neighbors.push_back(nodes[serials[i]]);
		}
	}

	UndirectedGraphNode* node = nodes[0];

    Solution solution;
	UndirectedGraphNode* newNode = solution.cloneGraph(node);

	return 0;
}
