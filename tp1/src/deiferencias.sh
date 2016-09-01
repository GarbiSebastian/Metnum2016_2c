path="../Test_Ale/test_egvlu1i"
#../Test_Ale/test_egvlu1i/radios-100_angulos-10.in
for i in `seq 10 5 105`; do  ./tp "$path/radios-$i-angulos-10.in" algo.out 1; done;
for i in `seq 10 5 105`; do  ./tp "$path/radios-$i-angulos-10.in" algo.out 0; done;
