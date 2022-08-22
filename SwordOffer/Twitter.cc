#include <basic_head.h>
class Twitter {
public:
    Twitter() {

    }
    
    void postTweet(int userId, int tweetId) {
        twitter_list[userId].push_front(tweetId);
        if(twitter_list[userId].size() > 10){
            twitter_list[userId].pop_back();
        }
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        // Merge Sort all the lists
        vector<int> result;
        for(int i = 0; i < follow_map[i].size(); ++i){
            // MergeSort
        }
    }
    
    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
        followed_map[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
        followed_map[followeeId].erase(followerId);
    }

    unordered_map<int, set<int>> follow_map;   // those self flows
    unordered_map<int, set<int>> followed_map; // those follows self
    unordered_map<int, std::list<int>> twitter_list;
    
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */