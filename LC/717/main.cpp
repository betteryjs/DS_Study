#include <vector>
#include <iostream>

using namespace std;

// @solution-sync:begin
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        // O(n)
        int n=bits.size()-1;
        int index=0;
        while (index<=n){
            if(bits[index]==1){
                index +=2;
            }else if(bits[index]==0){
                if(index==n){
                    return true;
                }
                index ++;
            }
        }
        return false;
    }
};
// @solution-sync:end

int main() {
    vector<int> bits = {1, 0, 0};

    auto solution = Solution();
    auto result = solution.isOneBitCharacter(bits);
    cout << result << endl;

    return 0;
}
