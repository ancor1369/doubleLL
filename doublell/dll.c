#include "dll.h"

#include <memory.h>
#include <stdlib.h>

//Public function implementations

dll_t * get_new_ddl()
{
	dll_t *dll = calloc(1, sizeof(dll_t));
	dll->head=NULL;
	return dll;
}

int add_data_to_dll(dll_t *dll, void *app_data)
{
	if(!dll || !app_data) return -1;

	dll_node_t *dll_new_node = calloc(1, sizeof(dll_new_node));
	dll_new_node->left = NULL;
	dll_new_node->right = NULL;
	dll_new_node->data = app_data;

	if(!dll->head){
		dll->head = dll_new_node;
		return 0;
	}

	dll_node_t *first_node = dll->head;
	dll_new_node->right = first_node;
	first_node->left = dll_new_node;
	dll->head = dll_new_node;	
	return 0;
}

//This function is defined as a callback.
//When the client code needs to use specific data, it will actually
//call an existing function in the client code
void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void*))
{
	dll->key_match = key_match;
}

//generic search function
void * dll_search_by_key(dll_t *dll, void *key){
	if(!dll || !dll->head) return NULL;
	dll_node_t *head = dll->head;
	while(head)
	{
		//Next line invokes the method implemented in the client code
		if(dll->key_match(head->data, key)==0)
			return (void*)head->data;
		head = head->right;
	}
	return NULL;
}
