class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> table;
        long long result = 0;
        for(auto& word : words) {
            const auto front = word.front();
            for(auto& c : word) {
                c = c >= front ? c - front : 'z' - front + c - 'a' + 1;
            }
            result += table[word]++;
        }
        return result;
    }
};