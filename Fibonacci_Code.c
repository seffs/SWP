#include "stdio.h"
#include "stdlib.h"

// Standard Fibonacci
int fib(int n){
 int f1, f2;
 printf("fib(%d)\n",n);
 if (n<=1) return 1;
 f1=fib(n-1);
 f2=fib(n-2);
 return f1+f2;
}

// Standard Fibonacci
// and print n's memory location
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

enum  Status {
  Full=0,
  Empty=1
};

struct Fib {
  int fib;
  enum Status status;
};

struct Fib fibArr[100];

typedef struct Fib* FibPtr;

void printFibArray(FibPtr f, int len) {
  int i;

  for(i=0; i<len; i++) {
    printf("fib[%d]=",i);
    if(f[i].status == Empty) {
      printf("Empty\n");
    }
    else {
      printf("%d\n",f[i].fib);
    }
  }
}

FibPtr allocFibArray(int len) {
  FibPtr f, f2;
  int i;

  f = malloc(sizeof(struct Fib) * len);

  f2 = f;
  for(i = 0, f2 = f; i < len; i++,f2++) {
    f2->status = Empty;
  }

  return f;
};

// Variante: Pointer auf zu allokierenden Speicherbereich
// wird als Argument uebergeben. Deshalb Uebergabe als
// 'Referenz' => pointer of pointer
void allocFibArray2(int len, FibPtr* f) {
  *f = allocFibArray(len);
}

struct FibArray {
  FibPtr f;
  int len;
};

// Fibonacci und dynamische Programmierung
int fib3(struct FibArray fa, int n){
  int f1, f2, fib;

 if (n <= 0) return 1;

 // Lookup falls schon berechnet
 // und Index innerhalb Grenzen ist
 if(n < fa.len) {
   if(fa.f[n].status == Full) {
     return fa.f[n].fib;
   }
 }

 // Berechne fib, weil
 // (a) erste Berechnung, oder
 // (b) Index ausserhalb Grenzen ist
 if (n<=1) {
   fib = 1;
 }
 else {
    f1=fib3(fa,n-1);
    f2=fib3(fa,n-2);
    fib = f1 + f2;
 }

 // Set fib Wert, falls Index innerhalb Grenzen ist
 if(n < fa.len) {
   if(fa.f[n].status == Empty) { // Redundant?
     fa.f[n].status = Full;
     fa.f[n].fib = fib;
   }
 }
 return fib;
}


// Redundant, weil falls nicht Empty => Full,
// aber dann haetten wir ja schon einen lookup
// durchgefuehrt und hatten den gespeicherten fib Wert
// zurueckgegeben. Also, muss der status hier immer Empty sein.



// Fibonacci und dynamische Programmierung
// mit dynamischer Anpassung von fa.
// Pointer auf FibArray, so dass wir Laengenaenderung
// von 'aussen' beobachten koennen.
int fib4(struct FibArray* fa, int n){
  int f1, f2, fib;

 if (n <= 0) return 1;

 if(n < fa->len) {
   if(fa->f[n].status == Full) {
     return fa->f[n].fib;
   }
 }
 // Dynamische Anpassung durch Verdopplung
 // (1) Allokieren neuen Speicherbereich
 // (2) Kopiere 'alt' nach 'neu'
 // (3) Gebe 'alt' frei
 else {
  FibPtr fPtr;
  int i;
  fPtr = allocFibArray(fa->len * 2);    // (1)
  for(i=0; i < fa->len; i++)            // (2)
              fPtr[i] = fa->f[i];
  free(fa->f);                          // (3)
  fa->f = fPtr;
  fa->len = fa->len * 2;
 }

 if (n<=1) {
   fib = 1;
 }
 else {
    f1=fib4(fa,n-1);
    f2=fib4(fa,n-2);
    fib = f1 + f2;
 }

 if(n < fa->len) {
   if(fa->f[n].status == Empty) { // Immer noch redundant?
     fa->f[n].status = Full;
     fa->f[n].fib = fib;
   }
 }
 return fib;
}
// if(fa->f[n].status == Empty) ist redundant
// aber NICHT if(n < fa->len),
// wir haben keine Garantie dass der erweiterte Bereich
// gross genug ist!

// Mittels defines Auswahl der jeweiligen Version
// #define STANDARD_FIB
// #define FIB_MEM_LOC
// #define FIB_DYN
#define FIB_DYN_DYN

int main() {

#ifdef STANDARD_FIB

  printf("fib(%d) = %d \n", 4,fib(4));

#endif

#ifdef FIB_MEM_LOC

  printf("fib2(%d) = %d \n", 4,fib2(4));

#endif


#ifdef FIB_DYN

  FibPtr f;
  struct FibArray fa;
  int len;

  len = 9;

  allocFibArray2(len,&f);
  printFibArray(f,len);

  fa.len = len;
  fa.f = f;

  fib3(fa,len+1);

  printFibArray(fa.f,fa.len);

#endif



#ifdef FIB_DYN_DYN

  FibPtr f;
  struct FibArray fa;
  int len;

  len = 9;

  allocFibArray2(len,&f);
  printFibArray(f,len);

  fa.len = len;
  fa.f = f;

  fib4(&fa,len*3);

  printFibArray(fa.f,fa.len);

#endif

  return 1;
}
