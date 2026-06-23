class MyCalendarTwo {
public:
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> overlaps;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for (auto &[s, e] : overlaps) {
            if (max(start, s) < min(end, e))
                return false;
        }


        for (auto &[s, e] : bookings) {
            if (max(start, s) < min(end, e)) {
                overlaps.push_back({max(start, s), min(end, e)});
            }
        }

    
        bookings.push_back({start, end});
        return true;
    }
};

