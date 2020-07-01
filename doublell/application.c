#include "ddl.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct person_{
	char name[32];
	int age;
	int weight;
}person_t;

static void print_person_details(person_t *person){
	printf("Name = %s\n", person->name);
	printf("Age = %d\n", person->age);
	printf("Weight = %d\n", person->weight);
}

static void print_person_db(dll_t *person_db)
{
	if(!person_db || !person_db->head) return;

	dll_node_t *head=person_db->head;
	person_t *data = NULL;

	while(head)
	{
		data = head->data;
		print_person_details(data);
		head = head->right;
	}

}


int main()
{
	person_t *personal1 = calloc(1, sizeof(person_t));
	strncpy(personal1->name, "Andres", strlen("Andres"));
	personal1->age = 31;
	personal1->weight = 75;
	person_t *personal2 = calloc(1, sizeof(person_t));
	strncpy(personal2->name, "Katherine", strlen("Katherine"));
	personal2->age = 25;
	personal2->weight = 60;

	dll_t *person_db = get_new_ddl();
	add_data_to_dll(person_db,personal1);
	add_data_to_dll(person_db, personal2);

	print_person_db(person_db);
	return 0;
}
