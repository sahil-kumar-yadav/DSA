# Dynamic Programming

## Top Down 
## Bottom Up
## space optimization

## Top to Down [n -> 0]
- step 1 : create Dp array
- step 2 : store ans in dp array 
- step 3 : base case ky just baad check if ans already exist in dp array

## Bottom up

- step 1 : create dp array
- step 2 : observe base case and intialize dp array accordingly
- step 3 : check building locgic

# Example [fibbonacci number]

# Fibonacci Number Calculation

This code provides three different methods to calculate the nth Fibonacci number: a recursive approach, a top-down dynamic programming approach with memoization, and a bottom-up dynamic programming approach. Below is a detailed explanation of each part of the code.

## Code Overview

### 1. `recurSol(int n)`

This function calculates the nth Fibonacci number using a simple recursive approach.

```cpp
int recurSol(int n)
{
    if (n == 0 || n == 1)
        return n;

    int ans = recurSol(n - 1) + recurSol(n - 2);

    return ans;
}
```

**Explanation:**
- **Base Case:** If `n` is 0 or 1, it returns `n`. This covers the first two Fibonacci numbers: `F(0) = 0` and `F(1) = 1`.
- **Recursive Case:** For other values of `n`, it calculates the Fibonacci number by summing up the results of `recurSol(n - 1)` and `recurSol(n - 2)`. This leads to an exponential time complexity, as it repeatedly calculates the same values.

### 2. `topDown(int n, vector<int> &dp)`

This function calculates the nth Fibonacci number using a top-down dynamic programming approach with memoization.

```cpp
int topDown(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);

    return dp[n];
}
```

**Explanation:**
- **Base Case:** Like `recurSol`, it returns `n` for `n = 0` or `n = 1`.
- **Memoization:** If `dp[n]` is not -1, it means the result has already been computed and stored, so it returns the stored value.
- **Recursive Calculation:** Otherwise, it calculates the result by recursively calling `topDown` for `n - 1` and `n - 2`, then stores this result in `dp[n]` to avoid redundant calculations.

### 3. `bottomUp(int n)`

This function calculates the nth Fibonacci number using a bottom-up dynamic programming approach.

```cpp
int bottomUp(int n)
{
    // step 1 create dp array
    vector<int> dp(n + 1, 0);

    // step 2 observe base case and intialize dp
    dp[0] = 0;
    dp[1] = 1;

    // step 3 check building logic
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}
```

**Explanation:**
- **Initialization:** Creates a `dp` vector of size `n + 1` initialized with zeros.
- **Base Cases:** Sets `dp[0]` to 0 and `dp[1]` to 1.
- **Iterative Calculation:** Iterates from 2 to `n`, filling `dp[i]` by summing up the previous two values: `dp[i - 1]` and `dp[i - 2]`. This approach has linear time complexity and requires linear space.

### 4. `main()`

This function demonstrates the usage of the three Fibonacci calculation methods.

```cpp
int main()
{
    int n = 8;

    int ans = recurSol(n);
    cout << "nth Fibonacci is " << ans << endl;

    vector<int> dp(n + 1, -1);
    int ans1 = topDown(n, dp);
    cout << "nth Fibonacci is " << ans1 << endl;

    int ans3 = bottomUp(n);
    cout << "nth Fibonacci is " << ans3 << endl;

    return 0;
}
```

**Explanation:**
- **`recurSol(n)` Call:** Calculates the 8th Fibonacci number using the naive recursive method and prints it.
- **`topDown(n, dp)` Call:** Calculates the 8th Fibonacci number using the top-down approach with memoization and prints it.
- **`bottomUp(n)` Call:** Calculates the 8th Fibonacci number using the bottom-up approach and prints it.

## Summary

- **Recursive Approach (`recurSol`):** Simple but inefficient for large `n` due to exponential time complexity.
- **Top-Down Approach (`topDown`):** More efficient than the recursive approach due to memoization, reducing time complexity to linear.
- **Bottom-Up Approach (`bottomUp`):** The most efficient in terms of both time and space, with linear time complexity and space complexity.

Each method is useful for understanding different approaches to solving the Fibonacci sequence problem, ranging from straightforward recursion to more optimized dynamic programming techniques.
