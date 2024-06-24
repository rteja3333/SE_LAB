#include <stdio.h>
#include <stdlib.h>
#include "foo.h"
#include "bar.h"
#include "coomon.h"

int main(){
	int n;
	#ifdef INTERACTIVE
		scanf("%u",&n);
    #else
       n=98756478;
    #endif
	char c='"';
	while(n!=0){
		printf("%u\n",n);
		printf("foo: %c",c);
		fooprn(n);
		printf("%c\n",c);
		printf("bar: %c",c);
		barprn(n);
		printf("%c\n",c);
		printf("\n");
		n=n/10;
	}
	return 0;
}
