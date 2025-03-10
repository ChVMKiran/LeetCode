class Solution {
public:
    bool is_vowel(const char &ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch =='o' || ch=='u'; 
    }
    long long countOfSubstrings(string word, int k) {
        long long ans = 0;
        int i = 0, j = 0, n = word.size();
        unordered_map<char, int> vowel_count;
        int consonant_count = 0;
        vector<int> next_consonant(n);
        int next_consonant_index = n;
        for (int i = n - 1; i >= 0; i--) {
            next_consonant[i] = next_consonant_index;
            if (!is_vowel(word[i])) {
                next_consonant_index = i;
            }
        }
        while (j < n) {
            char ch1 = word[j];
            if (is_vowel(ch1)) {
                vowel_count[ch1]++;
            } else {
                consonant_count++;
            }

            while (consonant_count > k) {
                char ch = word[i];
                if (is_vowel(ch)) {
                    vowel_count[ch]--;
                    if (vowel_count[ch] == 0) {
                        vowel_count.erase(ch);
                    }
                } else {
                    consonant_count--;
                }
                i++;
            }

            while (i < n && vowel_count.size() == 5 && consonant_count == k) {
                ans += next_consonant[j] - j;
                char ch = word[i];
                if (is_vowel(ch)) {
                    vowel_count[ch]--;
                    if (vowel_count[ch] == 0) {
                        vowel_count.erase(ch);
                    }
                } else {
                    consonant_count--;
                }

                i++;
            }
            j++;
        }
        return ans;
    }
};