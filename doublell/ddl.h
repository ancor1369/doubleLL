/*
 * ddl.h
 *
 *  Created on: Jul. 1, 2020
 *      Author: andres
 */

#ifndef DDL_H_
#define DDL_H_

typedef struct dll_node_{
	void *data;
	struct ddl_node_ *left;
	struct dll_node *right;
}dll_node_t;

typedef struct ddl_{
	dll_node_t *head;
}dll_t;

/*Public functions to intereact with the double linked list*/

dll_t * get_new_ddl();

int add_data_to_dll(dll_t *dll, void *app_data);


#endif /* DDL_H_ */
