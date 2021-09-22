#include <stdio.h>
#include <stdlib.h>
#include "VectorLib.h"

namespace myvector {
	void init(vector_t* vect) {
		vect->data = NULL;
		vect->capacity = 0;
		vect->size = 0;
	}
	void destroy(vector_t* vect) {
		if (vect->data != NULL)
			free(vect->data);
	}
	int push_back(vector_t* vect, int val) {
		int* tmp = NULL;
		if (vect->size == vect->capacity)
		{
			if (vect->capacity == 0)
				vect->capacity = 1;
			vect->capacity *= 2;
			tmp = (int*)malloc(sizeof(int) * vect->capacity);
			if (tmp == NULL)
				return 0;
			for (size_t i = 0; i < vect->size; i++)
			{
				tmp[i] = vect->data[i];
			}
			free(vect->data);
			vect->data = tmp;
		}
		vect->data[vect->size++] = val;
		return 1;
	}
	void printv(vector_t* vect) {
		for (size_t i = 0; i < vect->size; i++)
		{
			printf("%d ", vect->data[i]);
		}
		printf("\n");
	}
	int set(vector_t* vect, size_t i, int val) {
		if (i < 0 || i >= vect->size)
		{
			return 0;
		}
		vect->data[i] = val;
		return 1;
	}
	int get(vector_t* vect, int i, int* res) {
		if (i < 0 || i >= (int)vect->size)
		{
			return 0;
		}
		*res = vect->data[i];
		return 1;
	}
	int insert(vector_t* vect, int i, int val) {
		if (push_back(vect, 0) == 0)
			return 0;
		for (size_t j = vect->size - 1; (int)j > i; j--)
		{
			vect->data[j] = vect->data[j - 1];
		}
		vect->data[i] = val;
		return 1;
	}
	void erase(vector_t* vect, int i) {
		for (size_t j = i; j < vect->size ; j++)
		{
			vect->data[j] = vect->data[j + 1];
		}
		vect->size--;
	}


}