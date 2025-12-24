class Solution {
    static bool processBasket(vector<int>& basket) {
        const int length = basket.size();

        int i, j;
        for (i = 0; (i != length) && (basket[i] != -1); i++) {}
        for (j = i; (j != length) && (basket[j] == -1); j++) {}

        while (j != length) {
            basket[i++] = basket[j++];
            for (; (j != length) && (basket[j] == -1); j++) {}
        }

        basket.resize(i);

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

public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        sort(basket1.begin(), basket1.end());
        sort(basket2.begin(), basket2.end());

        const int bl = basket1.size(), minCost = min(basket1[0], basket2[0]) * 2;
        
        for (int i1 = 0, i2 = 0; (i1 != bl) && (i2 != bl);)
            if (basket1[i1] < basket2[i2])
                i1++;
            else if (basket2[i2] < basket1[i1])
                i2++;
            else
                basket1[i1++] = basket2[i2++] = -1;
        
        if (!processBasket(basket1) || !processBasket(basket2))
            return -1;

        long long result = 0;

        for (int i1 = 0, i2 = 0, c = basket1.size(); c != 0; c--)
            result += min(minCost,
                basket1[i1] < basket2[i2] ? basket1[i1++] : basket2[i2++]);

        return result / 2;
    }
};
