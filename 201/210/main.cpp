#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector< pair<int, int> >& prerequisites) {
        vector<int> result(numCourses);

        int i, j;
        vector<int> inDegree(numCourses, 0);
        vector< vector<int> > courseSet(numCourses);
        int course;
        int coursePre;
        for (i=0; i<prerequisites.size(); ++i) {
            course = prerequisites[i].first;
            coursePre = prerequisites[i].second;
            inDegree[coursePre]++;
            courseSet[course].push_back(coursePre);
        }

        int count = numCourses;
        while (count > 0) {
            i = 0;
            while ((i < numCourses) && 
                (inDegree[i] != 0) ) {
                ++i;
            }

            if (i == numCourses) {
                break;
            } else {
                inDegree[i] = -1;
                result[count-1] = i;
                --count;
                for (j=0; j<courseSet[i].size(); ++j) {
                    coursePre = courseSet[i][j];
                    --inDegree[coursePre];
                }
            }
        }

        if (0 != count) {
            result.clear();
        }

        return result;
    }
};

int main(int argc, char* argv[])
{
    int numCourses;
    int course;
    int coursePre;
    vector< pair<int, int> > prerequisites;
    pair<int, int> prerequisite;

    cin >> numCourses;

    cin >> course;
    while (course != -999999) {
        cin >> coursePre;
        prerequisite.first = course;
        prerequisite.second = coursePre;
        prerequisites.push_back(prerequisite);
        cin >> course;
    }

    Solution solution;
    vector<int> result = solution.findOrder(numCourses, prerequisites);
    for (int i=0; i<result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
