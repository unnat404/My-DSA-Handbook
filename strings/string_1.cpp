/*

1   - Leetcode 125. Valid Palindrome
2   - Leetcode 680. Valid Palindrome II
3   - Leetcode 271. Encode & Decode Strings
4   - Leetcode 443. String Compression :: https://leetcode.com/problems/string-compression/
5   - Leetcode 67. Add Binary :: https://leetcode.com/problems/add-binary/
6   - Leetcode 28. 
7   - Leetcode 678. Valid Parenthesis String :: https://leetcode.com/problems/valid-parenthesis-string/
8   - Leetcode 296. Best Meeting Point
        - https://leetcode.ca/all/296.html#:~:text=A%20group%20of%20two%20or,%2C%20p2)%20%3D%20%7Cp2.
9   - Leetcode 
10  - Leetcode
11  - Leetcode
12  - Leetcode
13  - Leetcode
14  - Leetcode
15  - Leetcode
16  - Leetcode
17  - Leetcode
18  - Leetcode
19  - Leetcode
20  - Leetcode

TODO: 
- Leetcode 1328. Break a Palindrome : https://leetcode.com/problems/break-a-palindrome/
    - https://www.youtube.com/watch?v=iXbJ1qvKg28
- Leetcode 132. Palindrome Partitioning II : https://leetcode.com/problems/palindrome-partitioning-ii/
- Leetcode 131. Palindrome Partitioning : https://leetcode.com/problems/palindrome-partitioning/
    - https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
- Leetcode 1745. Palindrome Partitioning IV : https://leetcode.com/problems/palindrome-partitioning-iv/
- Leetcode  : https://leetcode.com/problems/repeated-string-match/
- Leetcode  : https://leetcode.com/problems/maximum-repeating-substring/
- Leetcode  : https://leetcode.com/problems/repeated-substring-pattern/
- 
- https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
- kmpc : cp algorithms
- kmp/periodic strings : https://www.spoj.com/problems/FINDSR/
- kmp/manchester algo (google kickstart E 2022) : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb0f5/0000000000ba82c5
    - machenster soln (TODO) : 
    - kanisht' soln (kmp)(better): http://p.ip.fi/sE7c
    - mine (optimized brute force) : https://p.ip.fi/VqvE
- 

Additional String tagged pblms:
- https://www.interviewbit.com/courses/programming/strings/
- bits sheet
*/


// ==================================================================================================
// 3   - Leetcode 271. Encode & Decode Strings
// https://pastebin.com/WTVvwJwZ
/*
---------
Question:
---------
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}

So Machine 1 does:
string encoded_string = encode(strs);
and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.
 
Implement the encode and decode methods.
 
 
Note:
 
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
 
 
---------
Solution:
---------
*/
class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        // Separate the individual words by lengths
        string enc = "";
        for(int i = 0; i < strs.size(); i++) {
            enc += to_string(strs[i].size()) + "#" + strs[i];
        }
        
        return enc;
    }
 
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> dec;
        
        int i = 0;
        while(i < s.size()) {
            // Get the occurence of first #
            int pos = s.find('#', i);
            int count = stoi(s.substr(i, pos-i));
            pos++;
            
            // Push the string
            dec.push_back(s.substr(pos, count));
            
            // Update i
            i = pos+count;
        }
        
        return dec;
    }
};
 
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));

// ==================================================================================================

// Leetcode 443. String Compression :: https://leetcode.com/problems/string-compression/
class Solution {
public:
    //run-length encoding/compression
    // note ::  we are doing the compression in place 
    // will it override charectors u have already processed ? - think it out 
    // --> Ans: NO, it wont override => we can do it in the same char array itself the encoding
    int compress(vector<char>& chars) {
        char curr;
        int i,n=chars.size(),nxt=0,count;
        string s;
        for(i=0;i<n;i++){
            curr=chars[i];count=1;
            while(i<n-1 && curr==chars[i+1]){
                i++;count++;                
            }
            s=to_string(count);
            chars[nxt++]=curr;
            
            if(count>1){ //add length of charectors after splitting them to charectors               
                for(auto& x:s) chars[nxt++]=x;                
            } 
            
        }
        return nxt;//return length of the runlength encoded array
    }
};
// Note: if all charectors were the same :
// -> then it might have been an edge case in another implementation of the pblm 
// but in our case the inner while loop handles that situation as well
// but keep it in mind

