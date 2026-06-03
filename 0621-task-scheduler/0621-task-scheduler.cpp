class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int m = tasks.size(), maxi = 0, rem = 0, res = 0, count = 0, cnt = 0, flag = 0;
        for(int i = 0; i < m; i++) {
            freq[tasks[i] - 'A']++;
            maxi = max(freq[tasks[i] - 'A'], maxi);
        }
        for(int i = 0; i < 26; i++) {
            if(freq[i] == maxi) cnt++;
            rem += freq[i];
            if(rem >= maxi) {
                res += maxi;
                rem -= maxi;
                count++;
            }
        }
        //cout<<rem;
        res += rem;
        if(count < n + 1) {
            if(rem) {
                rem = (maxi - rem) - 1;
                flag = 1;
            }
            if(n + 1 - (count + flag)) rem += (((n + 1) - (count + flag)) * maxi) - ((n + 1) - (count + flag));
            rem = max(rem - (count - cnt), 0);
        }
        else rem = 0;
        res += rem;
        return res;
    }
};