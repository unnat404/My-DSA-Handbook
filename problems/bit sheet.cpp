/*
Week 1 (arrays,..)
- 
- 
- https://www.interviewbit.com/problems/maximum-unsorted-subarray/

Reference:
- tuf graphs playlist :: https://www.youtube.com/playlist?list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw
- cp algorithms :: https://cp-algorithms.com/#graphs

*/
// ==========================================================================================================
// https://www.interviewbit.com/problems/maximum-unsorted-subarray/
vector<int> Solution::subUnsort(vector<int> &a) {
    /* 
    -> smallest and largest of that range are out of sync 
    min(l...r) >= max(0...l-1)
    max(l...r) <= min(r+1...n-1)
    ==> above info help us define boundaries

    => right se minimum ka index layenge & place it 
    => left se max address    
    */ 
    int i,n=a.size(),s,e,x,maxi,mini;
    s=e=-1;
    for(i=0;i<n-1;i++){
        if(a[i]>a[i+1]){ s=i;break;}
    }
    for(i=n-1;i>0;i--){
        if(a[i]<a[i-1]){ e=i;break;}
    }

    if(s==-1) return {-1};//since array sorted if s not changed
    
    // find max and min in a[s...e]
    maxi=INT_MIN,mini=INT_MAX;
    for(i=s;i<=e;i++){
        maxi=max(maxi,a[i]);
        mini=min(mini,a[i]);
    }

    for(i=0;i<n;i++){
        if(mini<a[i]){ s=i;break;}
    }
    for(i=n-1;i>=0;i--){
        if(maxi>a[i]){ e=i;break;}
    }

    return {s,e};
}
// ==========================================================================================================
