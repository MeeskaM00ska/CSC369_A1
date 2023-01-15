#include "queue.h"


/*************************************************
 * Implement the following functions.
 * DO NOT add any global (static) variables,
 * Except in Part C.
 * You can add help functions as you need.
 ************************************************/


/*************************************************
 * ------------------Part A:---------------------- 
 * In this part, you will implement
 * a  dynamically allocated queue with
 * a linked list. 
 * DO NOT add any global (static) variables.
 *************************************************/

int queue_A_initialized = 0;

typedef struct queue_A_node{

/* Add code BEGIN */
    struct queue_A_node *next;
    struct queue_A_node *prev;


/* Add code END */

    void* item;

} 
queue_A_node_t;

queue_A_node_t * queue_A_root = NULL;
queue_A_node_t * queue_A_tail = NULL;

/* Add code BEGIN */
// Help unctions only!
/* Add code END */

int queue_A_initialize(){

/* Add code BEGIN */
    if(queue_A_initialized == 1){
        return ERR_INITIALIZED;
    }
    queue_A_root = (queue_A_node_t*)malloc(sizeof(queue_A_node_t));
    queue_A_tail = (queue_A_node_t*)malloc(sizeof(queue_A_node_t));
    queue_A_root->next = queue_A_tail;
    queue_A_tail->next = NULL;
    queue_A_root->prev = NULL;
    queue_A_tail->prev = queue_A_root;
    queue_A_initialized = 1;
    return 0;


/* Add code END */

}

