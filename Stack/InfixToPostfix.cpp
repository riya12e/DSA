//This is code for infix to postfix conversion using stack in c++
//Eg. Given Expression
//"a+b*(c^d-e)^(f+g*h)-i"
//Output will be:
//abcd^e-fgh*+^*+i-


int prec(char a){
    if(a=='^')
    return 3;
    else if(a=='*' || a=='/')
    return 2;
    else if(a=='+' || a=='-')
    return 1;
    
    return -1;
    
}

string infixToPostfix(string s){
    
    string ans;
    stack<char> st;
    s.push('N');
    
    for(int i=0;i<s.length();i++){
        
        if(s[i] >= 'A' && s[i] <='Z' || s[i] >= 'a' && s[i] <='z')
        {
            ans+=s[i];
        }
        
        else if(s[i]=='('){
            st.push('(');
        
        }
        
        else if(s[i]==')'){
            while(st.top()!='N' && st.top() != '('){
                char ch=s.top();
                ans+=ch;
                st.pop();
            }
            
            if(st.top() == '('){
                char ch=s.top();
                st.pop();
            }
        }
        
        else{
                while(st.top() != 'N' && prec(s[i]) <= prec(s.top())){
                    char ch=st.top();
                    ans+=ch;
                    st.pop();
                }
                
                st.push(s[i]);        
        }
        
        while(st.top() !='N'){
            char ch=s.top();
            ans+=ch;
            st.pop();
        
        }
    }
    return ans;

}
