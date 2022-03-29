/*
- Beri
- Akshat
- Nandini 1.0
- Nandini 2.0 :: Interview || 25/3/22 

- https://www.geeksforgeeks.org/check-characters-given-string-can-rearranged-form-palindrome/
    - solve above in :: time: O(n) ; space: O(1)
    - we can use bitset also?(if 256 charectors asked)
    - 
- Minimum Platforms | Practice | GeeksforGeeks
    - https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1
    - (Activity selection  h na vector of pair fir sort)
- Rotate Array | Practice | GeeksforGeeks
    - https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/1
    - Iska clockwise
- Two char arrays are anagram or not
-- Sab most optimized solution manga

- interface in java
- Oops ka main properties with explanation 
- Java cpp ka diff
- Is jvm platform independent 
- RDBMS and nosql ne difference 
- Indexing and its type
- Https methods-- get post put delete

--> Conclusion from 2 interview rounds dbms oops in java are really important for gs
- Collections in java and stl in cpp background me what data structure is used in them and there functionality

*/

//======================================================================================================================
/*
- https://www.geeksforgeeks.org/check-characters-given-string-can-rearranged-form-palindrome/
    - solve above in :: time: O(n) ; space: O(1)
    - we can use bitset also?(if 256 charectors asked)

Q)Find if palindrome possible or not :: O(1):space & O(n):time

*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool isPalindromePossible(string s){
    bitset<128> oddCount;//ascii range[0,127]
    for(const auto& ch:s){
        int ind = ch - '\0';
        oddCount.set(ind, oddCount[ind] ^ 1);
        // oddCount[ind] ^= 1;//toggle 
    }
    cout<<"Bitset is :"<<oddCount<<"\n";
    return (oddCount.count() > 1) ? false : true;
    
}

int main()
{
    string s="abaab";
    bool ans = isPalindromePossible(s);
    cout<<s<<" --> palindrome possible? "<<ans<<"\n\n";
    
    s="popomnbsakdfjk";
    ans = isPalindromePossible(s);
    cout<<s<<" --> palindrome possible? "<<ans<<"\n\n";
    return 0;
}
/*
:: o/p ::
Bitset is :00000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
abaab --> palindrome possible? 1

Bitset is :00000000000010000110010001010110000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
popomnbsakdfjk --> palindrome possible? 0
*/

//======================================================================================================================
