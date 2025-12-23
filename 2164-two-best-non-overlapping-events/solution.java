class Solution {
    public int maxTwoEvents(int[][] events) {
        
Arrays.sort(events, (a, b) -> a[0] - b[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);

        int maxSingle = 0, result = 0;

        for (int[] event : events) {
            int start = event[0], end = event[1], value = event[2];

            while (!pq.isEmpty() && pq.peek()[1] < start) {
                maxSingle = Math.max(maxSingle, pq.poll()[2]);
            }

            result = Math.max(result, maxSingle + value);
            pq.offer(event);
        }

        return result;

    }
}
