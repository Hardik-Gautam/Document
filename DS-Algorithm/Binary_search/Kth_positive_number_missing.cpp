#include<bits\stdc++.h>
using namespace std;
/**
 *      leetcode link : https://leetcode.com/problems/kth-missing-positive-number/
 *      
 *      Exemple 1:
 *       arr[] = [2,3,4,7,11]
 *        k =  5
 *        n = 6
 *      Explainaton :-> [1,5,6,8,9,10]
 *      Output:-> 9
 *      
 *      Exemple 1:
 *       arr[] = [1,2,3,4]
 *        k =  2
 *        n = 6 
 *      Explaination :->[1,2,3,4,5,6]
 *      Output:-> 6
 * 
 */
int findKthPositive(int arr[],int n, int k) {
    
    int l = 0, r = n, m;
    while (l < r) 
    {
        m = (l + r) / 2;
    
        if (arr[m] - 1 - m < k)
            l = m + 1;
        else
            r = m;
    }
    
    return l + k;
    
}
int main()
{
    int arr[] = {2,3,4,7,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    cout<<findKthPositive(arr,n,k);
    return 0;
}