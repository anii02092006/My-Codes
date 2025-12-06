var createCounter = function(n) {
    let count = n; // store current count
    return function() {
        return count++; // return current count, then increment
    };
};
