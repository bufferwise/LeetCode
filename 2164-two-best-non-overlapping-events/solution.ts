function maxTwoEvents(events: number[][]): number {
    events.sort((a, b) => a[0] - b[0]);
    const n = events.length;
    const suffixMax = new Int32Array(n);
    
    suffixMax[n - 1] = events[n - 1][2];
    for (let i = n - 2; i >= 0; i--) {
        suffixMax[i] = Math.max(events[i][2], suffixMax[i + 1]);
    }
    
    let maxSum = 0;
    for (let i = 0; i < n; i++) {
        let currentVal = events[i][2];
        let low = i + 1, high = n - 1, nextIdx = -1;
        
        while (low <= high) {
            let mid = (low + high) >> 1;
            if (events[mid][0] > events[i][1]) {
                nextIdx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        if (nextIdx !== -1) currentVal += suffixMax[nextIdx];
        if (currentVal > maxSum) maxSum = currentVal;
    }
    
    return maxSum;
};
