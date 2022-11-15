#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define nil -1
#define MAX 100
#define ll long long 

struct ListNode{
	ListNode* next;
	int val;
	ListNode(int x) : val(x),next(nullptr){}
	// ListNode(int x,ListNode* next):val=x,next=next;
};
int findLengthofList(ListNode* node){
	int n=0;
	while(node!=nullptr){
		node=node->next;
		n++;
	}
	return n;
}
int intersection2(ListNode* head1, ListNode* head2){
	unordered_set<int> items;
	ListNode* dummy=head1; 
	int intersect = -1 ; 
	while(dummy!=nullptr){
		cout<<dummy->val;
		items.insert(dummy->val);
		dummy=dummy->next;
	}

	dummy=head2;
	while(dummy!=nullptr){
		if(items.find(dummy->val)!=items.end()){
			intersect = dummy->val;
			break;
		}
		dummy = dummy->next;
	}
	return intersect;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ////vector<int> v(100, 0); //initialize 100 elements of vector to 0
    int t,n,i,k,x,y,cur,sum,ans;
    string res="";
	ListNode* dummy;
    ListNode* head1 = new ListNode(1);
	
	dummy = new ListNode(2);
	head1->next = dummy;
	dummy = new ListNode(3);
	head1->next->next = dummy;
	dummy = new ListNode(4);
	head1->next->next->next = dummy;
	dummy = new ListNode(5);
	head1->next->next->next->next = dummy;
	dummy = new ListNode(6);
	head1->next->next->next->next->next = dummy;
	
	ListNode* head2 = new ListNode(11);
	
	dummy = new ListNode(3);
	head2->next = dummy;
	dummy = new ListNode(13);
	head2->next->next = dummy;
	
	ans = intersection2(head1,head2);
	cout<< "\nIntersection val: ";
	cout<<ans;	
	
    return 0;
}
// ListNode* intersection(ListNode* head1, ListNode* head2){
// 	int len1,len2,i,diff;
// 	len1=len2=0;
// 	ListNode* intersection;
// 	len1=findLengthofList(head1);
// 	len2=findLengthofList(head2);
	
// 	diff = len1-len2;

// 	if(diff>0){
// 		// list1 is bigger
// 		diff = abs(diff);
// 		while(diff--){
// 			head1=head1->next;
// 		}
// 	}
// 	else{
// 		// list2 is bigger
// 		diff = abs(diff);
// 		while(diff--){
// 			head1=head1->next;
// 		}
// 	}

// 	// now start iterating
// 	while(head1!=head2){
// 		head1=head1->next;
// 		head2=head2->next;
// 	}


// }
/*

1 2 3 4 5 6 7 

11 7 13 

4
*/
