#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        // binary search
        int n = nums1.size() - 1, m = nums2.size() - 1, cur1 = 0, cur2 = 0;
        int mid1, mid2;
        while (cur1 != n || cur2 != m) {
            mid1 = (cur1 + n) / 2;
            mid2 = (cur2 + m) / 2;
            if (nums1[mid1] == nums2[mid2]) {
                return nums1[mid1];
            }
            if (nums1[mid1] < nums2[mid2]) {
                if ((cur1 + n - 1) & 1) {
                    // 奇数
                    cur1 = mid1;
                    m = mid2;

                } else {
                    cur1 = mid1 + 1;
                    m = cur2;

                }


            }
            else {

                if ((cur2 + m - 1) & 1) {
                    // 奇数
                    cur1 = mid1;
                    m = mid2;

                } else {
                    cur1 = mid1 + 1;
                    m = cur2;

                }


            }
        }
        return nums1[cur1]<nums2[cur2] ? nums1[cur1]:nums2[cur2];

    }
};





// @solution-sync:end

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    auto solution = Solution();
    auto result = solution.findMedianSortedArrays(nums1, nums2);
    cout << result << endl;

    return 0;
}
