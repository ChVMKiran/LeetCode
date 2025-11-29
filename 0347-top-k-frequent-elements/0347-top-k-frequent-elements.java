class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int[] ans = new int [k];
        Map<Integer, Integer> counter = new HashMap<>();
        for(int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }
        List<Integer>[] freq = new ArrayList[nums.length + 1];
        for(int i = 0; i < freq.length; i++) {
            freq[i] = new ArrayList<>();
        }
        for(Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            freq[entry.getValue()].add(entry.getKey());
        }
        for(int i = nums.length, idx = 0; i >= 1; i--) {
            for(int num : freq[i]) {
                ans[idx++] = num;
                if(idx == k) return ans;
            }
        }
        return ans;
    }
}