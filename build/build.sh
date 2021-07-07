cmake ..
make clean
make
cp Makefile ../
cp src/Makefile ../src/Makefile
cp stressTest/Makefile ../stressTest/Makefile
cp ../base/public.h ../src/public.h
cp ../base/public.h ../stressTest/public.h