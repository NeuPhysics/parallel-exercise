echo "STEPS, OMPThread, Time" > halo_sim_parallel_benchmark.record;

for STEPS in 1000000 10000000 100000000 1000000000 10000000000
do
    for OMPTH in 1 2 3 4 5 6 7 8 9 10 11
    do
        echo "$STEPS, $OMPTH"
        nohup ./pi-integral-parallel.o $STEPS $OMPTH >> pi-integral-parallel.record;
   done
done
