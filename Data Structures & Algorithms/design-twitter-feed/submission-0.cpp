class Node {
public:
    pair<int,int> tweet;
    Node* next;
    Node(pair<int,int> val) {   
        tweet=val;
        next=nullptr;
    }
};


class Twitter {
public:

    unordered_map<int,unordered_set<int>> followers;
    Node* head;

    Twitter() {
        head=NULL;
    }
    
    void postTweet(int userId, int tweetId) {
        Node* t= new Node({userId,tweetId});
        t->next=head;
        head=t;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        Node* t=head;
        while (ans.size()<10 && t) {
            if (t->tweet.first==userId || followers[userId].count(t->tweet.first)) ans.push_back(t->tweet.second);
            t=t->next;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
