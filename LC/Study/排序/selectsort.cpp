//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;



class SelectSort{
// time O(n^2)
public:
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }
    void selectSort(vector<int> & arr){
        if (arr.empty() || arr.size() < 2) {
            return;
        }

        for (int i = 0; i < arr.size(); ++i) {
            int min=i;
            for (int j = i+1; j < arr.size(); ++j) {
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            swap(arr[i],arr[min]);


        }

    }




};










int main() {

    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};
    SelectSort selectSort;
    SelectSort::pprint("in", nums4);
    selectSort.selectSort(nums4);
    SelectSort::pprint("out", nums4);





    return 0;
}