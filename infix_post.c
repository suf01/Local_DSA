#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int size;
    int top;
    char *exp;
};

int IsEmpty(struct stack *ptr){

    if (ptr->top == -1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

int IsFull(struct stack *ptr)
{

    if (ptr->top == ptr->size - 1)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void push(struct stack *ptr, char val)
{
    if (IsFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->exp[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    char temp;
    if (IsEmpty(ptr))
    {
        printf("Empty\n");
    }
    else
    {
        temp = ptr->exp[ptr->top];
        ptr->top--;
    }
    return(temp);
}

char stackTop(struct stack *opstack){
  return(opstack->exp[opstack->top]);
}

int precedence(char ch){
    if(ch=='*' || ch == '/'){
        return(3);
    }
    else if(ch == '+' || ch =='-'){
        return(2);
    }
    else
    return(0);
}

int isoperator(char ch){
    if(ch == '+'|| ch == '-'|| ch == '*'||ch == '/'){
        return(1);
    }
    else
     return(0);
}

char *postfix(char *infix){
    
    struct stack *opstack = (struct stack*)malloc(sizeof(struct stack));
    opstack->size=10;
    opstack->top=-1;
    opstack->exp = (char*)malloc(opstack->size * sizeof(char));
    char *post = (char*)malloc(strlen(infix+1)* sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0'){
    
    if(!isoperator(infix[i]))
    {
        post[j]=infix[i];
        i++;
        j++;
    }
    else{
        if(precedence(infix[i])> precedence(stackTop(opstack))){
            push(opstack, infix[i]);
            i++;
        }
          else{
            post[j]=pop(opstack);
            j++;
        }
    }
 }
 
 while(!IsEmpty(opstack)){
     post[j]=pop(opstack);
     j++;
 }
 post[j]='\0';
 return(post);

}

int main(){
    
    char *exp = "(x-(y+z))";
    printf("postfix expression is : %s", postfix(exp));
}