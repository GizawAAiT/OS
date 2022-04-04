// reducing a given fraction to the lowest term!
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int a,b,alowest,blowest,tempo;
    printf("Enter a fraction! :  ");
    scanf("%d/%d",&a,&b);


    alowest=a,blowest=b;

     while (a!=0)
    {
        tempo=b%a;
        b=a;
        a=tempo;
    }
    alowest /=b,blowest/=b;

    printf("%s%d/%d%s","In lowest terms :  ",alowest,blowest,"\n");
    

    return 0;
}
