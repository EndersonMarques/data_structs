#include <stdio.h>
#include <stdlib.h>

// Cria o No
typedef struct NO
{
    int value;
    struct NO *next;
}node;

// Cria a estrutura da pilha formada por nós
typedef struct stack
{
    node *top;
}stack;

// Cria Node
node *create_node(int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->next = NULL;
}

// Cria Pilha
stack *create_stack()
{
    stack *new_stack = (stack*)malloc(sizeof(stack));
    new_stack->top = NULL;
    return new_stack;
}

int is_empty(stack *stack)
{
    return (stack->top == NULL);
}

// Adciona Elementos
void push(stack *stack, int item)
{
    node *new_top = create_node(item);

    if(!is_empty(stack))
    {
        new_top->next = stack->top;
        stack->top = new_top;
    }
    else
    {
        stack->top = new_top;
    }

}

int pop(stack *stack)
{
    if(!is_empty(stack))
    {
        node *new_node = stack->top;
        stack->top = stack->top->next;
        new_node->next == NULL;
        free(new_node);
        return 1;
    }

    return 0;
}
void print(stack *p)
{
    node *no = p->top;

    while (no != NULL)
    {
        printf("%d\n", no->value);
        no = no->next;
    }
    
}

int main()
{

    stack *new_stack = create_stack(); // declaração da stack
    push(new_stack, 3);
    push(new_stack, 4);
    push(new_stack, 5);
    push(new_stack, 7);
    push(new_stack, 8);

    pop(new_stack);

    print(new_stack);
    return 0;
}
