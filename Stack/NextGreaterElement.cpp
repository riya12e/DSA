//Next Greater Element(to right)
//There are four variations to this problem


/*Example: Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
 */


#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
void nextGreaterElement(int arr[],int n){
    stack<int> s;
    vector<int> v;
    for(int i=n-1;i>=0;i--){
        if(s.empty())
          v.push_back(-1);
        else{
            while(!s.empty() && s.top()<=arr[i]){
                s.pop();
            }
            if(!s.empty() && s.top()>arr[i])
              v.push_back(s.top());
            if(s.empty())
              v.push_back(-1);
        }
        s.push(arr[i]);
    }
    reverse(v.begin(),v.end());
    for(auto i:v)
      cout<<i<<" ";
    
}
int main() {
 int arr[] = { 11, 13, 21, 3 };
 int n = sizeof(arr)/sizeof(arr[0]);
 nextGreaterElement(arr,n);
  return 0;
}
