#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//stack is full when top=size-1 (as top returns index)
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int Push(struct stack * ptr, int data){
    //when the stack is full i.e top=size-1 , and we are trying to push then its overflown    
    if (isFull(ptr))
    {
        printf("Stack is overflown");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
        printf("%d\n",ptr->top);
    }  
}

//when we are tring to pop and empty staack then its underflow
int Pop(struct stack * ptr){
    if (isEmpty(ptr)){
        printf("Stack is underflow");
    }
    else{
        int val= ptr->arr[ptr->top];
        //ptr->top=ptr->top-1;
        ptr->top--;
        printf("%d\n",ptr->top);
        //return val;
    }
}
 
int Peek(struct stack * ptr,int i){
    if (ptr->top-i+1<0){
        return "Not a valid position";
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int stackTop(struct stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBotton(struct stack *ptr){
    return ptr->arr[0];
}

int main(){
    // struct stack s;
    // s.size = 10;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    //creating 's' a pointer [stack pointer]
    struct stack *s;
    //alocating dynamic memory for the stack 's'
    s = (struct stack *)malloc(sizeof(struct stack));
    
    s->size = 10;
    s->top = -1;
    //dynamic memory allocation for array data
    s->arr = (int *)malloc(s->size * sizeof(int));    

    //pushing element manualy
    // s->arr[0]=10;
    // s->top++;

    //checking stack isEmpty
    // if (isEmpty(s)){
    //     printf("stack is Empty");
    // }
    // else{
    //     printf("stack is not empty");
    // }

    //checking stack isFull
    // if (isFull(s)){
    //     printf("stack is Full");
    // }

    //pushing data to stack 's'
    Push(s,5);
    Push(s,12);
    Push(s,18);
    Push(s,20);
    Push(s,22);
    Push(s,24);
    Push(s,26);
    printf("Push Completed\n");

    //poping data in stack 's'
    Pop(s);
    printf("Pop Completed\n");

    //using peek
    printf("%d\n",Peek(s,2));
    printf("%d\n",Peek(s,5));
    printf("peek 1 completed\n");
    //printing all
    for (int j = 1; j <= s->top +1; j++)
    {
        printf("the value at position %d is %d\n",j,Peek(s,j));
    }

    //stack top
    printf("stack top is %d\n",stackTop(s));   
    
    //stack bottom
    printf("stack bottom is %d\n",stackBotton(s));

    return 0;
}