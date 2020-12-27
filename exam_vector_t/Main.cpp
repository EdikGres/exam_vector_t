#include <stdio.h>
#include <stdlib.h>
#include "VectorLib.h"
/*
	Реализовать vector для любого типа данных с помощью *void
*/
using namespace myvector;
int main() {

	vector_t v;
	init(&v);
	push_back(&v, 256);
	push_back(&v, 216);
	push_back(&v, 2124);
	push_back(&v, -500);
	set(&v, 1, -1);
	
	int a = 0;
	if (get(&v, 4, &a) == 0)
	{
		printf("ERROR!\n");
	}
	insert(&v, 0, 999);
	erase(&v, 2);
	printv(&v);
	printf("GET: %d ", a);
	destroy(&v);
	return 0;
}