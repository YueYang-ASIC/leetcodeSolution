- Aka Maximum Sum of Subarray
- Dynamic Programming

## Maximum Subarray Problem

From [Wikipedia](https://en.wikipedia.org/wiki/Maximum_subarray_problem)

> In computer science, the maximum subarray problem is the task of finding the contiguous subarray within a one-dimensional array, a[1…n], of numbers which has the largest sum.

The task is to find a subarray (contiguous elements) of the given array that has the largest sum. For instance:

```
[1, 5, -1, 0, 10]
```

The answer would be `15` or the entire array (it’s also a subarray)

```
[0, -1, -5, 0, -4]
```

The answer would be `0` and so on.

## Solutions

### Brute-force

All you need is going through all sub-arrays, keep the global maximum and compare.

### Dynamic Programming (Kadane’s Algorithm)

- `O(n)` runtime complexity 
- `O(1)` space.

Following function shows the Kadane’s algorithm implementation which uses two variables, one to store the **local maximum** and the other to keep track of the **global maximum**:

```python
def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
```

So we assume that the largest subarray is the first element, then we go through `A[1:]` elements (all elements except the first one).

At each step, what we do is:

- Can current element plus the last largest sum_ help to find a largest subarray (line 4)?
- If yes, update the `max_ending_here` or our local maximum, otherwise current element is the largest subarray (array of one).
- Then update the global maximum or `max_so_far` if there is a new global maximum.

When the loop is over, return the global maximum.

## Conclusion

Kadane’s algorithm is a [Dynamic Programming](https://en.wikipedia.org/wiki/Dynamic_programming) approach to solve “the largest contiguous elements in an array” with runtime of O(n). 
