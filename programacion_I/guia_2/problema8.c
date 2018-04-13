#include <stdio.h>
#include <stdlib.h>

int main()
{
	int det,a,b,c,d;
	int num[4][4];

	printf("ingrese los 16 numeros que compondran la matriz\n");
	for(a=0;a<4;a++)
	{
		for(b=0;b<4;b++)
		{
			scanf("%d",&num[b][a]);
		}
	}

	a=num[1][1]*(num[2][2]*num[3][3]-num[2][3]*num[3][2])-num[1][2]*(num[2][1]*num[3][3]-num[2][3]*num[3][1])+num[1][3]*(num[2][1]*num[3][2]-num[2][2]*num[3][1]);
	b=num[1][0]*(num[2][2]*num[3][3]-num[2][3]*num[3][2])-num[1][2]*(num[2][0]*num[3][3]-num[2][3]*num[3][0])+num[1][3]*(num[2][0]*num[3][2]-num[2][2]*num[3][0]);
	c=num[1][0]*(num[2][1]*num[3][3]-num[2][3]*num[3][1])-num[1][1]*(num[2][0]*num[3][3]-num[2][3]*num[3][0])+num[1][3]*(num[2][0]*num[2][1]-num[3][0]*num[3][1]);
	d=num[1][0]*(num[2][1]*num[3][2]-num[2][2]*num[3][1])-num[1][1]*(num[2][0]*num[3][2]-num[2][2]*num[3][0])+num[1][2]*(num[2][0]*num[3][1]-num[2][1]*num[3][0]);


	det=num[0][0]*a-num[0][1]*b+num[0][2]*c-num[0][3]*d;
	
	printf("el determinante es: %d\n",det);	
	return 0;
}