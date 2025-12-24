function minCost(basket1: number[], basket2: number[]): number {
    const map = new Map<number, number>();
    let minVal = Infinity;

    for (const x of basket1) {
        map.set(x, (map.get(x) || 0) + 1);
        minVal = Math.min(minVal, x);
    }
    for (const x of basket2) {
        map.set(x, (map.get(x) || 0) - 1);
        minVal = Math.min(minVal, x);
    }

    const swapList: number[] = [];
    for (const [val, diff] of map.entries()) {
        if (diff % 2 !== 0) return -1;
        const count = Math.abs(diff) / 2;
        for (let i = 0; i < count; i++) {
            swapList.push(val);
        }
    }

    swapList.sort((a, b) => a - b);
    let totalCost = 0;

    for (let i = 0; i < swapList.length / 2; i++) {
        totalCost += Math.min(swapList[i], 2 * minVal);
    }

    return totalCost;
}
