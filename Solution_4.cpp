//
// Created by houmo on 19-1-14.
//

#include "Solution_4.h"

/*
    There are two sorted arrays nums1 and nums2 of size m and n respectively.

    Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

    You may assume nums1 and nums2 cannot be both empty.

    Example 1:

    nums1 = [1, 3]
    nums2 = [2]

    The median is 2.0
    Example 2:

    nums1 = [1, 2]
    nums2 = [3, 4]

    The median is (2 + 3)/2 = 2.5

 */


double Solution_4::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {

    int size1 = nums1.size();
    int size2 = nums2.size();
    int medianPosition = (size1 + size2 + 1) / 2;
    int odd = (size1 + size2) % 2;
    int point1 = 0;
    int point2 = 0;
    double getOne = 0;

    while (medianPosition > 0 && point1 < size1 && point2 < size2) {
        if (nums1[point1] < nums2[point2]) {
            getOne = nums1[point1];
            point1 += 1;
        } else {
            getOne = nums2[point2];
            point2 += 1;
        }
        medianPosition--;

        cout << getOne << endl;
    }

    if (medianPosition > 0) {
        if (point1 == size1) {
            while (medianPosition > 0) {
                getOne = nums2[point2];
                point2 += 1;
                medianPosition--;
                cout << getOne << endl;
            }
        } else {
            while (medianPosition > 0) {
                getOne = nums1[point1];
                point1 += 1;
                medianPosition--;
                cout << getOne << endl;
            }
        }
    }

    if (odd == 1) {
        return getOne;
    } else {
        double next;
        if (point1 == size1) {
            next = nums2[point2];
        } else if (point2 == size2) {
            next = nums1[point1];
        } else if (nums1[point1] < nums2[point2]) {
            next = nums1[point1];

        } else {
            next = nums2[point2];
        }
        return (getOne + next) / 2;
    }

}
