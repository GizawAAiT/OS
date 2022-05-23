#include <stdbool.h>

struct Binding;
typedef struct Binding Binding;


struct HashTable;
typedef struct HashTable HashTable;

HashTable* create();

unsigned int hash(const char* key);

bool add( HashTable* table, const char* key, int value);

Binding* find( HashTable* table, const char* key);

bool remove(HashTable* table, const char* key);
void delete_table(struct HashTable* table);
