#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : hashvec(1000001, -1) {}
    
    void add(int key) {
        hashvec[key] = 1;
    }
    
    void remove(int key) {
        hashvec[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) { return hashvec[key] == 1;}

private:
    vector<int> hashvec;
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueVec;
    Input(valueVec);

    // solution
    MyHashSet hs;
    for (auto act: valueVec) {
        switch(act[0]) {
        case 0:
            hs.add(act[1]);
            break;
		case 1:
		    cout << (hs.contains(act[1])?"true":"false") << endl;
			break;
		default:
		    hs.remove(act[1]);
        }
    }

    return 0;
}
