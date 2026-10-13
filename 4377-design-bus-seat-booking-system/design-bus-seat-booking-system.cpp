class BusBooking {
public:
    vector<int> totalTimer[4];
    vector<int> minTimer[4];

    int countTotalTimer = 0;
    int countMinTimer = 0;
    BusBooking(int n) {
        for(int i=0;i<4;i++){
            totalTimer[i].resize(n+1,0);
            minTimer[i].resize(n+1,0);
        }
    }
    
    void toggle(string seat) {
        string y = seat.substr(1);
        int i = seat[0] - 'A';
        int j = stoi(y);

        if(totalTimer[i][j]){
            countTotalTimer -= totalTimer[i][j];
            countMinTimer -= minTimer[i][j];
            totalTimer[i][j] = 0;
            minTimer[i][j] = 0;
            return;
        }  
        totalTimer[i][j] = 1;
        if(i==0 || i==3){
            totalTimer[i][j] += 2 * totalTimer[i^1][j];
        }
        minTimer[i][j] = 1;
        countTotalTimer += totalTimer[i][j];
        countMinTimer += minTimer[i][j];

        return;
    }
    
    int getTotalTime() {
        return countTotalTimer;
    }
    
    int getMinTime() {
        return countMinTimer;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */