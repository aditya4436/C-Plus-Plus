///A program to evaluate Postfix Expression
#include<iostream>
#include<stack>
#include<math.h>
using namespace std;
int Postfix_Evaluation(string s)
{
    stack<int> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op1, op2;
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();

            switch(s[i])
            {
            case '+':
                st.push(op1+op2);
                break;

            case '-':
                st.push(op1-op2);
                break;

            case '*':
                st.push(op1*op2);
                break;

            case '/':
                st.push(op1/op2);
                break;

            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string str;
    cout<<"Enter the Postfix Expression:\n";
    getline(cin, str);
    cout<<Postfix_Evaluation(str);
    return 0;
}

