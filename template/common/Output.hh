#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

template <typename baseType>
void Output(baseType& value) {
    cout << value << endl;
};

template <typename baseType>
void Output(vector<baseType>& valueVec) {
    for (auto p : valueVec) {
        Output(p);
    }
}

template <typename baseType>
void Output(vector<vector<baseType>>& valueGrid) {
    cout << valueGrid.size() << endl;
    for (auto p : valueGrid) {
        cout << p.size();
        for (auto q : p) {
            cout << " " << q;
        }
        cout << endl;
    }
}

template <>
void Output(bool& value) {
    cout << (value?"true":"false") << endl;
}
