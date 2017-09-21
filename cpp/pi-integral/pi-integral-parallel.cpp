#include <iostream>
#include <omp.h>

using namespace std;



int main(int argc, char *argv[]) {//2 parameters {# of steps, # of threads}

      static long long num_steps = stoll(argv[1]);
      double step;

      double x, pi, sum = 0.0;
      step = 1.0/(num_steps);

      omp_set_dynamic(0);
      omp_set_num_threads(stoi( argv[2] ));
      

      double tb = omp_get_wtime();
      
      #pragma omp parallel
      {
            #pragma omp for reduction(+:sum)
            for(int i=0; i<num_steps; i++){
                  x = (i+0.5) * step;
                  sum += 4.0/(1.0+x*x);
            }
      }


      double te = omp_get_wtime();

      pi = step * sum;

      cout << argv[1] << ", " << argv[2]<< ", " << te-tb << ", " << pi << endl;

}
