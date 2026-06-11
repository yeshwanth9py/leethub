// Last updated: 6/11/2026, 11:13:13 AM
class AuctionSystem {
public:
    map<int, multiset<pair<int, int>>> mp; //{bidamt, uid}
    map<pair<int, int>, int> mp2;  //{{item, uid}, bidamt}}
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(mp2.find({itemId, userId}) != mp2.end()){
            int getamt = mp2[{itemId, userId}];
            if(mp[itemId].find({getamt, userId}) != mp[itemId].end()){
                mp[itemId].erase(mp[itemId].find({getamt, userId}));
            }
        }

        mp[itemId].insert({bidAmount, userId});
        mp2[{itemId, userId}] = bidAmount;
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        if(mp2.find({itemId, userId}) != mp2.end()){
            int getamt = mp2[{itemId, userId}];
            if(mp[itemId].find({getamt, userId}) != mp[itemId].end()){
                mp[itemId].erase(mp[itemId].find({getamt, userId}));
            }
        }
        mp[itemId].insert({newAmount, userId});
        mp2[{itemId, userId}] = newAmount;
        
        
    }
    
    void removeBid(int userId, int itemId) {
        if(mp2.find({itemId, userId}) != mp2.end()){
            int getamt = mp2[{itemId, userId}];
            if(mp[itemId].find({getamt, userId}) != mp[itemId].end()){
                mp[itemId].erase(mp[itemId].find({getamt, userId}));
            }
        }
        mp2[{itemId, userId}] = -1e9;
    }
    
    int getHighestBidder(int itemId) {
        if(mp[itemId].size() == 0) return -1;
        auto it = mp[itemId].rbegin();
        int ans = (*it).second;
        if(ans == -1e9) return -1;
        return ans;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */