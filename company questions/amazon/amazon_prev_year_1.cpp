/*
-------------------------------------------------------------------------------------------------------------------------------------------------------
** Link to this file's content : https://leetcode.com/discuss/interview-question/1590162/amazon-final-interview-questions-all-combined-2021-sde-new-grad
(pasting content here just in case Leetcode delete's this content)
-------------------------------------------------------------------------------------------------------------------------------------------------------

Amazon Final Interview Questions | All Combined 2021 | SDE & New Grad
299
Anonymous User
Anonymous User
November 21, 2021 8:48 PM

55.8K VIEWS

Amazon Final Interview Questions
A copy of my personal incomplete list of questions I found on Amazon's Interview process from end of 2020 - 2021.
Purposely very verbose so as to allow to find the original post (via google search).
Feel free to comment missing questions so that I add them to the list.

Onsite
All Combined 2021 | SDE & New Grad

Tips
I feel like to pass the onsite interview, you must demonstrate stong leadership principles and communication skills. The problems weren't too hard so I'm guessing they're looking to see if you can clearly explain your thought process.

I personally think I will not get the offer because from my experience you either have to get everything perfect or you will fail. For me I can only say 2/4 interviews went perfectly thus I probably will get rejected. Alas, I do have another final round interview this August so I have another chance.

One Leetcode Medium Question. Rather than the actual code, they were mostly interested in how I approach the problem and I had to speak aloud about my thought process in solving the problem. Heard back within 3 business days that they would like to extend the offer. If you practice Leetcode with full concentration then there is no reason not to clear the interviews at big companies. With regards to LP, if you have 2 scenarios which you can explain in detail for each of the LP principles, you are golden. All the best for everyone who is preparing.

Finally, one last piece of advice. Please, PLEASE, avoid remembering the exact questions, but rather focus on learning the actual patterns, data structures, and logic behind each exercise.

Experience -

Initial 20 minutes they will ask you LP questions only. Its not like they will ask just one or two questions on LP.

Next 20 minutes will be dedicated to coding. Links to coding platform will be shared. They wont be able to compile the code, but will see the way you are coding. One thing common in all rounds were they wanted me to write the code in OOD format. It was not like i just wrote the method and its done. They wanted me to write the object creation, function calls etc. I was not done with full implementation in round 1 and round 3, they stopped me like 2 minutes before 20 minutes are completed and asked me to write the OOD format for whole code.

NOTE - I was not able to complete full implementation but i explained the approach very well, step by step. Its okay to go back and forth sometimes, just tell them i am thinking out loud, i am making connections to find optimal way :)

3 Last five minutes were just if i have any questions for them.

Finally I would suggest anyone who is appearing for the Amazon technical interview to focus on proper naming of variables and code readability and reusabality aspects as well.

Questions
Old https://leetcode.com/discuss/interview-question/488887/amazon-final-interview-questions-sde1 Amazon Final Interview Questions | SDE1 - Google Docs

Number of Islands,

Level Order (and Zigzag) Tree Traversal,

Word Series (Word Ladder 1 & 2, Word Break 1 & 2, Word Search 1 & 2).

"parking lot" OOD question

Bloomberg | Software Engineering Intern | London | January 2020 [Offer] - LeetCode Discuss

Amazon Dublin Ireland | Onsite - SDE New Grad 2021 | Income Calculator - LeetCode Discuss

What are Design patterns? example and explanation? https://leetcode.com/discuss/interview-experience/1060893/amazon-sde-new-grad-2021-dublin-experience-offer

Round2 Onsite: This was a class design. In the beginning, there were 2 LP questions then he asked how a hash table is implemented as a starter and then asked to design a file system and implement search on the filesystem based on certain parameters (like file size creation date etc)

https://leetcode.com/discuss/interview-question/609070/Amazon-OOD-Design-Unix-File-Search-API

Round 3: Bar raiser Basically asked LP questions and asked to Design a task scheduler (in memory) and then implement a function that finds the time a certain task takes to complete (given that there exist tasks that have to be executed before it )

Round 4: Simple Number of islands question along with LP questions

1 OOP questions variant of UNIX command, Game of Life Question and Iterator Question.

Remove all duplicate numbers from a list.

https://leetcode.com/problems/min-stack/ However, it came with the constraint that we would be needing extra O(n) space. I was also asked to implement exception handling to deal with situations when you call pop() or getMin() on an empty stack.

First round: 2-3 behavioral questions followed by a coding question. The question was given a binary tree find a subtree within the binary tree that adds up to a certain target sum.

Second round: 2-3 behavoral questions followed by an OOD question. The question was a bit vague and I had a hard time understanding their english but essentially it was to design a wharehouse class that had certain constraints such that the particular wharehouse could only store certain products.

Fourth round: 2-3 behavioral questions. This was another coding round, which involved taking a string that say said "This sweater cost $40 dollars." The objective was to take that number and apply a 20% discount and return the string back with the updated price, i.e., "This sweater cost $32 dollars.".

This round was interesting since it was not any of the Leetcode questions. I was given certain conditions for a valid transaction and I had to write a function that will determine if the transaction is valid or not. The goal of this round was to see how I can write a maintainable and scalable code. For example, how can we add more conditions for a valid transaction and still not alter the main function very much. I had LP questions as part of this round also.

Find the count of a given sequence that appears in an array. There can be any amount of characters between the numbers of the sequence. ex 4,5,6,2 would have a count of 1.

sequence 4,6,2

array [ 3, 4, 4, 6, 7, 8 , 2, 6, 9, 2]

count of sequences: 6
https://leetcode.com/discuss/interview-question/437362/amazon-sde-count-of-sequences-within-an-array

2 LP´s and Medium exercise on Trie Structure (make sure you know how to use a Trie, the Explore section here has a really good card on it). Really similar to an Amazon tagged exercise.

2 LP´s, then started with an extremely simple exercise, and afterwards, the interviewer started adding complexity, to see how I adapted my solution so that it scaled. The interviewer was testing my knowledge on Object Oriented Design, which I use in my everyday work, but had not prepared for the interview. This was almost a disaster, my solution was far from good.

Course Schedule II -

Given huge database of sentences, write a class to find most frequently used words

Questions on data structures like array list, linked list, hash table, binary search tree. Differences between these data structures and when would you use which one. Inheritance and Composition.

Coding: Design a Tic Tac Toe Game

Given a graph and destination D, find shortest path between all nodes. Not given any graph implementation, and input is a list of edges ([1,2,3] = Node 1 to Node 2, distance 3). Had to implement my own adjacency list and "nodes" (Dijkstra's Algorithm)

Similar to this question, but exclude the combined word (ex. instead of [['car','super', 'supercar'], the answer is [['car','super'],)https://leetcode.com/discuss/interview-question/314550/amazon-onsite-interview-concatenated-words

https://leetcode.com/problems/copy-list-with-random-pointer/

https://leetcode.com/problems/longest-happy-prefix/

https://leetcode.com/problems/insert-interval/

Design a system to generate and apply coupons for e-commerce site based on product and its category.

https://leetcode.com/problems/lfu-cache/

Find the next value from the target node using BST

https://leetcode.com/problems/string-to-integer-atoi/

Longest common prefix among an array of strings - but the longest between any two (instead of the longest in all)

https://leetcode.com/problems/boundary-of-binary-tree/

https://leetcode.com/problems/integer-to-roman/

K most frequent items(item_id) in a stream. Input is a stream of (item_id,timestamp).

This I was able to easily solve using hashmap and min-heap

Then, Interviewer asked me to find frequent items in last hour given a timestamp.

For example, Given time 6:07 PM, Return k most frequent items from 5:07 PM to 6:07 PM.

Gave an answer using queue, hashmap and min-heap, Not an optimal answer, But it worked.

Three sum

Round 1 - 2 interviewers https://leetcode.com/discuss/interview-experience/1060893/Amazon-SDE-new-grad-2021-Dublin-Experience-or-Offer/854173

Implement queue using stack
Find loop in single linkedlist
find missing element in an array
Explain any sorting algorithm
Time and space complexity for the above problems
Difference similarity between list, linkedlist and array
Implementation of Hashmap
Difference between set, hashmap, list
Round 2 - 1 inerviewer

2 LP questions
What are Design patterns? example and explanation?
Best coding practices
https://leetcode.com/problems/integer-to-english-words/
Time complexity for the above problem
Round 3 - 1 interviewer

Print matrix spirally. Time and space complexity for the above problem
Given an array of large numbers and a number K, give an algorithm to search for a triplet whose sum is K. You can modify the array. You can print any triplet whose sum is K.

After basic introduction, the interviewer asked me questions about Hashmaps. such as time complexity and how to handle collisions. And he asked me how would I implement a structure to store contact informations(phones numbers, names and area codes). I think I did ok in this part, and the interviewer agreed with me on how I would use a hashmap to do so.

https://leetcode.com/problems/valid-parentheses/

Merge List + find Top K Elements , I solved this using a Heap to merge the Lists, and a later variation involved using BFS, basically the question was , Recommend a user features that are used by friends and friends of friends N - level deep. Given an api which can give you user's friends and friends most used features.

https://leetcode.com/problems/number-of-islands/

https://leetcode.com/problems/knight-probability-in-chessboard/

Given a positive integer N, and a starting point 1 one can perform any of the following 2 operations in one step: https://leetcode.com/discuss/interview-experience/906535/amazon-sde-i-bangalore-october-2020-offer

Add 1 to the number
Double the number
The task is to find the minimum number of steps to reach N (desired complexity O(log n)).

Given a set of N numbers (both positive and negative) sorted in increasing order with A[i] < A[j] for all i<j, find whether there exists an index i (i = 1 .. N) such that A[i] = i. If multiple answers are present return any one of them. (desired complexity O(log n)).

Give the design of an automated valet parking system with the following specifications:

There are 3 parking areas (each of different sizes) for 3 different vehicle sizes - small, medium and large.
Small one can accommodate only small vehicles, medium can accommodate small and medium vehicles and similarly for the large one.
Design a system which issues a parking ticket to a vehicle entering the lot with the optimal parking space allotted to it. For eg., if a medium vehicle arrives and both medium and large parking areas have vacant spaces, the vehicle should be allotted the medium slot.
Also design a syntax for the token ID which is generated when each vehicle enters the lot. The ID should be uniquely able to determine the details of the slot where the vehicle is parked for smooth parking and un-parking.
Provide the class design of the same.
Virtual Onsite Round 3 (Bar Raiser, Coding + CS Fundamentals)

Given a set of N integers find the kth largest contiguous subarray sum.
Questions on OS like describe the boot up process of OS.
Difference between caching, paging and buffering.
Difference between stack and heap memory, calloc and malloc, etc.
Things to keep in mind while designing a software product (scalability, memory leaks, deadlocks).
Design a restaurant table booking system with the following specifications:

The restaurant has X tables of size 2, Y tables of size 3 and Z tables of size 4.
There are 3 slots from 6:30 pm to 11 pm, each of 1.5 hrs.
Restaurant can take bookings upto 7 days in advance.
No two parties will share a table.
A pack of size N should always be assigned the largest table available.
Wastage of seats should be minimised.
Provide the database structure to support the above constraints (space should be optimised).
Provide an algorithm to allot table to an incoming reservation with the following specs:
Allot table(s) to a group of N people for the ith day and the jth slot.
Provide pseudo code for the algorithm stated above.
Search for smallest element in sorted rotated list

Tell me about a situation when you had a tight deadline and what are the sacrifices you made to achieve the deadline.

TTL LRU Cache.
https://leetcode.com/discuss/interview-question/284925/ttl-lru-cache

Tell me about a time you couldn't finish your task within the given deadline.

flatten a hierarchical linked list.

A variant of topological sort in a graph.

Find smallest +ve missing integer from given array without extra space.

(follow up : Array can contain both positive and negative numbers).

Ex : ar [1,9,8] output :2

You have locking suitcase system (the one in which there will be number codes). Find the minimum number of steps to reach from given number to target number. You can move any place digit at a time. (for n-digit codes, discuss complexity). Ex : start : 0-0-1Target : 1-0-0 min steps = 2 …..changing an xth place digit by b will be counted as b steps. follow -up...what if you are not allowed to use certain numbers(not digits but whole number )(given as array)Ex: [100,234,115]

Implement a custom collection class with add, remove and getRandomOperations in O(1) time

https://leetcode.com/discuss/interview-question/1586723/amazon-sde-3-interview-question

https://leetcode.com/discuss/interview-question/system-design/685338/microsoft-onsite-design-the-t9-predictive-text-algorithm-and-system (not sure)

https://kobejean.github.io/algorithms/2020/03/08/the-award-budget-cuts-problem/

Poker Cards Game

As we all know that poker cards have four suites: Spades, Hearts, Clubs and Diamonds with figures from 1 to 13.

Now you are given a set of poker cards, you can pick any one card as the first card. And except for the first card, you can only pick the card that has the same suit or figure with the previous one.

Return the max number of cards you can.

For example: [(H, 3), (H, 4), (S, 4), (D, 5), (D, 1)], it returns 3 as follows: (H,3)-->(H,4)-->(S,4)

https://leetcode.com/discuss/interview-question/1030942/Amazon-Onsite-Inteview-Poker-Cards-Game

Given a game board| B ||A | C | D||E | F | G ||H | I | J|Rules of movinga. you can not move to same row.b. you can not move in same column.Given a starting point and number of moves tell the number of possible options https://leetcode.com/discuss/interview-question/1170079/amazon-onsite-imdb-team

Given an array of integers(pos/neg) in sorted order, return an array of elements square in sorted order.

Given an array of wine prices, any given year you can sell a bottle of wine only from either of the ends. Bottle of wine increases every year. Find max profit after selling all.

Given a uni-directed graph with numbers find maximum root to leaf sum with using only internal data structure.

https://leetcode.com/problems/binary-tree-maximum-path-sum/

https://leetcode.com/problems/word-break/

Given a dictionary of words and a string, state if the string if broken into multiple words consists of dictionary words.

I explained him the standard solution using BFS which is O(n) time ans O(n) space.However, the interviewer was deeply interested with me solving the question via making a Graph and then solving it.

https://leetcode.com/discuss/interview-question/600412/Amazon-onsite

A very similar question to this , same concept of BFS will applyGiven a 2D grid, each cell is either a zombie 1 or a human 0. Zombies can turn adjacent (up/down/left/right) human beings into zombies every hour. Find out how many hours does it take to infect all humans?https://leetcode.com/discuss/interview-question/411357/ Amazon | OA 2019 | 🧟‍♀️ Zombie in Matrix - LeetCode Discuss

given a list of unique strings, if the last char at string A match first char at string B then you can append them together: good+dog -> goodog . Now return the longest possible string (length of concatenated String, not the string number). https://leetcode.com/discuss/interview-question/250623/Onsite-question-for-Amazon-String-concatenation(Updated)/246655

Convert BST to Doubly Linked List without deforming tree and without using extra space except used for creating List. So this shouldn’t be done inplace.Time and Space Complexity of my solutions -: O(n) & O(1) respectively

You are given a subarray which has only 0’s and 1’s , Maximise the subarray containing 1’s and in this you can only flip one 0 , tell the index of that 0Similar to thisfind-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximizedon GFGTime and Space Complexity of my solutions -: O(n) & O(1) respectively

Given 2 large files say file1, file2 consisting of strings of customerid - find the unique customers present in those files. Basically unique words (ex. customer1, customer 3, customer5 and so on)!

My approach - Solved using HashSet but interviewer told it won't work as input is very large and Set would exceed Memory limit. I told maybe something like divide and conquer but wasn't able to come up with the actual solution.

For SDE I found Amazon mostly ask Graph Medium questions for example:

323. Number of Connected Components in an Undirected Graph

547. Number of Provinces

http://leetcode.com/problems/generate-parentheses

This Question I have not seen in any platform. So I will be giving the question description. We have been given a string with parenthesis and characters in between. The parenthesis can be invalid also if it's invalid we have to return -1 and if it's valid then we need to find the maximum depth of the brackets.For eg. let s = "((((X))(((Y)))))" Output will be 5 in this caseThe string can have characters in between the brackets and it can be without characters in between also. I gave him the approach and after the initial discussion, he told me to optimize the space for validity checking of the brackets. After more discussion, I came with an optimized approach and he told it to code it. I wrote the code along with the time and space complexity.

https://leetcode.com/discuss/interview-question/995825/amazon-onsite-sql-library

implement business logic for amazon products with friends. Writing a function like you would in a work style

for the given binary tree find the distance or number of hop required to move from one node to another.

https://leetcode.com/problems/frog-jump SDE 2

https://leetcode.com/problems/sliding-puzzle/ SDE 2

Write a program to print the sum of two roman numbers

https://leetcode.com/problems/best-time-to-buy-and-sell-stock If there is a tie, then return the minimum days to finish the transaction. Example: [1 2 3 1 3], we can buy at index 0 and sell at 2, the profit is 2. but we can also buy at index 3 and sell at 4 which only takes 2 days. So return [3, 4]

describe the differences between Set, Map, Array, List and which data structure should be used with different scenarios

https://leetcode.com/problems/k-similar-strings/

We are given a list of cars, and the direction of the road they are in. We need to find the order in which cars leave the intersection. The list of cars have the cars at the intersection in order. However, if two cars are in opposite direction, for example East/West or North/South, they can leave the intersection even though other cars arrived before it.

Given a list of inputs in the form of a string array, for example [["Item: Bread", "Id:1"], ["Item: Meat", "Id:3"], ["Item: Sauce", Id:2], ["Item: Bread", "Id:4"]], we need to arrange the input string in order and output the result. The interviewer said do not worry about parsing the string. I gave the solution of sorting based on Id and then getting the result. It was very unclear what the interviewer was expecting. Also, I made the mistake of having only screen, and the interviewer said he was nodding to my questions, and I was writing code in another window. This was a very uncomfortable interview.

Write an API for Linux find command. It was this exact question: https://leetcode.com/discuss/interview-question/369272/Amazon-or-Onsite-or-Linux-Find-Command

Medium OOD question. Very similar to linux find command question (https://leetcode.com/discuss/interview-question/369272/Amazon-or-Onsite-or-Linux-Find-Command) but for validation of purchases. If you are good at applying SOLID principles, this should be solvable. The question was in Java, I spent a couple of minutes to convert it to Python.
https://leetcode.com/problems/russian-doll-envelopes/

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

A variation of meeting rooms: https://leetcode.com/problems/meeting-rooms/Given a list of meeting rooms and a meeting reservation request. Find if the reservation request can be fulfilled or not.Follow up: What if the list of meeting rooms is sorted?Edit: I found a similar one here: https://leetcode.com/problems/my-calendar-i/

Coding: create stack with O(1) push, pop and min.

K most frequent items(item_id) in a stream. Input is a stream of (item_id,timestamp).

Then, Interviewer asked me to find frequent items in last hour given a timestamp.

For example, Given time 6:07 PM, Return k most frequent items from 5:07 PM to 6:07 PM.

Gave an answer using queue, hashmap and min-heap, Not an optimal answer, But it worked.

https://leetcode.com/problems/integer-to-roman/

https://leetcode.com/problems/reorder-data-in-log-files/

Design and implement a playlist of a user’s most recently played songs on Amazon music. It should support the following operations: getSong and addSong.

getSong – user should be able to search and get the song from the playlist if the song exists.

addSong – add the song into the playlist if the song is not already present.

Design a Parking Lot , Which takes assigns a ticket number a when car arrives and a vacant parking slot is available and rejects if not, Empty the parking slot when car departs. There were different types of cars and parking spots(small,medium and large).

https://leetcode.com/problems/longest-common-subsequence/

https://leetcode.com/problems/longest-consecutive-sequence/

https://leetcode.com/problems/trapping-rain-water/

Merge k sorted linked list & array. (Highly scalable solution was expected)

Implementaion of coin change variation of dynamic programming. -

https://leetcode.com/problems/design-in-memory-file-system/

https://leetcode.com/problems/copy-list-with-random-pointer/

https://leetcode.com/problems/product-of-array-except-self/

https://leetcode.com/problems/median-of-two-sorted-arrays/

https://leetcode.com/problems/rectangle-overlap/

https://leetcode.com/problems/design-tic-tac-toe/

https://leetcode.com/problems/longest-consecutive-sequence/solution/

https://leetcode.com/problems/concatenated-words/

https://leetcode.com/problems/word-search-ii/

https://leetcode.com/problems/making-file-names-unique/

Follow up question - Assume the tree as a Binary Search Tree & was asked to solve it.
https://leetcode.com/problems/find-all-anagrams-in-a-string/

Largest pair sum that is less than or equal to k in an array

https://leetcode.com/discuss/interview-question/369272/Amazon-or-Onsite-or-Linux-FindCommand

https://leetcode.com/problems/rotting-oranges/

https://leetcode.com/problems/all-paths-from-source-to-target/

https://leetcode.com/discuss/interview-question/algorithms/124715/amazon-is-cheese-reachable-in-the-maze

Implement operations for an AutoComplete feature. New Grad 2021

InsertWords(words) - Given a stream of words, store the words
CheckPrefix(prefix) - Returns if the prefix exists
SearchPrefix(prefix) Given a prefix string, return words starting with the prefix string.Eg: Insert Words {car, cart, carpool, bus, apple, cargo}SearchPrefix (car) -> car, cart, carpool, cargoFollow up questions – SearchPrefix() return in sorted order/ top k results
Isomorphic Strings New Grad 2021

Design Unix Find command - https://leetcode.com/discuss/interview-question/609070/Amazon-OOD-Design-Unix-File-Search-API New Grad 2021 Loading... (leetcode.com)

Design and implement a playlist of a user’s most recently played songs on Amazon music. It should support the following operations: getSong and addSong.

getSong – user should be able to search and get the song from the playlist if the song exists.

addSong – add the song into the playlist if the song is not already present.

In the logistic floor robots entered and exited, how many robot exist at any specific time. interviewer was not very specific about the question and I had to question a lot to understand and construct the problem statement.

https://leetcode.com/problems/jump-game-ii/

Sum of all binary search trees in a tree. So, basically, the interviewer wanted to create a tree and then if there was a BST, add the value of all the nodes in the tree. SDE2

OOP/Coding: Design a game where there are multiple players, you can either add a new player, update their score or display Leadership Board SDE2

Design phone bill calculator

[K maximum sum combinations from two arrays] - GeeksfGeeks question

There are N trees in Jon's backyard and the height of tree i is h[i]. Jon doesn't like the appearance of it and is planning to increase and decrease the height of trees such that the new heights are in strictly increasing order. Every day he can pick one tree and increase or decrease the height by 1 unit. Heights can be 0 or even negative (it's a magical world).
https://leetcode.com/discuss/interview-question/1171979/a-good-question-of-amazon-sde

This problem is a variant of closest pair sum. You'll be given two arraysarr1 = { {1, 2000}, {2, 3000}, {3, 4000} }arr2 = { { 1, 5000 }, {2, 3000} }the first element of every pair represents id and the second value represents the value.and a target x = 5000Find the pairs from both the arrays whose vaue add upto a sum which is less than given target and should be close to the target.

Output for the above example:{ {1, 2} } // Note that the output should be in id's

I cleared all the test cases for the first problem (will share), but for this problem, I couldn't clear 3 test cases which were of handling duplicates!In the online assesment this problem was sort of tagged as approximate solution, does anyone know what that means?Awaiting for the result!

https://leetcode.com/problems/find-median-from-data-stream/

Variation of https://leetcode.com/problems/concatenated-words/

Given a large list of words. Some of these are compounds, where all parts are also in the List. Write a method that will find all combinations where one word is a composite of two or more words from the same list and return them.

https://leetcode.com/discuss/interview-question/545748/amazon-subsidiary-phone-concatenated-words

Given two number in the form of sting, we have to perform two operations: Remove all the zeroes from the number and then add the two numbers.

Given two numbers in the form of LinkedList we have to add the numbers. But there was a condition that we cannot reverse the linkedlist.

https://leetcode.com/problems/asteroid-collision/

https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

https://leetcode.com/problems/minimum-knight-moves/

Group Product Id pairs into Categories ****https://leetcode.com/discuss/interview-question/690707/Amazon-or-Phone-Interview-or-Group-Product-Id-pairs-into-Categories

https://leetcode.com/problems/word-break-ii/

Search for smallest element in sorted rotated list

https://leetcode.com/problems/binary-tree-right-side-view/



*/