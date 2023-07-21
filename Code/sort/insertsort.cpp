//
// Created by yjs on 23-7-21.
//

#include <bits/stdc++.h>
#include <vector>

using namespace  std;


void  insert_sort(vector<int> & arr){

    for (int i = 1; i < arr.size(); ++i) {
        for (int j = i-1; j >=0 && arr[j] > arr[j+1] ; j--) {
            swap(arr[j],arr[j+1]);
        }

    }




}

int main(){
    vector<int> arr{1,56,89,26,55};
    for_each(arr.begin(),arr.end(),[](auto  c){ cout << c << " "; });
    cout<< endl;
    insert_sort(arr);
    for_each(arr.begin(),arr.end(),[](auto  c){ cout << c << " "; });



    return 0;
}





