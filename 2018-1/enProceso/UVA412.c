#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num_fila,i,j,contador,factor,verificador;
    float pi;
    scanf("%d",&num_fila);
    while(num_fila>0)
    {
        int pares=0;
        int numeros[num_fila];
        for(i=1;i<=num_fila;i++)
        {
            scanf("%d",&numeros[i]);
        }

        for(i=1;i<=num_fila;i++)
        {
            for(j=i+1;j<=num_fila;j++)
            {
                verificador=1;
                pares++;
                for(factor=2;factor<=numeros[i];factor++)
                {
                    if(numeros[i]%factor==0 && numeros[j]%factor==0)
                    {
                        verificador=0;
                        break;
                    }
                }
                if(verificador==1){contador++;}
            }
        }
        pi=sqrt(6*pares/contador);
        printf("el valor de pi es %f",pi);
    }
  return 0;
}