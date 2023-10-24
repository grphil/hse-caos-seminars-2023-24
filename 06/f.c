#include <stdio.h>
#include <stdlib.h>

typedef struct {
	size_t size;
	size_t capacity;
	int* v;
} vector;

vector vector_new() {
	return (vector){
		.size = 0, 
		.capacity = 0,
		.v = NULL
	};
}

void vector_delete(vector* v) {
	free(v->v);
}

void vector_push_back(vector* this, int x) {
	if (this->size == this->capacity) {
		size_t new_cap = this->capacity * 2 + 1;
		int* new_v = realloc(this->v, new_cap * sizeof(*new_v));
		this->v = new_v;
		this->capacity = new_cap;
	}
	this->v[this->size] = x;
	this->size++;
}

int main() {
	vector v = vector_new();
	vector_push_back(&v, 1);
	vector_push_back(&v, 2);
	vector_push_back(&v, 3);
	printf("%d %d %d %lu %lu\n", v.v[0], v.v[1], v.v[2], v.size, v.capacity);
	vector_push_back(&v, 4);
	printf("%d %d %d %lu %lu\n", v.v[0], v.v[1], v.v[2], v.size, v.capacity);
	vector_delete(&v);
}