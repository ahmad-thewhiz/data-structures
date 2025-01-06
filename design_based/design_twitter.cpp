// Problem Link: https://leetcode.com/problems/design-twitter/description/

class Twitter {
private:
    int idx;
    unordered_map<int, vector<pair<int, int>>>tweets;
    unordered_map<int, unordered_set<int>>followers;

public:
    Twitter() {
        idx=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(idx++, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>>feed;
        // 1. push the tweets of the user
        for(auto tweet: tweets[userId])
            feed.push(tweet);

        // 2. check if the followers of the users have tweet
        if(followers.find(userId)!=followers.end()) {
            // 3. for each follower, push their tweets
            for(int follower: followers[userId]) {
                for(auto tweet: tweets[follower])
                    feed.push(tweet);
            }
        }

        // 4. push the min(10, sizeof(feed)) into the result vector
        vector<int>res;
        int count=0;

        while(!feed.empty()) {
            res.push_back(feed.top().second);
            feed.pop();
            count++;
            if(count==10) break;
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
