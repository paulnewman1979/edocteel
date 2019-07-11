#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_set>

using namespace std;

template <typename baseType>
void Input(baseType& value) {
    cin >> value;
};

template <typename baseType>
void Input(vector<baseType>& valueVec) {
    baseType value;
    int n;
    cin >> n;
    while (n-- > 0) {
        Input(value);
        valueVec.push_back(value);
    }
}

template <>
void Input(vector<string>& valueVec) {
    string value;
    int n;
    cin >> n;
    getline(cin, value);
    while (n-- > 0) {
        getline(cin, value);
        valueVec.push_back(value);
    }
}

template <typename baseType>
void Input(vector<vector<baseType>>& valueGrid) {
    int n;
    vector<baseType> valueVec;
    cin >> n;
    while (n-- > 0) {
        Input(valueVec);
        valueGrid.push_back(valueVec);
    }
}

template <>
void Input(string& value) {
    getline(cin, value);
}

template <>
void Input(bool& value) {
    int valueInt;
    cin >> valueInt;
    value = (valueInt == 0) ? false : true;
}

