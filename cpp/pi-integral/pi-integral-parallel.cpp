#include <iostream>
#include <omp.h>
#include <typeinfo>

using namespace std;



int main(int argc, char *argv[]) {//2 parameters {# of steps, # of threads}

      const long num_steps =  1e9; //stoll(argv[1]);
 //     cout << num_steps << endl;


      double x, pi, sum = 0.0;
      constexpr double step = 1.0/(num_steps);

      // omp_set_dynamic(0);
      omp_set_num_threads( stoi( argv[2] ));

      double tb = omp_get_wtime();
      
            #pragma omp parallel for private(x) reduction(+:sum)
            for(int i=0; i<num_steps; i++){
                  x = (i+0.5) * step;
                  sum += 4.0/(1.0+x*x);
                  // sum += 4.0/(1.0+  (i+0.5) * step  * (i+0.5) * step  );
                  // sum += 4.0/(1.0+  i * step  * i * step  );
            }
//          cout << omp_get_num_threads() << endl;


      double te = omp_get_wtime();

      pi = step * sum;

      cout.precision(10);
      cout << argv[1] << ", " << argv[2]<< ", " << te-tb << ", " << pi << endl;

}
