class Solution {
    public String sortVowels(String s) {
        String vowels = "AEIOUaeiou";
        int n = s.length();
        int freq[] = new int[128];
        char arr[] = s.toCharArray();
        for (char c : arr) {
            if (vowels.indexOf(c) != -1) {
                freq[c]++;
            }
        }
        int j = 0;
        for (int i = 0; i < vowels.length() && j < n; i++) {
            char v = vowels.charAt(i);
            int count = freq[v];

            while (count-- > 0) {
                while (j < n && freq[arr[j]] == 0) {
                    j++;
                }
                if (j < n) {
                    arr[j++] = v;
                }
            }
        }

        return new String(arr);
    }
}
