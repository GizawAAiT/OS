//largest of the given numbers:
#include<stdio.h>
#include<stdbool.h>
int main(int argc, char const *argv[])
{   
    float x,condition=1;
    float largest=0;
    bool stop=false;
    while(condition){
        printf("Enter a number: ");
        scanf("%f",&x);

        (x>0)?
        ((x>largest)?largest=x:largest):(stop=true);
    if (stop){printf("%s%f%s","The largest number entered was ",largest,"\n");
    break;}
    }
    
    return 0;
}
