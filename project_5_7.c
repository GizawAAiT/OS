// largest and smallest of fout number
#include <stdio.h>
#include <math.h>
// #include math.h

int main(int argc, char const *argv[])
{
    int a,b,c ,d,sm1,sm2,lr1,lr2;
    printf("Enter four integers(notice that each separated by a space):  ");
fflush(stdout);
    scanf("%d %d %d %d",&a,&b,&c,&d);

    if (a<=b){ sm1=a,lr1=b;}
    else { sm1=b,lr1=a;}
   
    if (c<=d){ sm2=c,lr2=d;}
    else { sm2=d,lr2=c;}
   
    
    (lr1>=lr2)?printf("largest : %d",lr1):printf("\nlargest : %d",lr2);
    (sm1<=sm2)?printf("\nsmallest : %d",sm1):printf("\nsmallest : %d",sm2);
    printf(" \n"); 
// printf("%3d%3d%3d%3d",a,b,c,d);
    return 0;
}
