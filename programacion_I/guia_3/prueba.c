#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 	int i,n,k,j,mayor,aux;

 	mayor=0;

 	scanf("%d",&n);

 	int numeros[n];

 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&numeros[i]);
 		if(mayor<numeros[i])
 		{
 			mayor=numeros[i];
 		}
 	} 

 	char secuencia[mayor];

 	for(i=0,j=0,k=0;i<mayor;i++)
 	{
 		if(i==j)
 		{
 			secuencia[i]='1';
 			k++;
 			j=j+k;
 		}

 		else
 		{
 			secuencia[i]='0';
 		}
 	}

 	for(i=0;i<n;i++)
 	{
 		aux=numeros[i];
 		printf("%c",secuencia[aux-1]);

 		if(i<n-1)
 		{
 			printf(" ");
 		}

 	}

 	printf("\n");

   return 0;
}