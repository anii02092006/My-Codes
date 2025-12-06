function createCounter(init) {
    // Store the current value
    let current = init;

    // Return an object with the three methods
    return {
        increment: function() {
            current += 1;
            return current;
        },
        decrement: function() {
            current -= 1;
            return current;
        },
        reset: function() {
            current = init;
            return current;
        }
    };
}

// Example usage:

const counter1 = createCounter(5);
console.log(counter1.increment()); // 6
console.log(counter1.reset());     // 5
console.log(counter1.decrement()); // 4

const counter2 = createCounter(0);
console.log(counter2.increment()); // 1
console.log(counter2.increment()); // 2
console.log(counter2.decrement()); // 1
console.log(counter2.reset());     // 0
console.log(counter2.reset());     // 0
