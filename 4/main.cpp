#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	inline int getValue(vector<int>& num, int pos)
	{
		return num[pos-1];
	}

    double findMedian(vector<int>& nums1, vector<int>& nums2)
    {
        if (nums2.size() == 0)
        {
            if (nums1.size() % 2 == 1)
            {
                return nums1[(nums1.size()-1)/2];
            }
            else
            {
                return ((double)(nums1[(nums1.size()-1)/2] + nums1[nums1.size()/2]))/2;
            }
        }

        int size1 = nums1.size();
        int size2 = nums2.size();
		int start1 = 1;
		int end1 = size1;
		int pos1 = (start1 + end1)/2;
		int pos2 = (size1 + size2 + 1)/2 - pos1;
		double median = 0;
		while (end1 - start1 >= 1)
		{
			pos1 = (start1 + end1)/2;
			pos2 = (size1 + size2 + 1)/2 - pos1;
			if (getValue(nums1, pos1) >= getValue(nums2, pos2))
			{
				if ( pos2 == size2)
				{
					median = getValue(nums1, pos1);
					if ((size1 + size2) % 2 == 1)
					{
						return median;
					}
					else
					{
						return ((double)(getValue(nums1, pos1) + getValue(nums1, pos1 + 1)))/2;
					}
				}
				else if (getValue(nums1, pos1) <= getValue(nums2, pos2 + 1))
				{
					median = getValue(nums1, pos1);
					if ( (size1 + size2) % 2 == 1)
					{
						return median;
					}
					else if ((pos1 < size1) && (getValue(nums1, pos1 + 1) <= getValue(nums2, pos2 + 1)) )
					{
						return ((double)(getValue(nums1, pos1) + getValue(nums1, pos1 + 1)))/2;
					}
					else
					{
						return ((double)(getValue(nums1, pos1) + getValue(nums2, pos2 + 1)))/2;
					}
					break;
				}
				else
				{
					end1 = pos1;
				}
			}
			else
			{
				if ( pos1 == size1)
				{
					if ((size1 + size2) % 2 == 1)
					{
						return getValue(nums2, pos2);
					}
					else
					{
						return ((double)(getValue(nums2, pos2) + getValue(nums2, pos2 + 1)))/2;
					}
				}
				else if (getValue(nums2, pos2) <= getValue(nums1, pos1 + 1))
				{
					median = getValue(nums2, pos2);
					if ((size1 + size2) % 2 == 1)
					{
						return median;
					}
					else if ((pos2 < size2) &&
							(getValue(nums2, pos2 + 1) <= getValue(nums1, pos1 + 1)))
					{
						return ((double)(getValue(nums2, pos2) + getValue(nums2, pos2 + 1)))/2;
					}
					else
					{
						return ((double)(getValue(nums2, pos2) + getValue(nums1, pos1 + 1)))/2;
					}
				}
				else
				{
					start1 = pos1 + 1;
				}
			}
		}

    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            return findMedian(nums1, nums2);
        }
        else
        {
            return findMedian(nums2, nums1);
        }
    }
};

int main(int argc, char* argv[])
{
	vector<int> nums1;
	vector<int> nums2;
	int size1;
	int size2;
	int value;
	int i;

	cin >> size1;
	for (i=0; i<size1; i++)
	{
		cin >> value;
		nums1.push_back(value);
	}

	cin >> size2;
	for (i=0; i<size2; i++)
	{
		cin >> value;
		nums2.push_back(value);
	}

	Solution solution;
	cout << solution.findMedianSortedArrays(nums1, nums2) << endl;
}
