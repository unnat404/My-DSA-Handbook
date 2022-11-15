/*
--------------------------------------
Free ka Tree Series by Striver:
Lectures 32 to 53
--------------------------------------
- Lec 32 : Leetcode 2385. Amount of Time for Binary Tree to Be Infected : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
- Lec 33 : Leetcode
- Lec 34 : Leetcode
- Lec 35 : Leetcode
- Lec 36 : Leetcode
- Lec 37 : Leetcode
- Lec 38 : Leetcode
- Lec 39 : Leetcode
- Lec 40 : Leetcode
- Lec 41 : Leetcode
- Lec 42 : Leetcode
- Lec 43 : Leetcode
- Lec 44 : Leetcode
- Lec 45 : Leetcode
- Lec 46 : Leetcode
- Lec 47 : Leetcode
- Lec 48 : Leetcode
- Lec 49 : Leetcode
- Lec 50 : Leetcode
- Lec 51 : Leetcode
- Lec 52 : Leetcode
- Lec 53 : Leetcode


*/
// ===============================================================================================================================
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ===============================================================================================================================
// Lec 32 : Leetcode 2385. Amount of Time for Binary Tree to Be Infected : https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/
// Minimum Time taken to burn the binary tree from any given node

// approach #1 : (my soln)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    int above_dfs(TreeNode* node,int target, int& time){
        if(node==nullptr) return 0;
        if(node->val == target){
            time=0;
            return 1;
        }
        
        int ld=-1,rd=-1;
        int lh = above_dfs(node->left,target,ld);
        int rh = above_dfs(node->right,target,rd);
        
        if(ld!=-1){
            time = ld+1;
            ans = max(ans,time+rh);
        }
        if(rd!=-1){
            time = rd+1;
            ans = max(ans,time+lh);
        }
        
        return max(lh,rh)+1;
    }
    int below_dfs(TreeNode* node,int dist){
        if(node==nullptr) return dist-1;
        
        int lh = below_dfs(node->left,dist+1);
        int rh = below_dfs(node->right,dist+1);
        
        return max(lh,rh);
    }
    TreeNode* findTarget(TreeNode* root,int target){        
        if(root==nullptr) return nullptr;
        if(root->val == target){
            return root;
        }
        // if(root==nullptr) return nullptr;
        
        TreeNode* l = findTarget(root->left,target);
        TreeNode* r = findTarget(root->right,target);
        
        if(l!=nullptr) return l;
        else return r;
    }
    int amountOfTime(TreeNode* root, int start) {
        int i,j,cur,time=0;
        TreeNode* target = findTarget(root,start);
        cur=below_dfs(target,0);
        
        above_dfs(root,start,time);
        cout<<cur<<" "<<ans<<"\n";
        return max(cur,ans);
        
    }
};
/*
[1]
1
*/

/*
------------------------------------------------
approach #2 (striver's soln approach)(better i guess)
------------------------------------------------
Solution:
	1) Use  bfs to traverse from current node to max distance node from there via bfs traversal
	2) For that we need two things:
		a. The address of the beginning node fom where we initiate the burn (if only value is given in qn then only this step is needed)
		b. Parent of each node, we need this to traverse in all 3 directions possible from a binary node(up : parent node,left : child node,right : hild node)

	- Both things in step 2 can be formed by  a single bfs traversal
	- Use another bfs traversal starting from the target node(given in the qn)

    TC: O(n) || SC: O(n) 
*/

class Solution {
public:
    int burnBfs(TreeNode* start,map<TreeNode*, TreeNode*> parentMap){
        queue<TreeNode*> q;
        // map<TreeNode*,int> visited; 
        vector<int> vis(1e5+5,0);
        int size,time=-1;
        q.push(start);
        while(!q.empty()){
            size = q.size();
            time++;
            while(size--){
                TreeNode* cur = q.front();
                q.pop();
                // m[cur]=1;
                vis[cur->val]=1;
                
                // add parent (if exists)
                if(parentMap.find(cur)!=parentMap.end() and vis[parentMap[cur]->val]==0){
                    q.push(parentMap[cur]);
                }
                // add left and right childs
                if(cur->right != nullptr and vis[cur->right->val]==0){
                    q.push(cur->right);
                }
                if(cur->left != nullptr and vis[cur->left->val]==0){
                    q.push(cur->left);
                }
            }
        }
        return time;
    }
    TreeNode* bfsConstructParentMap(TreeNode* root, int start, map<TreeNode*, TreeNode*> &parentMap){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;
        int size ;
        // bfs traversal
        while(!q.empty()){
            size = q.size();
            while(size--){
                TreeNode* cur=q.front();
                q.pop();
                if(cur->val == start) target=cur;
                if(cur->left){
                    parentMap[cur->left]=cur;
                    q.push(cur->left);
                }
                if(cur->right){
                    parentMap[cur->right]=cur;
                    q.push(cur->right);
                }
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> parentMap;
        TreeNode* target = bfsConstructParentMap(root, start, parentMap);
        // for(auto x:parentMap) cout<<x.first->val<<" :: "<<x.second->val<<"\n";
        int time = burnBfs(target, parentMap);
        return time;

    }
};


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================


// ===============================================================================================================================

