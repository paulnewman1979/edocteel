#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <set>

using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
	{
        vector< set<int> > matrix(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
            matrix[prerequisites[i].second].insert(prerequisites[i].first);
            
        vector<int> degree(numCourses, 0);
        for(int i=0; i<numCourses; i++)
            for(auto it:matrix[i])
                ++degree[it];
                
        for(int i=0; i<numCourses; i++)
        {
            int j;
            for(j=0; j<numCourses && degree[j]!=0; ++j);
            
            if(j==numCourses) return false;
            
            degree[j] = -1;
            
            for(auto it:matrix[j])
                --degree[it];
        }
            
        return true;
    }
};

int main(int argc, char* argv[])
{
	int numCourses;
	int course, precourse;
	vector< pair<int,int> > prerequisites;

	cin >> numCourses;

	cin >> course;
	while (course != -999999) {
		cin >> precourse;
		prerequisites.push_back(std::pair<int, int>(course, precourse));
		cin >> course;
	}
		
    Solution solution;
	cout << (solution.canFinish(numCourses, prerequisites)?"true":"false") << endl;

    return 0;
}
