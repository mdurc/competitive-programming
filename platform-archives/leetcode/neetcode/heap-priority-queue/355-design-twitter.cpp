struct comparator {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        // max heap
        return a[0] < b[0];
    }
};

class Twitter {
public:
    Twitter(): count(0) {}

    void postTweet(int userId, int tweetId) {
        tweet_map[userId].push_back({count++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, comparator> max_heap;

        follow_map[userId].insert(userId);
        for (int followeeId : follow_map[userId]) {
            if (tweet_map.count(followeeId)) {
                const vector<pair<int, int>>& tweets = tweet_map[followeeId];
                int index = tweets.size() - 1;
                // add this person's most recent tweet, and add the index
                // so that we can search through the rest of this person's tweets later
                max_heap.push({tweets[index].first, tweets[index].second, followeeId, index});
            }
        }

        while (!max_heap.empty() && res.size() < 10) {
            vector<int> curr = max_heap.top();
            max_heap.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if (index > 0) {
                const pair<int, int>& tweet = tweet_map[curr[2]][index - 1];
                max_heap.push({tweet.first, tweet.second, curr[2], index - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        follow_map[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follow_map[followerId].erase(followeeId);
    }
private:
    // <count/time, tweet id>
    unordered_map<int, vector<pair<int, int>>> tweet_map;
    unordered_map<int, unordered_set<int>> follow_map;
    int count;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
