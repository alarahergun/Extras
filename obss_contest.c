#include <stdio.h>
#include <stdlib.h>

int solution(int **A, int N, int M)
{
bool set[N][M];
int B[10];
int max = 0, max_2 = 0, sum = 0, sum_old = 0;
int a, b, c, d;
int i, j, k;

for(i=0; i<N; i++)
{
for(j=0; j<M; j++)
{
if(A[i][j] > max)
{
max = A[i][j];
}
}
}

for(i=0; i<N; i++)
{
for(j=0; j<M; j++)
{
if(max == A[i][j])
{
A[i+1][j] = B[0];
A[i-1][j] = B[1];
A[i][j+1] = B[2];
A[i][j-1] = B[3];

set[i][j] = false;

for(k=0; k<4; k++)
{
if(B[k] > max_2)
{
max_2 = B[k];
}
}

sum = max + max_2;
goto label;
}
}
}

label:

for(a=0; a<3; a++)
{
switch(max_2){
case B[0] :
i = i+1;
break;
case B[1] :
i = i-1;
break;
case B[2] :
j = j+1;
break;
case B[3] :
j = j-1;
break;
}

A[i+1][j] = B[0];
A[i-1][j] = B[1];
A[i][j+1] = B[2];
A[i][j-1] = B[3];

for(k=0; k<4; k++)
{
if(B[k] > max_2)
{
max_2 = B[k];
}
}

sum = max + max_2;
temp = sum;
}



for(i=0; i<N; i++)
{
for(j=0; j<M; j++)
{
if(max == A[i][j] && set[i][j] != false)
{
A[i+1][j] = B[0];
A[i-1][j] = B[1];
A[i][j+1] = B[2];
A[i][j-1] = B[3];

set[i][j] = false;

for(k=0; k<4; k++)
{
if(B[k] > max_2)
{
max_2 = B[k];
}
}

sum = max_2 + max;
goto label;
}

}
}






 return max(sum, sum_old);
}


