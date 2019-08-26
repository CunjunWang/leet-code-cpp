//
// Created by 王存俊 on 2019-08-26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>
#include <sstream>
#include <cassert>
#include <list>
#include <set>
#include "TreeNode.h"
#include "ListNode.h"

using namespace std;

class LRUCache {
private:
    int size;
    list<int> keys;
    unordered_map<int, int> pairs;

public:
    LRUCache(int capacity) {
        this->size = capacity;
    }

    int get(int key) {
        auto index = find(keys.begin(), keys.end(), key);
        if (index == keys.end())
            return -1;
        keys.remove(key);
        keys.push_front(key);
        return pairs[key];
    }

    void put(int key, int value) {
        // 若key本身就存在
        auto index = find(keys.begin(), keys.end(), key);
        if (index != keys.end()) {
            keys.remove(key);
            keys.push_front(key);
            pairs[key] = value;
            return;
        }
        if (keys.size() >= size) {
            int last = keys.back();
            keys.pop_back();
            pairs.erase(last);
        }
        keys.push_front(key);
        pairs[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache *cache = new LRUCache(2);
    cache->put(2, 1);
    cache->put(1, 1);
    cache->put(2, 3);
    cache->put(4, 1);
    cout << cache->get(1) << endl;
    cout << cache->get(2) << endl;
}