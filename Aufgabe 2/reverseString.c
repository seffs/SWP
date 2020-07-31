#include <stdio.h>
#include <stdlib.h>

char* reverse(char *s) {
  int i = 0, j = 0;
    while (s[i])
    {
      j++;
      i++;
    }
  i = 0;
  char* temp = malloc(sizeof(char) * (j+1));
  while (s[i])
    {
    temp[j-i] = s[i++];
    }
  temp[i] = '\0';
  return temp;
}

typedef enum {
  OK,
  FAIL
} Test;

Test testReverse(char* input, char* expected) {
  Test t;
  int i = 0;
  input = reverse(input);

  if (input == expected) {
    t = OK;
  }
  else {
    while(input[i]) {
      i++;
      if(expected[i] == input[i]) {
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
    printf("Test %d \n", i);
    t = testReverse(test[i].input, test[i].expected);
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
       {" ", " "},
       {"ocarina", "aniraco"},
       {"dude", "edud"},
       {"surefire", "eriferus"},
       {"Hallo", "ollaH"},
       {"aa aaa", "aaa aa"},
       {"12_12_12", "21_21_21"},
       {"::o::", "::o::"}
     };
  runTests(testNo,tests);

  return 0;
  }
