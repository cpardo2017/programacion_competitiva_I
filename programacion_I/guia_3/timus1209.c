#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    scanf("%d",&N);
    
    long long K;
    
    while(N--){
        scanf("%lld",&K);
        long long D = (long long)8*K-7;
        long long lo = 1,hi = D,mi;
        
        while(lo!=hi){
            mi = (lo+hi+1)/2;
            
            if(mi>D/mi) hi = mi-1;
            else lo = mi;
        }
        
        if(lo*lo==D && (lo & 1)==1) printf("1");
        else printf("0");
        printf(" ");
    }
    
   printf("\n");
    
    return 0;
}

