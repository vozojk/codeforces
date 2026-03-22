You are given an array of n integers, and your task is to find four values (at distinct positions) whose sum is x.

Input:
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.

Output:
Print four integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.

Constraints:
1<=n<=1000
1<=x,a_i<=10^9

Strategy:
Here we make use of the fact that target=A+B+C+D=(A+B)+(C+D) we can do basically the same thing as in 2 sum just with double the numbers. We do a double for loop (i=0, j=i+1). This picks 2 numbers, the overall target minus their sum is our target for the other two. For this we use a hashmap. We check is there is anything already at map[SmallTarget], if there is not we put all the pairs {numAtJ, anyNumberBeforeJ} in the hashmap and use their sum as the key. This way we always add all the pairs that are newly discovered by moving j in the outer (the inner loop is i) for loop by 1. This way we can be sure we iterate through all of the pairs but also that there are no duplicates since we always add only previous pairs, not the whole array. All the pairs containing J with a second index bigger than J will be added later. We traverse the whole array like this. If nothing is found we output impossible.
Note: The normal O(n^3) strategy also works here with a bit of optimization solving the most time-consuming problem in 0.3s. This strategy is much better and elegant that's why it's used.