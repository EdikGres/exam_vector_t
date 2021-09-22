#ifndef VECTOR_LIB_H
#define VECTOR_LIB_H
namespace myvector {
	typedef struct vector_t {
		int* data;
		size_t size;
		size_t capacity;
	};
	void init(vector_t* vect); //O(1)
	void destroy(vector_t* vect); // O(1)
	int push_back(vector_t* vect, int val); //амортизированное O(1), т.е. иногда O(n)
	void printv(vector_t* vect); // O(n)
	int set(vector_t* vect, size_t i, int val); // O(1)
	int get(vector_t* vect, int i, int* res); // O(1)
	int insert(vector_t* vect, int i, int val); //O(n)
	void erase(vector_t* vect, int i);
}


#endif