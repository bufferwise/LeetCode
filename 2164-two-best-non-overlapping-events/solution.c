#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi2,mmx,sse2,sse3,sse4")

#define START 0
#define END 1
#define VALUE 2


int compare_func(const void* a, const void* b) {
    int arg1 = (*(const int**)a)[START];
    int arg2 = (*(const int**)b)[START];

    if (arg1 < arg2) {
        return -1;
    } 
    if (arg1 > arg2) {
        return 1;
    }

    return 0;
}

inline void binarySearch(int** events, int left, int right, int end_val, int* res) {
    if (left > right) {
        return ;
    }

    int mid = (left + right) >> 1;

    if (events[mid][START] > end_val) {
        if (mid < *res) {
            *res = mid;
        }

        binarySearch(events, left, mid - 1, end_val, res);
    } else {
        binarySearch(events, mid + 1, right, end_val, res);
    }
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {

    qsort(events, eventsSize, sizeof(int*), compare_func);

    int suffix_max[eventsSize];
    memset(suffix_max, 0, eventsSize * sizeof(int));

    suffix_max[eventsSize - 1] = events[eventsSize - 1][VALUE];
    for (int i = eventsSize - 2; i >= 0; i--) {
        if (events[i][VALUE] > suffix_max[i + 1]) {
            suffix_max[i] = events[i][VALUE];
        } else {
            suffix_max[i] = suffix_max[i + 1];
        }
    }

    int next_event = 0;
    int cur_event = 0;

    int ret = INT_MIN;

    for (int i = 0; i < eventsSize; i++) {
        int res_next = INT_MAX;
        
        binarySearch(events, i, eventsSize - 1, events[i][END], &res_next);

        int cur_val;

        if (res_next < INT_MAX) {
            cur_val = events[i][VALUE] + suffix_max[res_next];   
        } else {
            cur_val = events[i][VALUE];
        }

        ret = (ret > cur_val)? ret : cur_val;
    }

    return ret;
}
