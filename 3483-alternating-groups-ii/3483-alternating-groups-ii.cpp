class Solution
{
    public:
        int numberOfAlternatingGroups(vector<int> &colors, int k)
        {
            int j = 0, count = 0, i = 1, n = colors.size();
            while (j < n)
            {
                if (colors[(i - 1) % n] == colors[i % n])
                {
                    j = i;
                    if (i >= n && j >= n) break;
                }
                if (i - j == k - 1) count++, j++;
                i++;
            }
            return count;
        }
};