build a static li
	gcc -Wall -c common.c
 gcc -Wall -c bar.c
 gcc -Wall -c foo.c
ar rcs libnumprn.a coomon.o foo.o bar.o


gcc -Wall -L. -DINTERACTIVE="0" app.c -lnumprn
./a.out




gcc -Wall -fPIC -c coomon.c
gcc -Wall -fPIC -c foo.c
gcc -Wall -fPIC -c bar.c
gcc shared -o libnumprn.a coomon.o foo.o bar.o


export LD_LIBRARY_PATH=
gcc -Wall -L. DINTERACTIVE="0" app.c -lnumprn
