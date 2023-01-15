#include "stack.h"

/************************
 * Implement the following functions.
 * DO NOT add any global (static) variables,
 * Except in Part C.
 * You can add help functions as you need.
 * **********************/

/*************************************************
 * ------------------Part A:---------------------- 
 * In this part, you will implement
 * a  dynamically allocated stack with
 * a linked list. 
 * DO NOT add any global (static) variables.
 *************************************************/

int stack_A_initialized = 0;

typedef struct stack_A_node{
/* Add code BEGIN */
    struct stack_A_node *next;
/* Add code END */

    void* item;

} 
stack_A_node_t;

stack_A_node_t * stack_A_root = NULL;
stack_A_node_t * stack_A_tail = NULL;

/* Add code BEGIN */
// Help unctions only!
/* Add code END */


int stack_A_initialize(){
/* Add code BEGIN */
    if(stack_A_initialized == 1){
        return ERR_INITIALIZED;
    }
    stack_A_root = (stack_A_node_t*)malloc(sizeof(stack_A_node_t));
    stack_A_tail = (stack_A_node_t*)malloc(sizeof(stack_A_node_t));
    stack_A_root->next = stack_A_tail;
    stack_A_tail->next = NULL;
    stack_A_initialized = 1;
    return 0;
/* Add code END */
}

int stack_A_pop(void** item){
/* Add code BEGIN */
    if(stack_A_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if(stack_A_root->next == stack_A_tail){
        return ERR_NO_ITEM;
    }
    stack_A_node_t *ptr = stack_A_root->next;
    *item = ptr->item;
    stack_A_root->next = ptr->next;
    free(ptr);
    return 0;
/* Add code END */
}



int stack_A_push(void* item){
/* Add code BEGIN */
    if(stack_A_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    stack_A_node_t *ptr = (stack_A_node_t*)malloc(sizeof(stack_A_node_t));
    ptr->item = item;
    ptr->next = stack_A_root->next;
    stack_A_root->next = ptr;
    return 0;
/* Add code END */

}

int stack_A_destroy(){
/* Add code BEGIN */
    if(stack_A_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    stack_A_node_t *ptr = stack_A_root;
    while(ptr != NULL){
        stack_A_node_t *ptr2 = ptr->next;
        free(ptr);
        ptr = ptr2;
    }
    stack_A_initialized = 0;
    return 0;
/* Add code BEGIN */

    /*return 0;*/

}

/* END of Part A */

/*************************************************
 * ------------------Part B:---------------------- 
 * In this part, you will implement a 
 * static stack with a max capacity using
 * the RING BUFFER introduced in the handout. 
 * DO NOT add any global (static) variables.
 * Rename the given variables to match your 
 * coding style. 
 *************************************************/

int stack_B_initialized = 0;

void * stack_B_items[PART_B_MAX_SIZE];

unsigned long stack_B_var_1 = 0, stack_B_var_2 = 0, stack_B_var_3 = 0;

/* Edit macros below for your convience BEGIN */
#define EDIT_VAR_NAME_1 stack_B_var_1 
#define EDIT_VAR_NAME_2 stack_B_var_2 
#define EDIT_VAR_NAME_3 stack_B_var_3
/* Edit macros END */ 


/* Add code BEGIN */
// Help unctions only!



/* Add code END */

int stack_B_initialize(){

/* Add code BEGIN */
    if(stack_B_initialized == 1){
        return ERR_INITIALIZED;
    }
    EDIT_VAR_NAME_1 = 0;
    EDIT_VAR_NAME_2 = PART_B_MAX_SIZE;
    stack_B_initialized = 1;
    return 0;


/* Add code END */

}

int stack_B_pop(void** item){

/* Add code BEGIN */
    if(stack_B_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if(EDIT_VAR_NAME_2 == PART_B_MAX_SIZE){
        return ERR_NO_ITEM;
    }
    *item = stack_B_items[EDIT_VAR_NAME_1 - 1];
    EDIT_VAR_NAME_1 -= 1;
    EDIT_VAR_NAME_2 += 1;
    return 0;
/* Add code END */
}

int stack_B_push(void* item){

/* Add code BEGIN */
    if(stack_B_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if(EDIT_VAR_NAME_2 <= 0){
        return ERR_NO_MEM;
    }
    stack_B_items[EDIT_VAR_NAME_1] = item;
    EDIT_VAR_NAME_1 += 1;
    EDIT_VAR_NAME_2 -= 1;
    return 0;


/* Add code END */


}

int stack_B_destroy(){

/* Add code BEGIN */
    if(stack_B_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    EDIT_VAR_NAME_1 = 0;
    EDIT_VAR_NAME_2 = PART_B_MAX_SIZE;
    stack_B_initialized = 0;
    return 0;


/* Add code END */

}

/* END of Part B */

/*************************************************
 * ------------------Part C:---------------------- 
 * In this part, you will implement a
 *  dynamically allocated stack. The stack 
 * should support any large number of items.
 * 
 * You are free to call malloc as you need.
 * However, unlike Part A where each push
 * needs a malloc, you need to follow
 * the rules below to minimize the use of 
 * the malloc WHEN the number of
 * elements reaches 1000:
 * 1.   the number of malloc calls shall not
 *      exceed 1 per 100 elements added
 * 2.   the overall space efficiency 
 *      (total bytes of the items stored/
 *      total bytes malloced) shall be higher
 *      than 80% 
 * You are also required to 
 * recycle all the space freed. That is,
 * the above rules shall always be kept
 * even in the process of pop. 
 * 
 * You MAY add any necessary global (static)
 * variables in this part, as well as
 * structs/types and help functions. 
 *************************************************/
/* dynamically allocated stack, The total number of malloc calls should not exceed 1 per 100 push calls, space efficiency > 80% */
int stack_C_initialized = 0;

/* Add code BEGIN */

/* Add code END */

int stack_C_initialize(){

/* Add code BEGIN */
    
/* Add code END */

    return 0;

}

int stack_C_pop(void** item){

/* Add code BEGIN */
    
/* Add code END */

    return 0;

}

int stack_C_push(void* item){
/* Add code BEGIN */
    
/* Add code END */

    return 0;

}

int stack_C_destroy(){

/* Add code BEGIN */

/* Add code END */

    return 0;

}

/* End of Part C */
