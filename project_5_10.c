// convert the numberic grading to letter grade!
#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
//   declare var!
int grade,test=-1;
 
//  primpt user to accept numerical grade! 
    printf("Entern numerical grade: ");
    scanf("%d",&grade);

//    find the test case!
 if(grade>100&&grade<110){test=11;}
else if(grade>=0){test=floor(grade/10);}
// switch the test case!
switch (test)
{
case 0:case 1:case 2:case 3:case 4:case 5:
    printf("Letter grade: F\n");
    break;
case 6:
    printf("Letter grade: D\n");
    break;
case 7:
    printf("Letter grade: C\n");
    break;
case 8:
    printf("Letter grade: B\n");
    break;
case 9:case 10:
    printf("Letter grade: A\n");
    break;

default:
printf("INVALID GRADE(Grade should be between 0 and 100!)\n");
    break;
}
    return 0;//done!
}
