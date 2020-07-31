#include "stdio.h"

char* extract(char* input) {
  int i = 0;
  int j = 0;
  char* ret= "";
  while(input[i]) {
    i++;
    if (input[i] == ':' && input[i-1] == ':' && input[i] != '\0') {
      j = i;
      ret = &input[j+1];
    }
  }
  //printf("%s\n",ret);
  return ret;
}

typedef enum {
  OK,
  FAIL
} Test;

Test testSuffix(char* input, char* expected) {
  Test t;
  int i = 0;
  input = extract(input);

  if (input == expected) {
    t = OK;
  }
  else {
    while(input[i]) {
      i++;
      if( expected[i] == input[i] ) {
        t = OK;
      }
      else {
        t = FAIL;
      }
    }
  }
  return t;
}


typedef struct {
  char* input;
  char* expected;
} TestCase;


void runTests(int no, TestCase test[]) {
  Test t;
  int i;

  for(i=0; i < no; i++) {
    printf("Test %d: \n", i);
    t = testSuffix(test[i].input, test[i].expected);
    printf("Input: %s \n",test[i].input);
    printf("Expected: %s \n",test[i].expected);
    if(OK == t) {
      printf("Result: OK \n\n");
    }
    if(FAIL == t){
      printf("Result: FAIL \n\n");
    }
  }
}

int main() {
  const int testNo = 8;
  TestCase tests[8] = {
       {"", ""},
       {"Ha::ll::o", "o"},
       {"Ha::l::lo", "lo"},
       {"::Hallo", "Hallo"},
       {"H::allo", "allo"},
       {"Hallo", ""},
       {":lll:::::ll::llll:::o", ":o"},
       {"::::o", "o"}
       //{" Hal lo  ", 2}
     };
  runTests(testNo,tests);

  //char input[] = "::o::ca::rina";
  //char* suffix = extract(input);
  //printf("The suffix for the word %s is %s\n", input, suffix);

  return 0;
}
