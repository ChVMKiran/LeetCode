class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        set<int> st;
        int n = arrival.size(), maxFreq = 0;
        unordered_map<int, int> serverFreq;
        vector<int> ans;
        for(int i = 0; i < k; i++) st.insert(i);
        for(int i = 0; i < n; i++) {
            while(!pq.empty() && pq.top().first <= arrival[i]) {
                st.insert(pq.top().second);
                pq.pop();
            }
            if(st.empty()) continue;
            auto it = st.lower_bound(i % k);
            if(it != st.end()) {
                serverFreq[*it]++;
                maxFreq = max(maxFreq, serverFreq[*it]);
                pq.push({arrival[i] + load[i], *it});
                st.erase(it);
            }
            else {
                auto it = st.begin();
                serverFreq[*it]++;
                maxFreq = max(maxFreq, serverFreq[*it]);
                pq.push({arrival[i] + load[i], *it});
                st.erase(it);
            }
        }
        for(auto &[key, freq] : serverFreq) {
            if(freq == maxFreq) ans.push_back(key);
        }
        return ans;
    }
};