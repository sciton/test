#include <stdio.h>
#include <stdlib.h>
//#include "solving.h"
#include <stdbool.h>
//#include "rendering.h"

#define h 0.5f

typedef float val;

void InitVal( int *N, val *x, val *y )
{
  val
    top = 10.0,
    bottom = -10.0,
    leftbound = -1.0,
    rightbound = 1.0,
    radius = 0.25,
    *xline,
    *yline;

  int nx = 5;
  int ny = 10;
  int i,j;

  xline = malloc(nx*sizeof(val));
  yline = malloc(ny*sizeof(val));
  
  for (i = 0; i<nx; i++)
    xline[i] = leftbound + i*(rightbound-leftbound)/(nx-1);
  
  for (i = 0; i<ny; i++)
    yline[i] = bottom + i*(top-bottom)/(ny-1);

  x = malloc(sizeof(val));
  y = malloc(sizeof(val));
  int k = 1;
  for (i = 0; i<nx; i++)
    for (j = 0; j<ny; j++)
      if (xline[i]*xline[i]+yline[j]*yline[j] > radius*radius)
        {
          x = realloc(x,k*sizeof(val));
          y = realloc(y,k*sizeof(val));
          x[k] = xline[i];
          y[k] = yline[j];
          
          printf("%i    %f    %f  \n ",k,x[k],y[k]);
          k += 1;
        }

  
 *N = k-1;
  
}

int main(void){

  val
    *x,
    *y,
    *Vx,
    *Vy;
    
  int N,i;
  bool flag = true;
  InitVal(&N,x,y);
  
    
  return 0;
}
