/*Taqi Tahmid*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100

//Stack structure
struct Stack{
    int size;
    int top;
    int arr[MAX];
};

//Intitialize stack
void init(Stack *s, int sz){
    s->size = sz;
    s->top = -1;
}

//Check if stack is empty
bool isEmpty(Stack *s){
    return s->top == -1;
}

//check if stack is full
bool isFull(Stack *s){
    return s->top == s->size-1;
}

//Push Operation
void push(Stack *s, int val){
    if(isFull(s)){
        cout << "Stack overlfow" << endl;
        return;
    }
    s->arr[++(s->top)] = val;
    cout << val << " pushed successfully" << endl;
}

//Pop Operation
int pop(Stack *s){
    if(isEmpty(s)){
        cout << "Stack Underflow" << endl;
        return -1;
    }
    return s->arr[(s->top)--];
}

//Peek Operation
int peek(Stack *s){
    if(isEmpty(s)){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return s->arr[s->top];
}

//Display stack
void display(Stack *s){
    if(isEmpty(s)){
        cout << "Stack is empty" << endl;
        return; 
    }
    for(int i = s->top; i>=0; i--){
        cout << s->arr[i] << " ";
    }
    cout << endl;
}

int main(){
    Stack s;
    init(&s, 5); //stack capacity = 5
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(&s);

    cout << "Top element: " << peek(&s) << endl;
    cout << "Popped: " << pop(&s) << endl;
    display(&s);

    return 0;
}