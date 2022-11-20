/*

Helpful resources / Links

Interview Experiences
1) 2022 : Python dev intern : https://medium.com/@sahmaanwar61/alphagrep-python-developer-interview-on-campus-5385e535caf8


Question List :
- https://www.geeksforgeeks.org/make-the-string-lexicographically-smallest-non-palindromic-by-replacing-exactly-one-character/
- https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
- https://leetcode.com/problems/maximum-profit-in-job-scheduling/
- https://leetcode.com/discuss/interview-question/949904/amazon-oa2-nearest-city
- https://www.geeksforgeeks.org/compute-the-minimum-or-maximum-max-of-two-integers-without-branching/
- https://leetcode.com/problems/valid-parentheses/
- https://leetcode.com/problems/recover-binary-search-tree/

*/
// ===========================================================
/* 

1)
Recently, I interviewed for Python Developer Intern Role at AlphaGrep. AlphaGrep is a High-frequency Trading Firm(HFT) that mainly deals in securities, and so it’s also called AlphaGrep Securities. The interview process was completely based on Python, and that mainly comprised Python Logic, Multi-threading, coding questions. Some general questions from OS were also asked.

There were 4 rounds in total:

1 Coding Round on Hacker Rank (to be done in Python)
3 Technical/CodePair Round
Coding Round

The Coding Round was conducted on Hacker Rank, with four questions to be done in Python. The duration of the test was 90 minutes. The questions were—

A string is given and we are required to return a new string by altering only one letter such that the resultant string is smallest possible and not a palindrome.
Make the string lexicographically smallest and non palindromic by replacing exactly one character …
Given a palindromic string str containing only lowercase letters, the task is to print the lexicographically smallest…
www.geeksforgeeks.org

A question on scheduling — maximum number of events that could be scheduled. We are given two lists containing start and end time for each event, and we need to return the maximum number of possible events without conflict. I employed a greedy approach by sorting the events in ascending order based on the end time of each event, finally doing a linear sweep, incrementing a counter and finding max value.
Maximum Number of Events That Can Be Attended - LeetCode
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at and ends at . You can…
leetcode.com

A question on Graphs but it simply boiled down to using dictionary. There are friends and each friend node has some value, share some interests with many other nodes via some edges which had their own weights. We needed to output the maximum product of two nodes which are connected via maximum single edges. Ostensibly, the weight of the edges were of no use. Even the question itself could be solved using just maps, and no graph structure was needed per se.
A classical problem on Weighted Interval Scheduling. There is some Taxi and there is 1d path that begins at 0. We needed to find the maximum fare the Taxi Driver can get such that each customer pays for his trip length(dest — src) + some extra tip. I used Binary Search + DP to solve this problem.
Maximum Profit in Job Scheduling - LeetCode
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of…
leetcode.com

Technical/CodePair Round 1

The Interviewer was the VP of Data Engineering Team. He introduced himself, talked about the kind of work he and his team did. Then he asked me some general questions on Python, multi-threading and multi-programming. Next he asked me to head to the CodePair Link, wherein there was one coding question that goes like —

“A list of numbers is given and we must find the number that has the max difference between the beginning and ending, and the count of that number should be same as spread(max no. of occurrences of any particular number) of the list.”

I employed a brute-force approach and it gave me TLE on longer test cases. Then, I incorporated a dictionary storing the beginning and ending of each number for which has the count is same as spread. After this, all the test cases passed and the interviewer was satisfied. We then moved to second question, which again was a simple one. It goes like this —

“A very long document comprising of English sentences is given. We need to read the file and return the list of words arranged on their frequency of occurrences.”

I employed an iterator to open the file, reading character by character and appending the same to a string that will be finally processed to find the words. But, the interviewer pointed out that since the file is very large, the subsequent string would take up much redundant space and may even overflow. So, I then proposed an online processing scheme — read each character and process it in the same loop. Now, since the redundant space was solved, we moved to the next part.

Next, he asked a Question that was similar to the Producer-Consumer Problem that goes like this —

“A stream of data is available within certain stipulated time. We need to download this data and apply some form of processing to this data. We need to design a system that does this.”

I proposed a multi-threading example just like the Producer-Consumer Problem, wherein there is a global buffer that is accessed via a lock for mutual exclusion. The Downloader(Receiver) thread gets activated when the stipulated period starts, downloads data into its own local buffer. once the transfer is complete, it tries to write this into the global buffer. The Computing Thread consumes the global buffer, applying the necessary computations. The interviewer was satisfied with this approach.

Technical/CodePair Round 2

In Round 2, the interviewers were two senior members of the Data Engineering Team at AlphaGrep. They both introduced themselves taking turns. The first interviewer inquired if I had worked with numpy and pandas library in Python, and I nodded in agreement. Then he asked me some general questions on Python and following which he asked me to head to the CodePair Link, wherein there was one coding question that goes like —

“A map in the form of a 2D Grid was given, and there were a number of cities. For any given city, we needed to find the nearest city that either shares the x coordinate or y coordinate with the given city. If more than one city satisfies the nearest criteria, output the one that is alphabetically least. Write a function that takes input four lists — name, list of queries, x coordinate and y coordinate for the cities, and returns the nearest city for each query city.”

Amazon | OA2 | Nearest City - LeetCode Discuss
Anyone can provide the solution, java plz: Given a list of points, find the nearest points that shares either an x or a…
leetcode.com

I employed a brute-force approach and it gave me TLE on longer test cases. For optimization, I incorporated two dictionaries that stored the x and y coordinates of the cities. For dictionary 1, the key was the x coordinate and the value was a list of y coordinate for each city that had the particular x coordinate, and similarly, dictionary 2 stored the opposite. The list was sorted in ascending order, so that Binary Search could be employed to search in O(log n) time. Finally, all test cases passed after this.

The second interviewer then quizzed me on the difference between Process and Thread, memory management in Python. And after this, Round 2 concluded.

Technical/CodePair Round 3

In Round 3, the interviewer was a senior member of the Data Engineering Team at AlphaGrep. He introduced himself and straightaway jumped into Python basics. He asked me about deep and shallow copy, *args and **kwargs , pass by value and pass by reference in Python. He also slightly touched the concept of closure, scope and use of keyword global. Then, he asked me to head to the CodePair Link, wherein there were 3 coding/logic questions —

Write a function to min(a, b) to find min of a and b, provided that we cannot use conditional like if…else, ternary operator, etc. I employed a dictionary-based approach dict = {True: a, False:b} and return dict[a < b].
Compute the minimum or maximum of two integers without branching - GeeksforGeeks
On some rare machines where branching is expensive, the below obvious approach to find minimum can be slow as it uses…
www.geeksforgeeks.org

Given a string expression consisting of ‘{}()[]’, we need to check whether the expression is balanced or not. I employed stack-based approach. The interviewer asked me what if there are other characters as well, but we need to ignore it. So, I just added an extra conditional and it worked fine.
Valid Parentheses - LeetCode
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is…
leetcode.com

Swap two incorrect nodes in a BST. I employed a modified version of in-order search and it worked.
Recover Binary Search Tree - LeetCode
You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by…
leetcode.com

Finally, Round 3 concluded and I got positive reviews from the Interviewer.

I was informed by the HR that I was selected for the role of ‘Automation Engineer Intern’. The HR also enlisted the perks that I would be entitled to as an intern, and that’s how I got an offer from AlphaGrep.

Key Takeaways
If you are interviewing for an HFT firm, you should have at least some idea about operating system and computer architecture. Some question hither and thither may pop up which may require a good understanding of fundamental concepts.
Practice Questions on LeetCode would certainly help in cracking almost any interview.
Always start with the most basic solution, i.e., Brute Force and then optimize it piece by piece until you get to the best optimized code. If you are stuck at any point, be ready to take help from the interviewer.
Company Archives on GFG or Medium is a very good place to get started before any interview.

*/