/*

1   - Leetcode 125. Valid Palindrome
2   - Leetcode 680. Valid Palindrome II
3   - Leetcode 271. Encode & Decode Strings
4   - Leetcode 443. String Compression :: https://leetcode.com/problems/string-compression/
5   - Leetcode 67. Add Binary :: https://leetcode.com/problems/add-binary/
6   - Leetcode 28. 
7   - Leetcode 
8   - Leetcode 
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