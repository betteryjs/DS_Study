//
// Created by yjs on 2022/4/21.
//
#include <bits/stdc++.h>


using namespace std;


class LFUCache {
public:
    unordered_map<int,list<int>> fr;
    unordered_map<int,int> used;
    unordered_map<int,int> cache;
    unordered_map<int,list<int>::iterator> itr;
    int min_fr;
    int cap;
    LFUCache(int capacity) {
        min_fr=-1;
        cap = capacity;
    }

    int get(int key) {
        if(cache.count(key)==0) return -1;
        int ans = cache[key];
        int cnt = used[key];
        used[key] = cnt+1;
        fr[cnt].erase(itr[key]);
        if(cnt==min_fr && fr[cnt].size()==0) min_fr++;
        fr[cnt+1].push_front(key);
        itr[key]=fr[cnt+1].begin();
        return ans;
    }

    void put(int key, int value) {
        if(!cap) return;
        if(cache.find(key)!=cache.end()){
            cache[key]=value;
            get(key);
            return;
        }
        if(cache.size()>=cap){
            int evit = fr[min_fr].back();
            fr[min_fr].erase(itr[evit]);
            cache.erase(evit);
            used.erase(evit);
        }
        cache[key]=value;
        used[key]=1; //++used[key] not working
        min_fr=1;
        fr[1].push_front(key);
        itr[key] = fr[1].begin();
    }


};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */