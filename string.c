#include <stdio.h>

int main(){
    const char* str= "hello";
    // or
    // char str[6]="hello";
    char* str2;
    printf("%s",str);
    int i=0;
  while (*(str +i) !='\0'){
      *(str2+1)=*(str+1);
      i++;

  
  }
str2[5]='\0';
printf("%s",str2);

}