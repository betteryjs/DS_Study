#include <bits/stdc++.h>

using namespace std;


class RandomizedSet {
private:

    // 存储元素的值
    vector<int> nums;
    // 记录每个元素对应在 nums 中的索引
    unordered_map<int, int> valToIndex;
public:
    RandomizedSet() {

    }

    bool insert(int val) {

        if (valToIndex.count(val)) {
            return false;
        }
        // 若 val 不存在，插入到 nums 尾部，
        // 并记录 val 对应的索引值
        valToIndex[val] = nums.size();
        nums.push_back(val);
        return true;

    }

    bool remove(int val) {
        if (!valToIndex.count(val)) {

            return false;

        }

        // 先拿到 val 的索引

        int index = valToIndex[val];

        // 将最后一个元素对应的索引修改为 index
        valToIndex[nums.back()] = index;

        swap(nums[index], nums.back());
        nums.pop_back();
        // 删除元素 val 对应的索引
        valToIndex.erase(val);
        return true;


    }

    int getRandom() {
        return nums[rand() % nums.size()];

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