int queue_A_enq(void* item){

/* Add code BEGIN */
    if(queue_A_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    queue_A_node_t *new_node = (queue_A_node_t*)malloc(sizeof(queue_A_node_t));
    new_node->item = item;
    new_node->next = queue_A_tail;
    new_node->prev = queue_A_tail->prev;
    queue_A_tail->prev->next = new_node;
    queue_A_tail->prev = new_node;
/* Add code END */

    return 0;

}

int queue_A_deq(void** item){

/* Add code BEGIN */
    if(queue_A_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if(queue_A_root->next == queue_A_tail){
        return ERR_NO_ITEM;
    }
    queue_A_node_t *ptr = queue_A_root->next;
    *item = ptr->item;
    queue_A_root->next = ptr->next;
    ptr->next->prev = queue_A_root;
    free(ptr);
/* Add code END */

    return 0;

}

int queue_A_destroy(){

/* Add code BEGIN */
    if(queue_A_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    queue_A_node_t *ptr = queue_A_root;
    while(ptr != NULL){
        queue_A_node_t *ptr2 = ptr->next;
        free(ptr);
        ptr = ptr2;
    }
    queue_A_initialized = 0;
/* Add code END */

    return 0;

}

/* END of Part A */

/*************************************************
 * ------------------Part B:---------------------- 
 * In this part, you will implement a 
 * static queue with a max capacity using
 * the RING BUFFER introduced in the handout. 
 * DO NOT add any global (static) variables.
 * Rename the given variables to match your 
 * coding style. 
 *************************************************/

int queue_B_initialized = 0;

void * queue_B_items[PART_B_MAX_SIZE];

unsigned long queue_B_var_1 = 0, queue_B_var_2 = 0, queue_B_var_3 = 0;

/* Edit macros below for your convience BEGIN */
#define EDIT_VAR_NAME_1 queue_B_var_1 
#define EDIT_VAR_NAME_2 queue_B_var_2 
#define EDIT_VAR_NAME_3 queue_B_var_3
/* Edit macros END */ 


/* Add code BEGIN */
// Help unctions only!



/* Add code END */

int queue_B_initialize(){

/* Add code BEGIN */
    if(queue_B_initialized == 1){
        return ERR_INITIALIZED;
    }
    EDIT_VAR_NAME_1 = 0;
    EDIT_VAR_NAME_2 = 0;
    EDIT_VAR_NAME_3 = 0;
    queue_B_initialized = 1;


/* Add code END */

    return 0;

}

int queue_B_enq(void* item){

/* Add code BEGIN */
    if(queue_B_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if(EDIT_VAR_NAME_1 == PART_B_MAX_SIZE){
        return ERR_NO_MEM;
    }
    queue_B_items[EDIT_VAR_NAME_2] = item;
    EDIT_VAR_NAME_2 = (EDIT_VAR_NAME_2 + 1) % PART_B_MAX_SIZE;
    EDIT_VAR_NAME_1+=1;


/* Add code END */

    return 0;

}

int queue_B_deq(void** item){

/* Add code BEGIN */
    if(queue_B_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if(EDIT_VAR_NAME_1 == 0){
        return ERR_NO_ITEM;
    }
    *item = queue_B_items[EDIT_VAR_NAME_3];
    EDIT_VAR_NAME_3 = (EDIT_VAR_NAME_3 + 1) % PART_B_MAX_SIZE;
    EDIT_VAR_NAME_1-=1;


/* Add code END */

    return 0;

}

int queue_B_destroy(){

/* Add code BEGIN */
    if(queue_B_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    EDIT_VAR_NAME_1 = 0;
    EDIT_VAR_NAME_2 = 0;
    EDIT_VAR_NAME_3 = 0;
    queue_B_initialized = 0;


/* Add code END */

    return 0;

}

/* END of Part B */

/*************************************************
 * ------------------Part C:---------------------- 
 * In this part, you will implement a
 *  dynamically allocated queue. The queue 
 * should support any large number of items.
 * 
 * You are free to call malloc as you need.
 * However, unlike Part A where each enqueue
 * needs a malloc, you need to follow
 * the rules below WHEN the number of
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
 * even in the process of dequeue. 
 * 
 * You MAY add any necessary global (static)
 * variables in this part, as well as
 * structs/types and help functions. 
 *************************************************/

int queue_C_initialized = 0;

/* Add code BEGIN */
void** values;
int capacity;
int size;
int start;
/* Add code END */

int queue_C_initialize()
{
/* Add code BEGIN */
    if (queue_C_initialized == 1){
        return ERR_INITIALIZED;
    }
    values = (void**)malloc(sizeof(void*) * 1000);
    if (values == NULL) {
        return ERR_NO_MEM;
    }
    capacity = 1000;
    size = 0;
    start = 0;
    queue_C_initialized = 1;
/* Add code END */
    return 0;
}

int queue_C_enq(void* item)
{
/* Add code BEGIN */
    if (queue_C_initialized == 0) {
        return ERR_NOT_INITALIZED;
    }
    if (size == capacity)
    {
        int capacity_b4 = capacity;
        capacity = (int)(size / 0.9);
        void** values2= (void**)malloc(sizeof(void*) * capacity);
        int i;
        for (i = 0; i < size; i++)
        {
            int j = (start + i) % capacity_b4;
            values2[i] = values[j];
        }
        free(values);
        values = values2;
        start = 0;
        if (values == NULL) {
            return ERR_NO_MEM;
        }
    }
    int end = (start + size) % capacity;
    values[end] = item;
    size+=1;
/* Add code END */
    return 0;
}

int queue_C_deq(void** item)
{
/* Add code BEGIN */
    if (queue_C_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    if (size == 0) {
        return ERR_NO_ITEM;
    }
    //seg fault
    if(item == NULL){
        return ERR_INVALID_ARG;
    }

    *item = values[start];
    start+=1;
    if (start >= capacity){
        start = 0;
    }

    size-=1;
    if (capacity > 1000 && size / (double)capacity < 0.8)
    {
        int capacity_b4 = capacity;
        capacity = (int)(size / 0.9);
        if (capacity < 1000) capacity = 1000;
        void** values2 = (void**)malloc(sizeof(void*) * capacity);
        int i;
        for (i = 0; i < size; i++)
        {
            int j = (start + i) % capacity_b4;
            values2[i] = values[j];
        }
        free(values);
        values = values2;
        start = 0;
    }
    if (size == 0){
        start = 0;
    }
/* Add code END */
    return 0;

}

int queue_C_destroy()
{
/* Add code BEGIN */
    if (queue_C_initialized == 0){
        return ERR_NOT_INITALIZED;
    }
    free(values);
    queue_C_initialized = 0;
/* Add code END */
    return 0;
}

/* End of Part C */