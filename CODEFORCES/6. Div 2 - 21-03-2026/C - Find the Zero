C. Find the Zero
time limit per test: 2 seconds
memory limit per test: 256 megabytes

This is an interactive problem.
You are given an integer n. There is a hidden array a of length 2n. Each integer from 1 to n appears exactly once in a. The rest of the elements are all 0.
You can make the following type of query:
Choose two integers i and j (1 <= i, j <= 2n, i != j). The judge will respond with 1 if ai = aj, and will respond with 0 otherwise.
Find any integer k (1 <= k <= 2n) such that ak = 0 in no more than n + 1 queries. Note that the interactor is adaptive, which means that the hidden array a may change depending on your queries but will not contradict previous queries.

Input:
Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 10^3). The description of the test cases follows.
The first line of each test case contains an integer n (2 <= n <= 10^4). The length of the hidden array a will be 2n.
It is guaranteed that the sum of n over all test cases does not exceed 10^4.

Interaction:
To make a query, output a line in the following format:
? i j (1 <= i, j <= 2n, i != j)
As a response to the query, you will get:
1 if ai = aj;
0 if ai != aj;
-1 if you made an invalid query or if you exceed the limit of n + 1 queries.
To report the answer, output a line in the following format:
! k (1 <= k <= 2n)
After this, proceed to the next test case or terminate if this is the last test case.
Note that reporting the answer does not count towards the n + 1 queries.
The interactor is adaptive. This means that the hidden array a may change depending on your queries but will not contradict previous queries.
After printing each query do not forget to output the end of line and flush* the output. Otherwise, you will get Idleness limit exceeded verdict. If, at any interaction step, you read -1 instead of valid data, your solution must exit immediately. This means that your solution will receive Wrong answer because of an invalid query or any other mistake. Failing to exit can result in an arbitrary verdict because your solution will continue to read from a closed stream.
For this problem, hacks are disabled.

To flush, use:
fflush(stdout) or cout.flush() in C++;
sys.stdout.flush() in Python;
see the documentation for other languages.

Output:
For each test case, output the answer in the specified format.

Strategy:
This problem wants us to find the zero which boils down to either finding a query for which the output is 1 at which point both of the indices are zero since all nonzero numbers are unique or we need to exhaust all possibilities so that we can guarantee there's a zero at some position. One of my strategies was to check only half +1 of the 2n range at which point we can guarantee we have passed a 0 but then finding it is impossible anyway. The correct strategy is to get to a point where we can guarantee there's a 0 in a small enough window to be able to ask all the question we need to pinpoint its exact location. The second obvious strategy is to traverse the whole 2n range at which point we might find a zero by random or get enough information to pinpoint a 0. This is almost true. Since doing a full traversal by checking adjacent pairs will check all pairs {a1,a2},{an,an+1}, if we don't find a pair which outputs a 0 we can guarantee all the pairs have one 0, this is an edge case we need to account for. All of the pairs need to have a 0 since otherwise it would be guaranteed that there is a pair with 2 zeroes since there was a pair with 2 nonzeros. Therefore we traverse like this and if we manage to reach the end we need to somehow find a zero in the pairs. We can do this by actually not checking the last number but traversing only for all pairs until the last one which we dont check. At this point we have 2 queries left. My solution was comparing element 2n-2 with 2n-1. We know that {2n-2,2n-3} definitely has a zero inside and by doing {2n-1,2n-2} we will know if it has 2 zeroes or not. If so we have found a zero, if not we know that the tuple {2n-3,2n-2,2n-1} has at most 2 zeroes. Possibly one. Since we also know that {2n-2,2n-3} has a zero the only possible configurations are {0,A,0,B} for 2 zeroes or {A,0,B,0} and {0,A,B,0} at which point theres also a 0 at 2n. Therefore, at this point we can guarantee two zeroes at either {2n-2,2n} or {2n-3,2n-1} or {2n-3, 2n}. This is it, now we just check a pair, if it gives 1 we output one of its zeroes. If it gives 0 we look at the other 2 pairs and output the 0 they share. If we pick {0,A,0,B} we check for {2n-3, 2n-1} if the outputs 1 we found it and if it doesnt we output 2n since it is shared between the other 2 pairs.