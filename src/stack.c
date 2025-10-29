#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
stack_t *create_stack(int max_size,char type){
    if(max_size<=0){
        return NULL;
    }
    // checks if maxsize is grater then 0
    stack_t *stack = malloc(sizeof (stack_t));
    // allocates memomory for stack
    if(stack == NULL){
        return NULL;
    }
    // checks if memory allocation worked

    // checks a type of stactk and allocates space for conntent array,
    if(type == 'c'){
        stack ->stack_char= malloc(sizeof(char)*max_size);
            //checks if memory allocation worked
            if(stack ->stack_char== NULL){
                free(stack);
                stack = NULL;
            return NULL;
        }
    }
    else if(type == 'i'){
        stack ->stack_int= malloc(sizeof(int)*max_size);
            if(stack ->stack_int==NULL){
                free(stack);
                stack = NULL;
                return NULL;
            }
    }
    else{
        free(stack);
        return NULL;
    } 
    //sets stack type,size and maxsize
    stack->type = type;
    stack->max_size=max_size;
    stack ->size=0;
    return stack;
}
bool is_empty(stack_t *stack){
    //checks if stack is empty
    if(stack->size >0){
        return false;
    }
    return true;
}
bool is_full(stack_t *stack){
    //checks if stack is full
    if(stack->size==stack->max_size){
        return true;
    }
    return false;
}
bool push(stack_t *stack, char input)
{
    // checks if  stack is full
   if(is_full(stack)){
    return false;
   } 
   //pushes an item to right content array
   if(stack ->type=='c'){
        stack->stack_char[stack->size]=input;
   }
   else if(stack ->type=='i'){
        stack->stack_int[stack->size]=input - '0';
   }
   
   //increases size
   stack->size++;
   return true;
}
bool pop(stack_t *stack,char *item){
    // checks if stack is empty
    if(is_empty(stack)){
        return false;
    }
    // pops item form right array,deferfrences pointer to set value of a stack to a variable from function argument (char * item)
    if(stack ->type=='c'){
        *item = stack->stack_char[stack->size -1];
    }
    else if(stack ->type=='i'){
        *item = stack->stack_int[stack->size -1];
    }
    //decreases size
    stack->size--;
    return true;
}
void destroy_stack(stack_t *stack){
    //uninitializes stack arrays(fixing error with freeing intstack)
    stack->stack_char = NULL;
    stack->stack_int = NULL;
    //frees all of the content arrays and stack
    free(stack->stack_int);
    free(stack->stack_char);
    free(stack);
}
