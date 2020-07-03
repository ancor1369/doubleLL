#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dll.h"


typedef struct person_{
	char name[32];
	int age;
	int weight;
	unsigned int id;
}person_t;

static void print_person_details(person_t *person){
	printf("ID=%d\n", person->id);
	printf("Name = %s\n", person->name);
	printf("Age = %d\n", person->age);
	printf("Weight = %d\n", person->weight);
}

static void print_person_db(dll_t *person_db)
{
//	OLD code
//	if(!person_db || !person_db->head) return;
//
//	dll_node_t *head=person_db->head;
//	person_t *data = NULL;
//
//	while(head)
//	{
//		data = head->data;
//		print_person_details(data);
//		head = head->right;
//	}

	dll_node_t * temp = NULL;
	person_t * data = NULL;
	ITERATE_LIST_BEGIN(person_db, temp)
	{
		data = temp->data;
		print_person_details(data);
	}ITERATE_LIST_END;

}

static int match_person_rec_by_key(void *data, void *key)
{
	person_t *person = (person_t*)data;
	unsigned int id = (unsigned int)key;
	if(person->id == id)
		return 0;
	return -1;
}

int main()
{
	person_t *personal1 = calloc(1, sizeof(person_t));
	strncpy(personal1->name, "Andres", strlen("Andres"));
	personal1->age = 31;
	personal1->weight = 75;
	personal1->id = 12;
	
	person_t *personal2 = calloc(1, sizeof(person_t));
	strncpy(personal2->name, "Katherine", strlen("Katherine"));
	personal2->age = 25;
	personal2->weight = 60;
	personal2->id = 13;

	dll_t *person_db = get_new_ddl();

	register_key_match_callback(person_db, match_person_rec_by_key);

	add_data_to_dll(person_db,personal1);
	add_data_to_dll(person_db, personal2);

	person_t *person = dll_search_by_key(person_db, (void *)13);

	if(!person)
	{
		printf("Person Record not found\n");
	}
	else
	{
		print_person_details(person);
	}

	print_person_db(person_db);
	return 0;
}
