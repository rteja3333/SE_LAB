#include <stdio.h>
#include <stdlib.h>

void cmnprn(unsigned int n){
        char num[10][10]={"","one","two","three","four","five","six","seven","eight","nine"};
        char tens[10][10]={"","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninty"};
        char tensten[10][10]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","ninteen"};
        if(n>999) {
                printf("big\n");
                return;
        }
        else {
                int a=100;
                while(n!=0){
                        if((n/a!=0)&&(a==100)){
                                printf(" %s hundred",num[n/a]);
                        }
                        if(a==10){
                                if(n/10==1){
                                printf(" %s",tensten[n%10]);
                                }
                                else printf(" %s",tens[n/a]);
                                n=n-a*(n/a);
                                a=a/10;
                                if((n/a!=0)&&(a==1)){
                                printf(" %s",num[n/a]);
                                }
                        }
                        n=n-a*(n/a);
                        a=a/10;
                }
        }
        return ;
        }

			
			
			
				



