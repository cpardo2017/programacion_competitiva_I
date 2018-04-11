#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,a,b;
    int cantidad,d;

    scanf("%d",&cantidad);

    int datos[cantidad*2];

    for(i=0;i<cantidad*2;i++)
    {
    	scanf("%d",&datos[i]);
    }

    for(d=0;d<cantidad*2;d=d+2)
    {
 
        for(i=0;i<datos[d+1];i++)
        {
            for(a=1;a<datos[d];a++)
            {
                for(b=1;b<=a;b++)
                {
                    printf("%d",a);
                }
                printf("\n");
            }

            for(a=a;a>0;a--)
            {
                for(b=1;b<=a;b++)
                {
                    printf("%d",a);
                }
                printf("\n");

                if(a==1)
                {

                }
          	}
            	printf("\n");

        }   
    }

    return 0;
}