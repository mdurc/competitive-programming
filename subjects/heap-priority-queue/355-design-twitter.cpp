class Twitter {
public:
    Twitter(): m_count(0) {}
    
    void postTweet(int userId, int tweetId) {
        m_user_tweets[userId].push({m_count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {

    }
    
    void follow(int followerId, int followeeId) {
        m_user_follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m_user_follows[followerId].erase(followeeId);
    }
private:
    // user: max heap of <time, tweet id>
    unordered_map<int, priority_queue<pair<int, int>>> m_user_tweets;
    unordered_map<int, unordered_set<int>> m_user_follows;
    int m_count;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
