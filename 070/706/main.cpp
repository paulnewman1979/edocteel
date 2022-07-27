#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "../../template/common/Input.hh"
#include "../../template/common/Output.hh"

using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() : hashvec(1000001, -1) {}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashvec[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashvec[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashvec[key] = -1;
    }

private:
    vector<int> hashvec;
};

int main(int argc, char* argv[])
{
    // input
    vector<vector<int>> valueVec;
    Input(valueVec);

    // solution
    MyHashMap hm;
    for (auto act: valueVec) {
        switch(act[0]) {
        case 0:
            hm.put(act[1], act[2]);
            break;
		case 1:
		    cout << hm.get(act[1]) << endl;
			break;
		default:
		    hm.remove(act[1]);
        }
    }

    return 0;
}
