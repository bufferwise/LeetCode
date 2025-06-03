/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let s= x.toString()
    let reversed = s.split('').reverse().join('')
    let n = parseInt(reversed)
    const max=2**31-1
    const min=-(2**31)
    if(n>max||n<min)
    {
        return 0
    }
    else
    {
if(x<0)
        return -n
        else 
        return n
    } 
};
