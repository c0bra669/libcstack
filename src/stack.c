#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
stack_t *create_stack(int max_size){
    if(max_size<=0){
    //printf("Size must be grater then 0\n");
    return NULL;
    }
    stack_t *stack = malloc(sizeof (stack_t));
    if(stack == NULL){
        //printf("Failed to allocate memory!\n");
        return NULL;
    }
   stack ->content = malloc(sizeof(char)*max_size);
   if(stack ->content == NULL){
    free(stack);
    stack = NULL;
    //printf("Failed to allocate memory!\n");
    return NULL;
   }
   stack ->max_size=max_size;
   stack ->size=0;
   return stack;
}
bool is_empty(stack_t *stack){
    if(stack->size >0){
        return false;
    }
    return true;
}
bool is_full(stack_t *stack){
    if(stack->size==stack->max_size){
        return true;
    }
    return false;
}
bool push(stack_t *stack, char input)
{
   if(is_full(stack)){
    return false;
   } /* code */
   stack->content[stack->size]=input;
   stack->size++;
   return true;
}
bool pop(stack_t *stack,char *item){
    if(is_empty(stack)){return false;}
    *item = stack->content[stack->size -1];
    stack->size--;
    return true;
}
void destroy_stack(stack_t *stack){
    free(stack->content);
    free(stack);

}
