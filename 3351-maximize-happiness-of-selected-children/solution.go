import (
    "slices"
)

func maximumHappinessSum(happiness []int, k int) int64 {
    slices.SortFunc(happiness, func(a, b int) int {
        return b - a
    })

    var total int64 = 0
    
    for i := 0; i < k; i++ {
        val := happiness[i] - i
        
        if val <= 0 {
            break
        }
        
        total += int64(val)
    }

    return total
}
