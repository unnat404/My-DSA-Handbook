/*
Infosys (Power programmer/specialist programmer) (On-Campus)
-------------------------------------------------------------

// 
/******************************************************************************
 
                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.
 
*******************************************************************************/
 
#include <iostream>
 
using namespace std;
string sortSentence(string s){
    string word="",ans="";
    int i,j,n=s.length();
    map<int,vector<string>> m;
    //fi;ll map
    for(i=0;i<n;i++){
        //get first position
        j=i,word="";
        for(j=i;j<n;j++){
            if(s[j]!=" " || s[j]!=n-1) word+=s[j]; 
            else break;
        }
        m[word.size()].push_back(word);
        i=j-1;
    }
    
    //traverse mappping
    for(auto x:m){
        sort(x.second.begin(),x.second.end());
        
        for(auto w:x.second) ans+=w+" ";
    }
    ans.substr(0,ans.length()-1);
    return ans;
    // TC: O(x log x) 
    // where x=avg word length, which in worst case would be = n(size of input string)
    
}
int main()
{
    // cout<<"Hello World";
    // kety : count of chars 
    // value : vector of words of that kkey length
    // i.p : hello Unnat here four
    // o.p: four here hello Unnat
    
    string s,ans="";
    cin>>s;
    ans= sortSentence(s);
    
 
    return 0;
}

*/
/*
// square matrix : find diff between sum of its diagonals : absolute diff
 
3*3
0,2 
for principal diagonal : i=j
for secondary diagonal : i+j = n-1 (since zero based indexing)
 
int findDiagonalDifference(vector<vector<int> &v){
	int n=v.size();
	int i,j,k,d1=0,d2=0;
	for(i=0;i<n;i++){
		d1+=v[i][i];// principal diagonal sum
		d2+=v[i][n-1-i];// secondary dia
	}
	return abs(d1-d2);
}
// TC: O(n)
 
 
 
delete, get, put, post, 
 
class : multiple coteacher, assingement, students
{
class_code: primary_key,
students: [{...}],
techers : [{owner, ...cotecher}]
}
 
// ----------------------------------------------------------
get:method
https:bytelearn/classroom/teacher_id=xxxx?fetch_student=True
 
 
https:bytelearn/classroom/teacher_id=xxxx?fetch_student=True
jwt_token: 
 
 
linkedlist
search : O(n)
insert : O(n)
 
 
 
// algo to insert node at end of linked list
 
void insertBack(Node* head, int data){
	Node* dummy = new Node();
	dummy->next=head,dummy=dummy->next;
 
	
	if(dummy==nullptr){ dummy = new Node(data);}
	
	while(dummy->next !=nullptr) dummy=dummy->next;
	dummy->next = new Node(data);
}
	
 
	
 
student table: 
find student having 2nd highest ,marks in class
 
fields: student_id,marks
 
44 44 22 22 
 
select student_id from class 
where (
	select 1 from classs having marks = max(class.marks) 
	) as j
 
 
 
 
 
 
 
 
*/