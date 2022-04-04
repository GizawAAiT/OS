#include <stdio.h>
int main()
{
    int i;
    float l;
    printf("size :\n");
    scanf("%d",&i);
    
    int array[i];
    printf("%s %d","size==len==:",(int)(sizeof(array) / sizeof(int)));

    for (int a=0;a<i;a++){
        scanf("%d",&array[a]);
        // array[a]=l;
    };
    printf("%s %d","size==len==:",(int)(sizeof(array) / sizeof(int)));
    for (int a=0;a<(int)(sizeof(array) / sizeof(int));a++){
    printf("%d %s",array[a],"\n");
    // printf("break");
    }

    return 0;
    
}
