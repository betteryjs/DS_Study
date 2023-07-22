#include <bits/stdc++.h>


using namespace std;




// ["gta","gta(1)","gta","avalon"]
class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string , int> index;
        vector<string> res;
        for(const string &  name:names){
            if(index[name]==0){
                res.push_back(name);
                index[name]++;
            }else{
                int k=index[name];

                while (index.count(addSuffix(name,k))){
                    k++;
                }
                res.push_back(addSuffix(name,k));
                index[name]=k+1;
                index[addSuffix(name,k)]=1;

            }



        }
        return  res;

    }

    string addSuffix(string name, int k) {
        return name + "(" + to_string(k) + ")";
    }


};

int main(){
    return  0;
}