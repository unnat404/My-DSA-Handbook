
// https://leetcode.com/discuss/interview-question/1455524/Cisco-Online-Assesment
/*
Solution for 3

totalGroups=0
arr.sort() [#first](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array) sort the array
iterate from end to beggining
	if arr[i]>1.99:
		totalGroups+=1 [#add](https://leetcode.com/problems/add-two-numbers) to total groups since it is impossible to extend a group containg value 2, since the minimum element size is 1.01 and 2+1.01 is 3.01 which is not allowed since max group size is 3
	if arr[i]=<1.99: #otherwise it is possible to find a group
		if arr[ leftIndex ]+arr[i] <= 3:  # since the array is sorted we want to match the biggest element, which is our current element since were iterating backwords, with our smallest element which is at leftindex, this technique counts the minimum pairs that can be made that are <=3
			leftIndex +=1 [#if](https://leetcode.com/problems/text-justification) there is a match we dont want to double count so we incremnet the left index
		totalGroups+=1
	stop when leftIndex > i [#we](https://leetcode.com/problems/power-of-two) need to stop when we have checked all pairs
return totalGroups

*/