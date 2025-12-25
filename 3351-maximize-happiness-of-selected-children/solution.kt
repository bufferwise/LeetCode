class Solution {
    fun maximumHappinessSum(happiness: IntArray, k: Int): Long {
        happiness.sort()
        
        var total: Long = 0
        val n = happiness.size
        
        for (i in 0 until k) {
            val currentVal = happiness[n - 1 - i] - i
            
            if (currentVal <= 0) break
            
            total += currentVal.toLong()
        }
        
        return total
    }
}
