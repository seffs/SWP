#include <stdio.h>
#include <math.h>

void leibniz_sequence () {
  int n = 1000000;
  double pi4tel = 0.0;
  int i;
  for (i = 1; i <= n; i++) {
    if (i % 2 == 1) {
      pi4tel += 1.0 / (2 * i - 1);
	  }
    else {
      pi4tel -= 1.0 / (2 * i - 1);
    }
  }
  printf("%d\n", i);
  printf("%.5f\n",pi4tel * 4.0);
}

void bbp() {
  double pi = 0;
  int n = 1000000;
  for (int i = 1; i<=n; i++) {
    pi += (1.0/(1 << (4*i))) * ((4.0 / 8.0*i + 1) - (2.0 / 8.0*i + 4) - (1.0 / 8.0*i + 5) - (1.0 / 8.0*i + 6));
  }
  printf("%.5f\n",pi);
}



int main() {
  leibniz_sequence();
  bbp();
  return 0;
}
