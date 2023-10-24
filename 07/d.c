#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct memory_unit {
	void* mem;
	void (*clean)(void*);
	struct memory_unit* prev;
} memory_unit;

typedef struct cleaner {
	memory_unit* last;
	struct cleaner prev;
} cleaner;

cleaner* curr_cleaner;

void new_cleaner() {
	cleaner* c = malloc(sizeof(c));
	c->last = NULL;
	c->prev = curr_cleaner;
	curr_cleaner = c;
}

void add_new_mem(void* mem, void (*clean)(void*)) {
	memory_unit* unit = malloc(sizeof(memory_unit));
	unit->mem = mem;
	unit->clean = clean;
	unit->prev = curr_cleaner->last;
	curr_cleaner->last = unit;
}

void clean() {
	while (curr_cleaner->last != NULL) {
		memory_unit* unit = curr_cleaner->last;
		unit->clean(unit->mem);
		curr_cleaner->last = unit->prev;
		free(unit);
	}
	cleaner* c = curr_cleaner;
	curr_cleaner = c->prev;
	free(c);
}

int main() {
	new_cleaner();

	add_new_mem();

	{
		new_cleaner();

		add_new_mem();

		clean();
	}

	clean();
}