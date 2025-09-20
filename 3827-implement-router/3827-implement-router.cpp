class Router {
public:
    queue<vector<int>> qu;
    set<vector<int>> st;
    unordered_map<int, deque<int>> destToTime;
    int memoryLimit;
    Router(int memoryLimit) {
        this -> memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};
        if(st.count(packet)) return false;
        if(qu.size() == memoryLimit) {
            forwardPacket();
        }
        qu.push(packet);
        st.insert(packet);
        destToTime[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(qu.size() == 0) return {};
        vector<int> vec = qu.front();
        qu.pop();
        st.erase(vec);
        destToTime[vec[1]].pop_front();
        return vec;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if(destToTime[destination].size() == 0) return 0;
        auto left = lower_bound(destToTime[destination].begin(), destToTime[destination].end(), startTime);
        auto right = upper_bound(destToTime[destination].begin(), destToTime[destination].end(), endTime);
        return right - left;
    }
};