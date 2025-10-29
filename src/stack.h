typedef struct Stack {
    char type;
    int max_size;
    int size;
    char *stack_char; 
    int *stack_int;
}stack_t;
stack_t *create_stack(int max_size,char type);
bool is_empty(stack_t *stack);
bool if_full(stack_t *stack);
bool push(stack_t *stack,char input);
bool pop(stack_t *stack,char *input);
void destroy_stack(stack_t *stack);




