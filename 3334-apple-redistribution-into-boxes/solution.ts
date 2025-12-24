function minimumBoxes(apple: number[], capacity: number[]): number {
    let totalApples = apple.reduce((acc, curr) => acc + curr, 0);
    
    // Sort descending
    capacity.sort((a, b) => b - a);
    
    let boxes = 0;
    for (const cap of capacity) {
        totalApples -= cap;
        boxes++;
        if (totalApples <= 0) return boxes;
    }
    
    return boxes;
};
