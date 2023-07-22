//
// Created by yjs on 2022/6/4.
//

#include <bits/stdc++.h>


using namespace std;



class KMinNumber{

public:

    int getKMinNumber( vector<int>  & nums, int target){
        return randomSelect(nums,0,nums.size()-1,target);





    }


    int randomPartition( vector<int>  & nums, int left , int right){

        int randomNumber= (rand()% (right-left+1))+left;
        swap(nums[randomNumber],nums[right]);
        return partition(nums,left,right);


    }

    int partition( vector<int> & nums,int left, int right){
        int cur=nums[right];

        int i=left-1;
        for (int j = left; j <= right-1 ; ++j) {
            if(nums[j]<=cur){
                swap(nums[++i],nums[j]);
            }

        }
        swap(nums[i+1], nums[right]);
        return i+1;


    }

    int randomSelect( vector<int> & nums, int left,int right , int targetPos){
        if(left==right){
            return nums[left];
        }
        int q= randomPartition(nums,left,right);
        int k=q-left+1;
        if(targetPos==k){
            return nums[q];
        } else if(targetPos<k){
            return randomSelect(nums, left,q-1,targetPos);
        }else {
            // targetPos > k
            return randomSelect(nums, q+1,right,targetPos-k);

        }




    }



};




int main(){

    KMinNumber*  kMinNumber= new KMinNumber;
    vector<int>  nums{12,23,56,45,78,62,27};
    vector<int>  nums2(nums);

    sort(nums2.begin(),nums2.end());


    for (int i = 0; i < nums.size() ; ++i) {
        auto  res=kMinNumber->getKMinNumber(nums,i+1);
        cout << "res is "<< res << "  and  sort is : "<< nums2[i]<<endl;



    }


    return 0;


}