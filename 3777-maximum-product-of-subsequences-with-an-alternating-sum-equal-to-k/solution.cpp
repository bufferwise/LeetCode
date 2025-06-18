struct Range { int val, min, max, smallest_digit; };
vector<Range> range;
int L;
int bestProduct = -1;

class Solution {
public:
  static void choose(int i, unsigned long long prodSoFar, int k) {
    if (bestProduct == L) return;
    if (k > range[i].max || k < range[i].min) return;
    if (prodSoFar*range[i].smallest_digit > L) return;
    for(int j = i; j < range.size()-1; ++j) {
      unsigned long long newProd = prodSoFar * range[j].val;
      if (k == range[j].val && newProd <= L) bestProduct = max<int>(newProd, bestProduct);
      if (bestProduct == -1 || (newProd > 0 && newProd <= L))
        choose(j+1, newProd, range[j].val - k);
    }
  }
  int maxProduct(const vector<int> &nums, int k, int limit) {
    range.resize(nums.size()+1);
    range[range.size()-2] = { nums.back(), 0, nums.back(), nums.back() };
    for(int i = (int)nums.size()-2; i >= 0; --i) {
      range[i].val = nums[i];
      range[i].max = max(range[i+1].max, nums[i] - range[i+1].min);
      range[i].min = min(range[i+1].min, nums[i] - range[i+1].max);
      range[i].smallest_digit = min(nums[i], range[i+1].smallest_digit);
    }
    bestProduct = -1;
    L = limit;
    choose(0, 1, k);
    return bestProduct;
  }
};
