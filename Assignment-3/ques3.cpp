#include<iostream>
#include<string>
using namespace std;
#define max 100
int stackchar[max];
int top=-1;
void push(char c){
    if (top ==max-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    stackchar[top]=c;
} 
char pop(){
    if (top==-1){
        cout<<"Stack Underflow"<<endl;
        return '\0';
    }
    return stackchar[top--];
}
bool isBalanced(string s){
    for(char c:s){
        if(c=='(' || c=='{' || c=='['){
            push(c);
        }
        else if(c==')' || c=='}' || c==']'){
            char topChar = pop();
            if((c==')' && topChar!='(') || (c=='}' && topChar!='{') || (c==']' && topChar!='[')){
                return false;
            }
        }
    }
     return (top == -1);
}
int main(){
    string expr;
    cout<<"Enter the string:"<<endl;
    getline(cin, expr);
    if(isBalanced(expr)){
        cout<<"Balanced"<<endl;
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0;
}