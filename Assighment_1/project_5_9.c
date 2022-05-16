
// program to identify the earlier date:
#include <stdio.h>
int main(int argc, char const *argv[])
{
    //   var declaration!
    int month1,year1,day1,month2,year2,day2;

    // prompting user for input!
    printf("Enter the first date( mm/dd/yy): ");
    scanf("%d /%d /%d",&month1,&day1,&year1);    
    
    printf("Enter the second date( mm/dd/yy): ");
    scanf("%d /%d /%d",&month2,&day2,&year2); 

    // the logic!
    if ((day1+month1*30+year1*(364.25))==(day2+month2*30+year2*(364.25))){
        printf("the same day!\n");
    }
    else {

    ((day1+month1*30+year1*(364.25))<(day2+month2*30+year2*(364.25)))? 
    printf("%d /%d /%d %s %d /%d /%d,%s",month1,day1,year1," is earlier than ",month2,day2,year2 ,"\n"): 
    printf("%d /%d /%d %s %d /%d /%d,%s",month2,day2,year2," is earlier than ",month1,day1,year1 ,"\n");
    }

    return 0;
}
