/*
(article ideas for gfg)

- (code kaze)Find no of subsequences of array whose proct of last digit is exactly = k (code kaze)(dp)
    - just for reference : https://www.geeksforgeeks.org/count-subsequences-product-less-k/
- (code kaze)find minimum no of edges to be deleted in a tree such that there is atleast one connected component of size = k (graph/tree)
- (CISCO intern)(largest square possible) find maximal square from an array (solve using 2 array approach) 
    - https://github.com/unnat404/My-DSA-Handbook/issues/1
    - https://user-images.githubusercontent.com/53619178/158109002-877730f8-4f9e-40e8-a142-0a26c951a2aa.png
    - https://user-images.githubusercontent.com/53619178/158114108-c9c9eab0-60f5-4a44-86a6-c2b406947f9e.png
    - https://user-images.githubusercontent.com/53619178/158114185-c2195d63-9009-47e3-9fe2-547ae0f4af09.png

*/

// Self made questions:
/*
Question:

For a given tree as input, 
- variation 1: find the set of most optimal ROOT node candidates
- variation 2: find the most optimal ROOT node that can be root (tie breaker- smallest candidate node)(constraints for this can be a bit tighter?)

Optimal Root Node :
- node such that maximum distance of other nodes from this optmial root node is minimum
*/