#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*>& employees, int id) {
        for (int i = 0; i < employees.size(); ++i) {
            idIndexMap[employees[i]->id] = i;
        }

        return getImportanceInner(employees, id);
    }

    int getImportanceInner(vector<Employee*>& employees, int id) {
        int index = idIndexMap[id];
        int importance = employees[index]->importance;
        for (int i = 0; i < employees[index]->subordinates.size(); ++i) {
            importance += getImportanceInner(employees, employees[index]->subordinates[i]);
        }
        return importance;
    }

private:
    unordered_map<int, int> idIndexMap;
};

int main(int argc, char* argv[])
{
    int id;
    int n;
    //int importance;
    int size;
    int subordinate;
    vector<int> prices;
    vector<Employee*> employees;

    cin >> id;
    cin >> n;
    while (n > 0) {
        prices.push_back(n);

        Employee* employee = new Employee();
        cin >> employee->id;
        cin >> employee->importance;
        cin >> size;
        for (int i = 0; i < size; ++i) {
            cin >> subordinate;
            employee->subordinates.push_back(subordinate);
        }
        employees.push_back(employee);
        --n;
    }

    Solution solution;
    cout << solution.getImportance(employees, id) << endl;

    return 0;
}
