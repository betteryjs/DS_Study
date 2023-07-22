//
// Created by yjs on 2022/4/29.
//


#include <bits/stdc++.h>

using namespace std;
// https://mp.weixin.qq.com/s/qGqIWM2hmL1xewygPnb3Og

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        serialize(root, res);
        return res;


    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<string> datas = split(data, ",");
        queue<string> queueData;
        for (int i = 0; i < datas.size(); ++i) {
            queueData.push(datas[i]);

        }
        return deserialize(queueData);


    }

    std::vector<std::string> split(const std::string &str, const std::string &delim) {
        std::vector<string> res;
        if (str.empty()) {
            return res;
        }
        std::string string1 = str + delim; //*****扩展字符串以方便检索最后一个分隔出的字符串
        std::string::size_type pos;
        std::size_t size = string1.size();
        for (int i = 0; i < size; ++i) {
            pos = string1.find(delim, i); //pos为分隔符第一次出现的位置，从i到pos之前的字符串是分隔出来的字符串
            if (pos != string::npos) { //如果查找到，如果没有查找到分隔符，pos为string::npos
                string s = string1.substr(i, pos - i);//*****从i开始长度为pos-i的子字符串
                res.push_back(s);//两个连续空格之间切割出的字符串为空字符串，这里没有判断s是否为空，所以最后的结果中有空字符的输出，
                i = pos + delim.size() - 1;
            }
        }
        return res;
    }


    TreeNode *deserialize(queue<string> &datas) {
        string val = datas.front();
        datas.pop();
        if (val == "null") {
            return nullptr;
        }
        TreeNode *root = new TreeNode(atoi(val.c_str()));
        root->left = deserialize(datas);
        root->right = deserialize(datas);
        return root;


    }

    void serialize(TreeNode *root, string &res) {
        if (root == nullptr) {
            res += "null,";
            return;
        }

        res += to_string(root->val) + ",";
        serialize(root->left, res);
        serialize(root->right, res);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));