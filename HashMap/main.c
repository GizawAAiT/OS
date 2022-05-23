// #include <stdio.h>
#include "./hashtable/hashtable.h" 
#include<assert.h>
int main(int argc, char const *argv[]) {
HashTable*t;
t=create();
add(t,"Master",332);
add(t,"Kasshesh",332);
add(t,"Hashe",332);
add(t,"Hashe",32);
add(t,"Natnael",332);


assert( add(t, "Test Key", 11) == true);
assert( add(t, "Nnaewsdjanh", 11) == true);
delete_table(t);
return 0;

}
