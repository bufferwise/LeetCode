class Solution {
	private static final int MAX_NUM = 12;

	private static class SumProduct {
		final int altSum;
		final int product;

		SumProduct(int altSum, int product) {
			this.altSum = altSum;
			this.product = product;
		}

		@Override
		public int hashCode() {
			return altSum * 6827 + product;
		}

		@Override
		public boolean equals(Object obj) {
			SumProduct other = (SumProduct) obj;
			return altSum == other.altSum && product == other.product;
		}
	}

	private static int maxInSet(Set<SumProduct> set, int targetSum) {
		int maxProd = 0;
		for (SumProduct sp : set)
			if (sp.altSum == targetSum && sp.product > maxProd)
				maxProd = sp.product;
		return maxProd;
	}

	private static int maxNonZeroProduct(int[] nums, int targetSum, int limit) {
		Set<SumProduct> oddSet = new LinkedHashSet<>();
		Set<SumProduct> evenSet = new LinkedHashSet<>();
		for (int x : nums) {
			if (x == 0)
				continue;
			SumProduct firstNewEven = null;
			for (SumProduct sp : oddSet) {
				int p = sp.product * x;
				if (p <= limit) {
					SumProduct spx = new SumProduct(sp.altSum - x, p);
					if (evenSet.add(spx) && firstNewEven == null)
						firstNewEven = spx;
				}
			}
			for (SumProduct sp : evenSet) {
				if (sp == firstNewEven)
					break;
				int p = sp.product * x;
				if (p <= limit)
					oddSet.add(new SumProduct(sp.altSum + x, p));
			}
			if (x <= limit)
				oddSet.add(new SumProduct(x, x));
		}
		return Math.max(maxInSet(oddSet, targetSum), maxInSet(evenSet, targetSum));
	}

	private static void mixedAdd(Set<Integer> oddSums, Set<Integer> evenSums, int a) {
		Integer firstNewEven = null;
		for (Integer x : oddSums) {
			Integer s = x - a;
			if (evenSums.add(s) && firstNewEven == null)
				firstNewEven = s;
		}
		for (Integer x : evenSums) {
			if (x == firstNewEven)
				break;
			oddSums.add(x + a);
		}
	}

	private static boolean zeroProductExists(int[] nums, Integer targetSum) {
		// With zero product
		Set<Integer> oddSumsZ = new LinkedHashSet<>();
		Set<Integer> evenSumsZ = new LinkedHashSet<>();
		// With positive product
		Set<Integer> oddSumsP = new LinkedHashSet<>();
		Set<Integer> evenSumsP = new LinkedHashSet<>();
		for (int x : nums) {
			if (x == 0) {
				oddSumsZ.addAll(evenSumsZ);
				evenSumsZ = new LinkedHashSet<>(oddSumsZ);
				oddSumsZ.addAll(evenSumsP);
				evenSumsZ.addAll(oddSumsP);
				oddSumsZ.add(0);
			} else {
				mixedAdd(oddSumsZ, evenSumsZ, x);
				mixedAdd(oddSumsP, evenSumsP, x);
				oddSumsP.add(x);
			}
			if (oddSumsZ.contains(targetSum) || evenSumsZ.contains(targetSum))
				return true;
		}
		return false;
	}

	public static int maxProduct(int[] nums, int k, int limit) {
		if ((nums.length + (k > 0 ? 1 : 0)) / 2 * MAX_NUM < Math.abs(k))
			return -1;
		int p = maxNonZeroProduct(nums, k, limit);
		return p > 0 ? p : zeroProductExists(nums, k) ? 0 : -1;
	}
}
