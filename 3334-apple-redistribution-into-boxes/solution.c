int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int totalApples = 0;
    for (int i = 0; i < appleSize; i++) {
        totalApples += apple[i];
    }
    for (int i = 0; i < capacitySize - 1; i++) {
        for (int j = i + 1; j < capacitySize; j++) {
            if (capacity[i] < capacity[j]) {
                int temp = capacity[i];
                capacity[i] = capacity[j];
                capacity[j] = temp;
            }
        }
    }
    int usedBoxes = 0;
    int currentCapacity = 0;
    for (int i = 0; i < capacitySize; i++) {
        currentCapacity += capacity[i];
        usedBoxes++;
        if (currentCapacity >= totalApples) {
            break;
        }
    }
    return usedBoxes;
}
