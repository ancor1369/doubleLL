/*
 * ddl.h
 *
 *  Created on: Jul. 1, 2020
 *      Author: andres
 */

#ifndef DLL_H_
#define DLL_H_

typedef struct dll_node_{
	void *data;
	struct ddl_node_ *left;
	struct dll_node *right;
}dll_node_t;

typedef struct ddl_{
	dll_node_t *head;
	int (*key_match)(void *, void*); //This is a function pointer
}dll_t;

/*Public functions to intereact with the double linked list*/

void register_key_match_callback(dll_t *dll, int (*key_match)(void *, void*));

dll_t * get_new_ddl();

int add_data_to_dll(dll_t *dll, void *app_data);

int remove_data_from_dll_by_data_ptr(dll_t *dll, void *data);

int is_dll_empty(dll_t *dll);

void drain_dll(dll_t *dll);

void * dll_search_by_key(dll_t *dll, void *key);

#endif /* DLL_H_ */
