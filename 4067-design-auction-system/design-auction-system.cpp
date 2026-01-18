class AuctionSystem {
public:
    AuctionSystem() {}
    using T = pair<int, int>;
    map<T, int> getAmount;
    map<T, set<int>> getUserID;

    void updateBid(int userId, int itemId, int newAmount) {
        T key = {userId, itemId};
        int oldAmount = getAmount[key];
        getAmount[key] = newAmount;
        getUserID[{itemId, -oldAmount}].erase(-userId);
        if(getUserID[{itemId, -oldAmount}].size() == 0){
            getUserID.erase({itemId, -oldAmount});
        }
        getUserID[{itemId, -newAmount}].insert(-userId);
    }
    void addBid(int userId, int itemId, int bidAmount) {
        T key = {userId, itemId};
        if (getAmount.find(key) != getAmount.end()) {
            updateBid(userId, itemId, bidAmount);
        } else {
            getAmount[key] = bidAmount;
            getUserID[{itemId, -bidAmount}].insert(-userId);
        }
    }

    void removeBid(int userId, int itemId) {
        T key = {userId,itemId};
        int Amount = getAmount[key];
        T key2 = {itemId,-Amount};
        getAmount.erase(key);
        getUserID[key2].erase(-userId);
        if(getUserID[key2].size()==0){
            getUserID.erase(key2);
        }
    }

    int getHighestBidder(int itemId) { 
        auto it = getUserID.lower_bound({itemId, INT_MIN});
        auto end = getUserID.upper_bound({itemId, INT_MAX});
        for(;it!=end;it++){
            if(it->second.size()){
                return -*it->second.begin();
            }
        }
        return -1;
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