//
// Created by yjs on 23-7-21.
//
//
// Created by yjs on 23-7-21.
//

#include <bits/stdc++.h>
#include <vector>

using namespace std;


void bubble_sort(vector<int> &arr) {
    if (arr.empty() || arr.size() < 2) return;
    bool flag = false;
    for (int e = arr.size() - 1; e >= 0; --e) {
        for (int i = 0; i < e; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                flag = true;
            }
        }
        if (!flag) break;
    }
}

int main() {
    vector<int> arr{1, 56, 102, 89, 99, 26, 12, 45, 55};
    for_each(arr.begin(), arr.end(), [](auto c) { cout << c << " "; });
    cout << endl;
    bubble_sort(arr);
    for_each(arr.begin(), arr.end(), [](auto c) { cout << c << " "; });


    return 0;
}





