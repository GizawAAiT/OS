// approximating the vlue of e to the n term:
#include<stdio.h>
int main(int argc, char const *argv[])
{

    // declare vars!
    float e = 1;
    int n;

    printf("Enter the step number n  to approximate the number e:  ");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int iter=i;
        while(iter>1){i=i*iter;iter=iter-1;}
        e = e + (1.0/i);
    }
    printf("%s%d%s%f%s","The value of e approximated in ",n," steps is ",e,"\n" );
    return 0;
}
