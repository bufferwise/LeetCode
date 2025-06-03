var reverse = function(x) {
    function helper(x, rev) {
        if (x === 0) return rev;
        if (rev > Math.trunc(2147483647 / 10) || rev < Math.trunc(-2147483648 / 10)) return 0;

        let rem = x % 10;
        x = Math.trunc(x / 10);
        rev = rev * 10 + rem;

        return helper(x, rev);
    }

    return helper(x, 0);
};
