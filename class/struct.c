#include <stdio.h>
typedef struct{
    int length;
     int width; 
}rect;
typedef struct  {
    int x;
    int y;

}pos;

typedef struct 
{
    rect r;
    pos p;
    char* owner;

}boilding;



void main(){
   rect a = {5,6};
printf("%d,%d",a.length,a.width);
   boilding mybuilding = {{1,2},{22,24},"Hana"};
   printf("\n");
   printf("%s,%d,%d,%d,%d",mybuilding.owner,mybuilding.p.x,mybuilding.p.y,mybuilding.r.length,mybuilding.r.width);

//    return 0;

}