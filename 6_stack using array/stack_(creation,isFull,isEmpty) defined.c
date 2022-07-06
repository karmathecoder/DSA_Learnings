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
    s->arr[0]=10;
    s->top++;

    //checking stack isEmpty
    if (isEmpty(s)){
        printf("stack is Empty");
    }
    else{
        printf("stack is not empty");
    }

    //checking stack isFull
    if (isFull(s)){
        printf("stack is Full");
    }


    return 0;
}