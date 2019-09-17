//
// Created by 王存俊 on 2019-09-17.
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
#include <unordered_set>
#include "DoublyLinkedListNode.h"
#include "TreeNode.h"
#include "Helpers.h"

using namespace std;

class Twitter {
private:
    int curIndex;

    struct Post {
        int index;
        int postId;
        int userId;
    };

    struct ComparePost {
        bool operator()(const Post post, const Post &anotherPost) {
            return post.index < anotherPost.index;
        }
    };

    priority_queue<Post, vector<Post>, ComparePost> postQueue;

    // all tweets id, sorted by added order
    vector<int> allTweets;

    // graph to store <userId, followed user id>
    unordered_map<int, vector<int>> g;

public:
    /** Initialize your data structure here. */
    Twitter() {
        curIndex = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        // userTweets[userId].emplace_back(tweetId);
        postQueue.push({curIndex, tweetId, userId});
        curIndex++;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> targetUsers = g[userId];
        targetUsers.emplace_back(userId);

        auto copyQueue = postQueue;

        vector<int> res;

        while (!postQueue.empty()) {
            Post post = postQueue.top();
            postQueue.pop();
            if (res.size() < 10 && find(targetUsers.begin(), targetUsers.end(), post.userId) != targetUsers.end()) {
                res.emplace_back(post.postId);
            }
        }

        postQueue = copyQueue;

        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        vector<int> userFollows = g[followerId];
        if (find(userFollows.begin(), userFollows.end(), followeeId) == userFollows.end()) {
            userFollows.emplace_back(followeeId);
            g[followerId] = userFollows;
        }
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        vector<int> userFollows = g[followerId];
        int index = find(userFollows.begin(), userFollows.end(), followeeId) - userFollows.begin();
        if (index != userFollows.size()) {
            userFollows.erase(find(userFollows.begin(), userFollows.end(), followeeId));
            g[followerId] = userFollows;
        }
    }
};


int main() {
    Twitter *obj = new Twitter();
    obj->postTweet(1, 5);
    vector<int> param_2 = obj->getNewsFeed(1);
    printVector(param_2);

    obj->follow(1, 2);
    obj->postTweet(2, 6);
    param_2 = obj->getNewsFeed(1);
    printVector(param_2);

    obj->unfollow(1, 2);
    param_2 = obj->getNewsFeed(1);
    printVector(param_2);
}