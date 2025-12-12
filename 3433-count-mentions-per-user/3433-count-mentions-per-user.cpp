class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(), [](vector<string> &e1, vector<string> &e2) {
            int t1 = stoi(e1[1]), t2 = stoi(e2[1]);
            if(t1 == t2) return e1[0] > e2[0];
            return t1 < t2;
        });
        vector<int> ans(numberOfUsers);
        int n = events.size();
        unordered_set<int> ust;
        for(int i = 0; i < numberOfUsers; i++) ust.insert(i);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &event: events) {
            string mode = event[0], mentions = event[2];
            int time = stoi(event[1]);
            while(!pq.empty() && pq.top().first <= time) {
                ust.insert(pq.top().second);
                pq.pop();
            }
            if(mode[0] == 'M') {
                if(mentions[0] == 'A') {
                    for(int i = 0; i < numberOfUsers; i++) {
                        ans[i]++;
                    }
                }
                else if(mentions[0] == 'H') {
                    for(auto &u: ust) {
                        ans[u]++;
                    }
                }
                else {
                    string mention;
                    stringstream ss(mentions);
                    while(ss >> mention) {
                        string str = mention.substr(2);
                        int id = stoi(str);
                        ans[id]++;
                    }
                }
            }
            else {
                int id = stoi(mentions);
                ust.erase(id);
                pq.push({time + 60, id});
            }
        }
        return ans;
    }
};