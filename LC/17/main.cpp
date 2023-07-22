#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// @solution-sync:begin
class Solution {
private:
    unordered_map<string , string> phoneMap{
            {"2", "abc"},
            {"3", "def"},
            {"4", "ghi"},
            {"5", "jkl"},
            {"6", "mno"},
            {"7", "pqrs"},
            {"8", "tuv"},
            {"9", "wxyz"}
    };
public:

    vector<string> letterCombinations(string digits) {

        int n=digits.size();
        vector<string> ans;
        if(n==0){
            return ans;
        }
        string sb;
        dfs(digits, 0, n, sb, ans);
        return ans;
    }

    void dfs(const string & ds, const int & i, const int & n, string & sb, vector<string> & ans){
        if (i==n){
            ans.push_back(sb);
        }
        string key=ds.substr(i,1);

        string all=phoneMap[key];
        for (auto c:all) {
            sb+=c;
            dfs(ds, i + 1, n, sb, ans);
            sb.pop_back();
        }



    }
};
// @solution-sync:end


// dfs
class Solution2 {
private:

    vector<string> result;
    string digits;
    unordered_map<char, string> store = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
    int digitsSize = int(this->digits.size());

public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        this->digits = digits;
        //储存字典
        dfs("", 0);
        return result;
    }

    void dfs(string resultStr, int index) {

        if (digitsSize == index) {
            result.push_back(resultStr);
            return;
        }
        char targetChar = this->digits[index];
        string targetStr = store[targetChar];
        for (auto tmpChar: targetStr) {
            dfs(resultStr + tmpChar, index + 1);//递归调用
        }
        return;
    }
};


// bfs

class Solution3
{
    vector<string> result;
    string digits;
    unordered_map<char, string> store = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
    int digitsSize = int(this->digits.size());

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
        {
            return result;
        }
        this->digits = digits;
        //储存字典
        queue<string> workQueue;
        workQueue.push("");
        for (auto targetChar : digits)
        {
            string targetStr = store[targetChar];
            int queueSize = int(workQueue.size());
            //当前层，进行添加字符
            for (int i = 0; i < queueSize; ++i)
            {
                string tmpStr = workQueue.front();
                workQueue.pop();
                for (auto tmpChar : targetStr)
                {
                    workQueue.push(tmpStr + tmpChar);
                }
            }
        }
        while (!workQueue.empty())
        {
            string tmpStr = workQueue.front();
            workQueue.pop();
            result.push_back(tmpStr);
        }
        return result;
    }
};











#include <sstream>

string toString(vector<string> v) {
    stringstream out;
    out << "[";
    unsigned long size = v.size();
    for (int i = 0; i < size; ++i) {
        out << v[i];
        if (i < size - 1)
            out << ",";
    }
    out << "]";
    return out.str();
}

int main() {
    string digits = "23";

    auto solution = Solution2();
    auto result = solution.letterCombinations(digits);
    cout << toString(result) << endl;

    return 0;
}
