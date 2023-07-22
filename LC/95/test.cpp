//
// Created by yjs on 2022/6/3.
//
//
// Created by yjs on 2022/2/23.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;


class BucketSort{

public:

    void bucketSort(vector<int> & arr) {

        vector<int>::value_type maxx = *max_element(arr.begin(), arr.end());
        vector<int>::value_type minx = *min_element(arr.begin(), arr.end());
        const int bucket_size=maxx / 10 - minx / 10 + 1;

        vector<vector<int>> bucket(bucket_size);
        // 初始化空桶
        for (int i = 0; i < bucket_size; ++i) {
            vector<int> x{0};
            bucket.push_back(x);
        }
        for (int i = 0; i < arr.size(); ++i) {
            bucket[arr[i] / 10].push_back(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < bucket_size; ++i) {
            // sort of bucket
            insertSort(bucket[i]);

            for (auto it = bucket[i].begin(); it != bucket[i].end(); ++it) {
                arr[index++] = *it;

            }
        }
    }


    static void insertSort(vector<int> &arr) {
        int len = arr.size();
        for (int i = 1; i < len; ++i) {
            for (int j = i-1; j >=0 ; j--) {
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    static void pprint(const string str, const vector<int> num) {
        cout << str << " [ ";
        for_each(num.begin(), num.end() - 1, [](const int a) { cout << a << " ,"; });
        cout << *(num.end() - 1) << " ]";
        cout << endl;
    }

};


// buckets sort




int main() {
    BucketSort bucketSort;
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    bucketSort.bucketSort(nums4);
    string str;
    bucketSort.pprint(str,nums4);
    cout << str<<endl;

    return 0;
}
