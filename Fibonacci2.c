#include "stdio.h"

int fib2(int n) {
 int f1, f2;
 int* nPtr;
 printf("fib2(%d)\n",n);
 nPtr = &n;
 printf("&n = %ld \n",(long int)nPtr);
 if (n<=1) return 1;
 f1=fib2(n-1);
 f2=fib2(n-2);
 return f1+f2;
}

main(){
  fib2(5);
  int i = 1;
  int* iPtr;

  printf("i=%d \n", i);

  printf("Adresse von i = %ld \n", (long int)&i);

  iPtr = &i;

  printf("i=%d \n",*iPtr);
  return 0;
}
