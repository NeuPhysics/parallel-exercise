#include <iostream>
#include <omp.h>

using namespace std;

int main(){
   #pragma omp parallel
   {
      int id = omp_get_thread_num();
      A[id] = big_cal1(id);

      #pragma omp barrier

      B[id] = big_calc2(id,A);
   }
}