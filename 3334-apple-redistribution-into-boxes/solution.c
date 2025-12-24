int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int totalApples = 0;
    for (int i = 0; i < appleSize; i++) {
        totalApples += apple[i];
    }

    int compare(const void *a, const void *b) {
        return (*(int*)b - *(int*)a);
    }
    qsort(capacity, capacitySize, sizeof(int), compare);

    int count = 0;
    while (totalApples > 0) {
        totalApples -= capacity[count];
        count++;
    }
    return count;
}
