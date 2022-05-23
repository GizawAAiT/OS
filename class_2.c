#include<stdio.h>
int main(int argc, char const *argv[]){
    int v=8;
    int* pointer = &v;
    printf("%s%d %s%p%s", "\n",v ,"\n", &v,"\n");
    char u[3]={'a','b','m'};
    for ( int looper=1;looper<5;looper++){
        v++;
            printf("%s%d   %p%s", "\n",u[looper] , &u[looper],"\n");

    }
    return 0;
}