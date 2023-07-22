#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    int minArray(vector<int> &numbers) {
        // binarySearch
        //
        //
        int low = 0, hig = numbers.size() - 1;

        while (low <= hig) {
            int mid = low + (hig - low) / 2;

            if (numbers[mid] > numbers[hig]) {
                // low is right
                low = mid + 1;
            } else if (numbers[mid] < numbers[hig]) {
                hig = mid;
            } else {
                // numbers[mid]==numbers[hig]
                hig--;
            }
        }
        return numbers[low];
    }
};
// @solution-sync:end

int main() {
    vector<int> numbers = {1, 3, 5};

    auto solution = Solution();
    auto result = solution.minArray(numbers);
    cout << result << endl;

    return 0;
}
