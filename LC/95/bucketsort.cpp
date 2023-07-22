//
// Created by yjs on 2022/6/3.
//

#include <bits/stdc++.h>


using namespace  std;


class BucketSort{
public:


    void bucketSort(vector<int> & arr ,const int bucket_count) {

        vector<int>::value_type maxx = *max_element(arr.begin(), arr.end());
        vector<int>::value_type minx = *min_element(arr.begin(), arr.end());
        const  double bucket_size=(double ) (maxx-minx+1)/(bucket_count);

        // 初始化空桶


        vector<vector<int>> bucket(bucket_count,vector<int>{});

        for (int i = 0; i < arr.size(); ++i) {
//            cout << arr[i] << " to "<< floor((arr[i]-minx)/bucket_size)<< endl;
            bucket[floor((arr[i]-minx)/bucket_size)].push_back(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < bucket_count; ++i) {
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

    void comparator(vector<int> &arr) {
        sort(arr.begin(), arr.end());
    }

    vector<int> generateRandomArray(int maxSize, int maxValue) {

        uniform_real_distribution<> u(0,1);
        uniform_int_distribution<unsigned > u2(0,maxValue + 1);
        default_random_engine e;
        vector<int> arr(maxSize*u(e));
        for (int i = 0; i < arr.size(); i++) {
            arr[i]=u2(e);
        }
        return arr;


    }


    void run() {
        int testTime = 50000;
        int maxSize = 100; // 随机数组的长度0～100
        int maxValue = 100;// 值：-100～100
        bool succeed = true;
        for (int i = 0; i < testTime; i++) {
            vector<int> arr = generateRandomArray(maxSize, maxValue);

            vector<int> arr1(arr);
            vector<int> arr2(arr);
            this->bucketSort(arr1,10);
            comparator(arr2);
            if (arr1!=arr2) {
                // 打印arr1
                // 打印arr2
                succeed = false;
                for (int j = 0; j < arr.size(); j++) {
                    cout << arr[j] <<  " ";
                }
                cout << endl;
                break;
            }
        }
        cout << (succeed? "Nice!" : "Fucking fucked!")<<endl;
        vector<int> arr = generateRandomArray(maxSize, maxValue);
        pprint("arr before ",arr);
        this->bucketSort(arr,10);
        pprint("arr after",arr);
    }




};



int main(){
    BucketSort bucketSort;
    vector<int> nums4{2, 3, 56, 89, 26, 65, 19, 16, 23};

    bucketSort.bucketSort(nums4,10);
    string str;
    bucketSort.pprint(str,nums4);
    cout << str<<endl;
    bucketSort.run();

    return 0;
}