#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {

        vector<int> ans;

        for (int i = arr.size(); i > 1; i--) {
            int index=max_element(arr.begin(),arr.begin()+i)-arr.begin(); // 3
            cout <<"index "<< index<< endl;

            if(index==i-1){
                continue;
            }
            reverse(arr.begin(), arr.begin() + index + 1);
            reverse(arr.begin(),arr.begin()+i);
            ans.push_back(index+1);
            ans.push_back(i);

        }
        return ans;

    }


};
// @solution-sync:end

#include <sstream>

string toString(vector<int> v) {
    stringstream out;
    out << "[";
    unsigned long size = v.size();
    for (int i = 0; i < size; ++i) {
        out << v[i];
        if (i < size - 1)
            out << ",";
    }
    out << "]";
    return out.str();
}

int main() {
    vector<int> arr = {3, 2, 4, 1};

    auto solution = Solution();
    auto result = solution.pancakeSort(arr);
    cout << toString(result) << endl;

    return 0;
}
