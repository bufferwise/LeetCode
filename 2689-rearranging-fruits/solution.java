import java.util.*;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        Map<Integer, Integer> map = new HashMap<>();
        int minVal = Integer.MAX_VALUE;
        for (int x : basket1) {
            map.put(x, map.getOrDefault(x, 0) + 1);
            minVal = Math.min(minVal, x);
        }
        for (int x : basket2) {
            map.put(x, map.getOrDefault(x, 0) - 1);
            minVal = Math.min(minVal, x);
        }

        List<Integer> swapList = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int val = entry.getKey();
            int diff = entry.getValue();
            if (diff % 2 != 0) return -1;
            for (int i = 0; i < Math.abs(diff) / 2; i++) {
                swapList.add(val);
            }
        }

        Collections.sort(swapList);
        long totalCost = 0;
        for (int i = 0; i < swapList.size() / 2; i++) {
            totalCost += Math.min(swapList.get(i), 2L * minVal);
        }
        return totalCost;
    }
}
