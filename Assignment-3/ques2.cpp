#include<iostream>
#include<string>
using namespace std;
# define max 100
char stackchar[max];
int top=-1;
void push(char c){
    if (top ==max-1){
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    stackchar[top]=c;
}
void pop(){
    if (top == -1) {
        cout << "Stack Underflow" << endl;
        return ;
    }
    cout<<stackchar[top--];
}
int main(){
    string str;
    cout<<"Enter a string: ";
    getline(cin,str);
    for(char c : str){
        push(c);
    }
    
    cout << "Reversed string is: ";
    while (top != -1) {
         pop();
    }
    cout << endl;
    
    return 0;
}