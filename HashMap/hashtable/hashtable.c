#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define BUCKET_COUNT 1024

typedef struct Binding {
  const char *key;
  int value;
  struct Binding *next;


}Binding;
 struct HashTable {
 struct Binding* buckets[BUCKET_COUNT];
};

struct HashTable* create() {
struct  HashTable *table;
  table =(struct HashTable*) malloc(sizeof(struct HashTable));
  for (int i = 0; i < BUCKET_COUNT;  i++) {
  table->buckets[i]=NULL;
  }   
  return table;
}

unsigned int hash(const char* key) {
  int l = strnlen(key, BUCKET_COUNT);
  unsigned int h_val = 0;
  for (int i = 0; i < l; i++) {
    h_val += key[i];
    h_val = (h_val * (key[i]*2 + strnlen(key,BUCKET_COUNT)) )% BUCKET_COUNT;
  }
  return h_val;
}

bool add(struct HashTable* table, const char* key, int value){
   if (key == NULL)
    return false;
    struct Binding *node= (struct Binding*)malloc(sizeof(struct Binding));
    node->key=key;
    node->value=value;
    int index = hash(key);
    struct Binding *t = table->buckets[index];
    while (t != NULL) {
      if (node->key == t->key) {
        t->value=node->value;
        return false;}
      t = t->next;
  }

  node->next = table->buckets[index];
  table->buckets[index] = node;
  return true;
}
struct Binding* find(struct HashTable* table, const char* key) {
  int index = hash(key);

  struct  Binding *tmp = table->buckets[index];
  while (tmp != NULL && strncmp(tmp->key, key, BUCKET_COUNT) != 0) {
    tmp = tmp->next;
  }

  if (tmp != NULL){
    return tmp;
  }
    
  else{
  return NULL;
  }
   
}


bool remove(struct HashTable* table, const char* key){
  int index = hash(key);

 struct Binding *tmp = table->buckets[index];
 struct Binding *pre = NULL;

  while (tmp != NULL && strncmp(tmp->key, key, BUCKET_COUNT) != 0) {

      pre = tmp;
      tmp = tmp->next;
    }
    if (tmp == NULL){return false;}
      
    if (pre == NULL) { 
      table->buckets[index] = table->buckets[index]->next; 
      return true;
      } 
    else {
      pre->next = tmp->next;
      return true;
    }
  
}
void delete_table(struct HashTable* table){
  free(table);

  for (size_t i = 0; i < BUCKET_COUNT; i++)
  {
    free(table->buckets[i]);
    table->buckets[i]=NULL;
  }
  table=NULL;
}


