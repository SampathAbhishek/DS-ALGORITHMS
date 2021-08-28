#include<stdio.h>
#include<stdlib.h>
struct Stack
{
  int size;
  int top;
  char *S;
};

void create_stack(struct Stack *st,int n){
    st->size=n;
    st->top=-1;
    st->S=(char *)malloc(n*sizeof(char));
}

void push(struct Stack *st,char x){
    if(st->top==st->size-1){
        printf("Stack Overflow");
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

char pop(struct Stack *st){
    char x;
    if(st->top==-1){
        printf("Stack underflow");
    }
    else{
        x=st->S[st->top];
        st->top--;
    }
    return(x);
}

char peek(struct Stack *st,int pos){
    return(st->S[st->top-pos+1]);
}

int isEmpty(struct Stack st){
    return st.top==-1 ? 1: 0;
}

int isFull(struct Stack st){
    return st.top==st.size-1 ? 1 : 0; 
}

void display(struct Stack st){
    int i = st.top;
    for(;i>=0;i--){
        printf("%c ",st.S[i]);
    }
}

char stack_top(struct Stack st)
{
    return(st.top);
}

int isOperand(char x){
    if(x == '+' || x == '*' || x =='-' || x =='/'){
        return(0);
    }
    else{
        return(1);
    }
}

int precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x=='/'){
        return 2;
    }
    return 0;
}

void infix_to_postfix(char *infix)
{
    struct Stack st;
    create_stack(&st,100);
    char postfix[35];
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            postfix[j++]=infix[i++];
        }
        else {
            if(precedence(infix[i])>precedence(stack_top(st))){
                push(&st,infix[i++]);
            }
            else{
                postfix[j++]=pop(&st);
            }
        }
    }
    while(!isEmpty(st)){
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    i=0;
    while(postfix[i]!='\0'){
        printf("%c ",postfix[i]);
        i++;
    }
}


int isbalanced(char *expression){
    int i;
    struct Stack st;
    create_stack(&st,50);
    for(i=0;expression[i]!='\0';i++)
    {
        if(expression[i]=='['||expression[i]=='(')
        {
            push(&st,expression[i]);
        }
        else if(expression[i]==']'||expression[i]==')')
        {
            if(!isEmpty(st))
            {
            int x = expression[i]; 
            int y = pop(&st);
            if(y-x > 2 || x-y > 2){
                return 0;
            }
            }
            else{
                return 0;
            }
        }
    }
    return isEmpty(st)? 1: 0;
}

int main(){
    char *infix = "a+b*c";
    infix_to_postfix(infix);
}


