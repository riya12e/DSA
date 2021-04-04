//This is implementation of min Stack in cpp.
//You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.

stack<int> s;
int minEle;
//returns min element from stack
int _stack :: getMin()
{
   //Your code here
   if(s.empty())
    return -1;

   return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   int t,a;
   if(s.empty())
     return -1;
   else{
       t=s.top();
       s.pop();
       if(t<minEle){
          // int a=minEle;
           a=minEle;
           minEle=2*minEle-t;
           return a;
       }
       
      }
     
   return t;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   if(s.empty()){
       s.push(x);
       minEle=x;
   }
   else{
       if(x<minEle){
           s.push(2*x-minEle);
           minEle=x;
       }
       else
       s.push(x);
   }
}
