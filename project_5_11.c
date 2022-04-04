// printing the English word of the given 2 digit num!
#include <stdio.h>
#include <string.h>
#include<math.h>
int main(int argc, char const *argv[])
{
// declaraton
    int num;
    char sentence[50];

    // input
    printf("Enter a two digit number: ");
    scanf("%d",&num);
    // the logic
    if (num>=11 && num<20){
        switch (num)
        {
        case 11:
            printf("You entered the number eleven\n");
            break;
        case 12:
            printf("You entered the number twelve\n");
            break;
        case 13:
            printf("You entered the number thirteen\n");
            break;
        case 14:
            printf("You entered the number fourteen\n");
            break;
        case 15:
            printf("You entered the number fifteen\n");
            break;
        case 16:
            printf("You entered the number sixteen\n");
            break;
        case 17:
            printf("You entered the number seventeen\n");
            break;
        case 18:
            printf("You entered the number eighteen\n");
            break;
        case 19:
            printf("You entered the number ninteen\n");
            break;
        
    }}
    else{
        char tens[][12]={"zero","ten","twenty","thirty","forty","fifty","sixty","sevnty","eighty","ninty"};
        char unit[][12]={"zero","one","two","three","four","five","six","seven","eight","nine"};
// for(int i=0;i<9;i++){printf("%s",unit[i]);}
       if (num<10){strcpy(sentence, unit[num]);}
       else if (num<100){
           strcpy(sentence, tens[(int)(floor(num/10))]);
          ( (num%10!=0))? strcat(strcat(sentence,"-" ),(unit[num%10])):sentence;
       }
       else{strcpy(sentence,"the code can handles only 2 digit numbers!\n");}
       printf("%s %s %s","You entered the number ",sentence,"\n");

    }
    
    return 0;
}
