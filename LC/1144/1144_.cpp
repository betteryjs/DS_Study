#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
	return min(help(0,nums),help(1,nums));
    }
    int help(int pos, const vector<int> &  nums){
    	int count=0;
	for(int i=pos ; i<nums.size(); i+=2){
		int a=0;
		if(i-1>=0){
			a=max(a, nums[i]-nums[i-1]+1);
		}
		if(i+1<nums.size()){
		
			a=max(a, nums[i]-nums[i+1]+1);
		}
		count+=a;
	}

	return count;
	}
};
