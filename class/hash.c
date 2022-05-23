#include <stdio.h>
#define Size 1000
#define tSize 10
#include <string.h>
#include <stdbool.h>
typedef struct person
{
    char name[Size];
    int age;
    struct person *next;

} person;
person *hash_table[tSize];
void init_hash_table(){
    for (int i = 0; i < tSize; i++)
    {
        hash_table[i] = NULL;
    }
}


unsigned int hash(char *name)
{
    int l = strnlen(name, Size);
    unsigned int h_val = 0;
    for (int i = 0; i < l; i++)
    {
        h_val += name[i];
        h_val = (h_val * name[i]) % tSize;
    }

    return h_val;
}
bool hash_table_insert(person *p)
{  
    if (p == NULL)
        return false;
   
    int index = hash(p->name);
    printf("%d%s%s\t\t",index,":::::::",p->name);
    person* t=hash_table[index];
    while (t!=NULL)
    {
        if (p->name==t->name)
        
        return false;
        t=t->next;
    }
    
    p->next=hash_table[index];
    hash_table[index]=p;
    return true;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);

    person *tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, tSize) != 0)
    {
        tmp = tmp->next;
    }

    return tmp;
}
person *hash_table_delete(char *name)
{
    int index = hash(name);

    person *tmp = hash_table[index];
    person *pre = NULL;

    while (tmp != NULL && strncmp(tmp->name, name, tSize) != 0)
    {
        pre = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    if (pre == NULL)
    {
        hash_table[index] = tmp->next;
    }
    else
    {
        pre->next = tmp->next;
    }
    return tmp;
}
void print_table(){

    printf("start\n");
    for (int i = 0; i < tSize; i++)
    {   person *tmp = hash_table[i];
        if (tmp == NULL)
        printf("\t%i\t.........\n", i);
        else
        {
            printf("\t%i\t ", i);
            
            while (tmp != NULL)
            {
                printf("%s-->",tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
        }
    printf("End\n");
}
int main()
{
    init_hash_table();
    // print_table();
    person Jacob = {.name = "Jacob", .age = 22};
    person Beyene = {.name = "Beyene", .age = 12};
    person Belay = {.name = "Belay", .age = 33};
    person Urgesa = {.name = "Urgesa", .age = 34};
    person Kassahun = {.name = "Kassahun", .age = 85};
    person Siyum = {.name = "Siyum", .age = 23};

    person Elsabet = {.name = "Elsabet", .age = 22};
    person Manjunat = {.name = "Manjunat", .age = 12};
    person Ekram = {.name = "Ekram", .age = 33};
    person Nehags = {.name = "Nehags", .age = 34};
    person Kullamaa = {.name = "Kullamaa", .age = 85};
    person Lalura = {.name = "Lalura", .age = 23};

    person Asegd = {.name = "Asegd", .age = 22};
    person dagm = {.name = "dagm", .age = 12};
    person mejahned = {.name = "mejahned", .age = 33};
    person Jorahsn = {.name = "Jorahsn", .age = 85};
    person Gashaw = {.name = "Gashaw", .age = 23};

    // hash_table_insert(&Jacob);
    // hash_table_insert(&Jorahsn);
    // hash_table_insert(&mejahned);
    // hash_table_insert(&dagm);
    // hash_table_insert(&Nehags);
    // hash_table_insert(&Asegd);
    // hash_table_insert(&Manjunat);
    // hash_table_insert(&Lalura);
    // hash_table_insert(&Kullamaa);
    // hash_table_insert(&Nehags);
    // hash_table_insert(&Gashaw);
    // hash_table_insert(&Gashaw);

    // hash_table_insert(&Asegd);
    // hash_table_insert(&dagm);
    // hash_table_insert(&Kassahun);
    // hash_table_insert(&mejahned);
    // hash_table_insert(&Jorahsn);
    // hash_table_insert(&Gashaw);

    // init_hash_table();
    // hash_table_insert(&Belay);
    // hash_table_insert(&Urgesa);
    // hash_table_insert(&Kassahun);
    // hash_table_insert(&Siyum);
    // hash_table_insert(&Beyene);
    // hash_table_insert(&Jacob);


   
  
    // hash_table_insert(&Belay);
    //  hash_table_insert(&Manjunat);
    // hash_table_insert(&Urgesa);
    // hash_table_insert(&Kassahun);
    // hash_table_insert(&Siyum);
    // hash_table_insert(&Beyene);
    // hash_table_insert(&Beyene);
    // hash_table_insert(&Jacob);
    // hash_table_insert(&Asegd);
    // hash_table_insert(&Kassahun);
   
    hash_table_insert(&Lalura);
    hash_table_insert(&Manjunat);
    hash_table_insert(&Kullamaa);
    hash_table_insert(&Nehags);
    hash_table_insert(&Gashaw);
    hash_table_insert(&Gashaw);

    // person *d = hash_table_delete("Gashaw");
    // if (d != NULL)
    // {
    //     printf("\n%s Has been deleted\n", d->name);
    // }
print_table();
//     person *v = hash_table_lookup("Gashaw");
//     if (v == NULL)
//     {
//         printf("\nNot found\n");
//     }
//     else
//     {
//         printf("\n%s \n", v->name);
//     }

    
}