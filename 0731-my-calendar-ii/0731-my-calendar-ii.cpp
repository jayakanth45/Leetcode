class MyCalendarTwo {
public:
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> doublebookings;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        for(auto pr:doublebookings){
            int strt = pr.first;
            int en = pr.second;
            if(max(strt,start)<min(end,en)){
                return false;
            }
        }
        for(auto pr: bookings){
            int strt = pr.first;
            int en = pr.second;
            if(max(strt,start)<min(end,en)){
                doublebookings.push_back({max(strt,start),min(end,en)});
            }
        }
        bookings.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */