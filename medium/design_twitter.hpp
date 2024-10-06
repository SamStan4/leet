#pragma once

#include "./../imports.hpp"

class Twitter
{
private:
    unordered_map<int, unordered_set<int>> following_map;
    vector<pair<int, int>> tweets;
    int feed_size;

public:
    Twitter()
    {
        this->feed_size = 10;
    }
    
    void postTweet(int userId, int tweetId)
    {
        this->tweets.push_back({tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId)
    {
        vector<int> newTwitterFeed;

        // make sure that the person is following themselvs;

        this->following_map[userId].insert(userId);

        for (int i = this->tweets.size() - 1; (i > -1) && (newTwitterFeed.size() < this->feed_size); --i)
        {
            if (this->following_map[userId].find(tweets[i].second) != this->following_map[userId].end())
            {
                newTwitterFeed.push_back(tweets[i].first);
            }
        }
        return newTwitterFeed;
    }
    
    void follow(int followerId, int followeeId)
    {
        this->following_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        this->following_map[followerId].erase(followeeId);
    }
};
