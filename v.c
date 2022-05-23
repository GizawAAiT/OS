# include <stdio.h>
# define  N 700

int main (){
    int b[N][N]={{2}};
    for (int i =0;i<700;i++){
        for (int j =0;j<700;j++){
printf("%d  %s",b[i][j],"\t");
        }
        printf("%s","\n");
    }
    
    return 0;
}
