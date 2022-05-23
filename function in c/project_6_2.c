// GCD of 2 numbers!
#include<stdio.h>
int main(int argc, char const *argv[])
{
// declaration
    int x,y,a,b,tempo;

    printf("Entrr two integers: ");
    scanf("%d%d",&x,&y);
    (x<y)?(a=x,b=y):(a=y,b=x);

    while (a!=0)
    {
        tempo=b%a;
        b=a;
        a=tempo;
    }
    printf("%s%d%s","Greatest common Devisor : ",b,"\n");
    
    return 0;
}
