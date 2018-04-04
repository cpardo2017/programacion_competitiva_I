#include <stdio.h>
#include <stdlib.h>

int main()
{
    int amplitud,frecuencia,i,a,b;
    int cantidad,d;

    scanf("%d",&cantidad);

    for(d=0;d<cantidad;d++)
    {
        scanf("%d %d",&amplitud,&frecuencia);
        printf("\n");

        for(i=0;i<frecuencia;i++)
        {
            for(a=1;a<amplitud;a++)
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
            }
            printf("\n");
        }
    }

    return 0;
}