#include <iostream>
#include <omp.h>

using namespace std;

static long num_steps = 100000000;
double step;


int main() {

      double x, pi, sum = 0.0;
      step = 1.0/(num_steps);

      
      double tb = omp_get_wtime();
      
      for(int i=0; i<num_steps; i++){
         x = (i+0.5) * step;
         sum = sum + 4.0/(1.0+x*x);
      }

      double te = omp_get_wtime();
      
      pi = step * sum;

      cout << pi << endl;
      cout << te-tb << endl;
}