//  easy hi hai qn 
// ==================================================================================================
// Leetcode 67. Add Binary :: https://leetcode.com/problems/add-binary/
class Solution {
public:
    string addBinary(string a, string b) {
        int n,i,j,la=a.length(),lb=b.length(),ca,cb,carry=0,state,base=2;
        string ans="",x;
        n=max(la,lb);
        vector<int> v(n,0);
        la--,lb--;//start traversing bits form the last
        for(i=n-1;i>=0;i--){
            if(la>=0){
                x=(a[la--]);
                ca = stoi(x);
            }
            else ca=0;
            if(lb>=0){
                x= (b[lb--]);
                cb= stoi(x);
            }
            else cb = 0;
            //current_bit in addition (in any general base) = ({indivisuals sums at that digit's place} + carry) % base
            state = (carry + ca + cb) % base;
            //carry in addition (in any general base) = ({indiviauls sums  at that digit's place} + carry) / base
            carry = (carry + ca + cb) / base; // updating carry
            v[i]=state;//setting current bit
            ans = to_string(state)+ans;            
            
        }
        if(carry==1) ans='1'+ans;//take care of last carry
        return ans;
    }
};

// ==================================================================================================
// Question 7
// Leetcode 678. Valid Parenthesis String :: https://leetcode.com/problems/valid-parenthesis-string/
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> star,open;
        int i,j,n=s.length();
        for(i=0;i<n;i++){
            if(s[i]=='(') open.push(i);
            
            else if(s[i]==')'){
                if(!open.empty()) open.pop();
                else if(!star.empty()) star.pop();
                else return false;// no '(' or '*' present to balance ')'
            }
            
            else if(s[i]=='*'){
                star.push(i);    
            }
        }
        // after above loop ')' is balanced, now we need to balance '(' if any by '*'
        
        while(!open.empty()){
            if(star.empty()) return false;// no * to balance (
                        
            // good => (*  || bad => *( 
            if(open.top()>star.top()) return false;
            else{
                open.pop();
                star.pop();
            }
        } 
        return true;
    }    
};
// ==================================================================================================
/*
Leetcode 296. Best Meeting Point
        - https://leetcode.ca/all/296.html#:~:text=A%20group%20of%20two%20or,%2C%20p2)%20%3D%20%7Cp2.
        - https://www.codingninjas.com/codestudio/problems/best-meeting-point_1463982

*/
int findBestMeetingPoint(vector<vector<int>> &mat)
{
	int meet,t,dist=0,n=mat.size(),m=mat[0].size(),i,j,xmedian,ymedian;
	vector<int> row,col;//find median of x & y coordinates seperately 
	// row is projetcion of x-co-ordinates of 1's
	
	//row wise traversal ensures sorted x-coordinates
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(mat[i][j]==1) col.push_back(i);
		}		

	}
	//col wise traversal ensures sorted y-coordinates
	for(j=0;j<m;j++){
		for(i=0;i<n;i++){
			if(mat[i][j]==1) row.push_back(j);
		}
	}
	
	xmedian = col[col.size()/2];
	ymedian = row[row.size()/2];
	for(auto x :col) dist+=abs(xmedian-x);
	for(auto y :row) dist+=abs(ymedian-y);
	return dist;
}
/*
// 		find median of position
// 		meet = v[v.size()/2];// 5/2=2
// 		for(auto x:v) dist+=abs(meet-x);
// 		return dist;
*/
// ==================================================================================================
// Interviewbit ::  Merge Intervals :: https://www.interviewbit.com/problems/merge-intervals/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) { 
    vector<Interval> res;
    for (Interval test : intervals) {
        if (newInterval.start > test.end) res.push_back(test);
        else if(test.start > newInterval.end) {
            res.push_back(newInterval);
            newInterval = test;
        } else if (newInterval.start <= test.end || newInterval.end >= test.start) {
            newInterval = Interval(min(test.start, newInterval.start), max(test.end, newInterval.end));
        }
    } 
    res.push_back(newInterval);
    return res;
}
