#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	int n;
public:
    int movesToMakeZigzag(vector<int>& nums) {
	n=nums.size();
	return min(get_data(true,nums),get_data(false,nums));
    }
    int get_data(bool flag, vector<int> & nums){
    	int count=0;
	for(int i=0;i<n-1;++i){
		int j=i+1;
		if(flag && nums[i]<nums[j]){
			int tmpi=nums[j];
			nums[j]=nums[i]-1;
			count+=tmpi-nums[j];
		}
		if(!flag && nums[i]>nums[j]){
			int tmpi=nums[i];
			nums[i]=nums[j]-1;
			count+=tmpi-nums[i];
		}
		flag=!flag;
	
	}
	return count;
    }
};
