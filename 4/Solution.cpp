#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
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
        int start1 = 0;
        int start2 = 0;
        int end1 = nums1.size();
        int end2 = nums2.size();
        int medium1;
        int medium2;
        
        while (size2 > 1)
        {
            medium1 = nums1[start1 + (size1-1)/2] + nums1[start1 + size1/2];
            medium2 = nums2[start2 + (size2-1)/2] + nums2[start2 + size2/2];
            if (medium1 > medium2)
            {
                end1 -= size2/2;
                size1 = end1 - start1;

                start2 += size2/2;
                size2 = end2 - start2;
            }
            else if (medium1 < medium2)
            {
                start1 += (end2 - start2 - (size2-1)/2 - 1);
                size1 = end1 - start1;

                end2 = start2 + (size2-1)/2 + 1;
                size2 = end2 - start2;
            }
            else
            {
                return ((double)medium1)/2;
            }
        }
        if ( size1 % 2 == 0 )
        {
            if (nums2[start2] <= (nums1[start1 + (size1-1)/2]))
            {
               return nums1[start1 + (size1-1)/2];
            }
            else if (nums2[start2] >= (nums1[start1 + size1/2]))
            {
                return nums1[start1 + size1/2];
            }
            else
            {
                return nums2[start2];
            }
        }
        else if (size1 == 1)
        {
            return ((double)(nums1[start1] + nums2[start2]))/2;
        }
        else
        {
            if (nums2[start2] <= (nums1[start1 + (size1-1)/2 - 1]))
            {
                return ((double)(nums1[start1 + (size1-1)/2 - 1] + nums1[start1 + (size1-1)/2]))/2;
            }
            else if (nums2[start2] >= (nums1[start1 + (size1-1)/2 + 1]))
            {
                return ((double)(nums1[start1 + (size1-1)/2] + nums1[start1 + (size1-1)/2 + 1]))/2;
            }
            else
            {
                return ((double)(nums1[start1 + (size1-1)/2] + nums2[start2]))/2;
            }
        }
    }
};

int main()
{
    Solution solution;
    std::vector<int> nums1;
    std::vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(5);

    nums2.push_back(3);
    nums2.push_back(4);
    nums2.push_back(6);

    std::cout << solution.findMedianSortedArrays(nums1, nums2) << std::endl;
}
