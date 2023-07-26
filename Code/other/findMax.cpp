//
// Created by yjs on 2022/2/22.
//

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class FindMax{


public:
    static int findMax(const vector<int> & arr,int low,int high){
        if(low==high){ //[low,high]
            return arr[low];
        }
        int mid=low+((high-low)>>1);
        int lowMax= findMax(arr,low,mid);
        int highMax= findMax(arr,mid+1,high);
        return max(lowMax,highMax);


    }

};

int main() {
    vector<int> arr{77 ,46 ,54 ,22 ,4 ,69 ,69 ,95 ,39 ,52 ,84 ,3 ,5};
    auto  res=FindMax::findMax(arr,0,arr.size()-1);
    cout << res<<endl;

    return 0;
}