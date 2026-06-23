class MyCalendar {
public:
    vector<pair<int, int>> bookings;

    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto &[s, e] : bookings) {
            if (max(start, s) < min(end, e))
                return false;
        }

        bookings.push_back({start, end});
        return true;
    }
};

