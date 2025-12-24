int fruitsCmp(const void* a, const void* b) {
    return (*(int *)a) - (*(int *)b);
}

long long min(const long long a, const long long b) {
    return a < b ? a : b;
}

bool processBasket(int* basket, int* basketSize) {
    int i, j;
    for (i = 0; (i != *basketSize) && (basket[i] != -1); i++) {}
    for (j = i; (j != *basketSize) && (basket[j] == -1); j++) {}

    while (j != *basketSize) {
        basket[i++] = basket[j++];
        for (; (j != *basketSize) && (basket[j] == -1); j++) {}
    }

    *basketSize = i;

    if (i == 0)
        return true;

    int count = 1;

    for (i -= 2; i != -1; i--)
        if (basket[i] != basket[i + 1]) {
            if ((count & 1) == 1)
                return false;
            
            count = 1;
        } else
            count++;

    return (count & 1) != 1;
}

long long minCost(int* basket1, int basket1Size, int* basket2, int basket2Size) {
    qsort(basket1, basket1Size, sizeof(int), fruitsCmp);
    qsort(basket2, basket2Size, sizeof(int), fruitsCmp);

    const int minCost = min(basket1[0], basket2[0]) * 2;

    for (int i1 = 0, i2 = 0; (i1 != basket1Size) && (i2 != basket2Size);)
        if (basket1[i1] < basket2[i2])
            i1++;
        else if (basket2[i2] < basket1[i1])
            i2++;
        else
            basket1[i1++] = basket2[i2++] = -1;
    
        if (!processBasket(basket1, &basket1Size) ||
            !processBasket(basket2, &basket2Size))
                return -1;

    long long result = 0;

    for (int i1 = 0, i2 = 0, c = basket1Size; c != 0; c--)
        result += min(minCost,
            basket1[i1] < basket2[i2] ? basket1[i1++] : basket2[i2++]);

    return result / 2;
}
