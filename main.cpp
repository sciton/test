#include <stdio.h>
#include <stdlib.h>
//#include "solving.h"
#include <stdbool.h>
//#include "rendering.h"

#define h 0.1f

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

  int nx = (int)((rightbound-leftbound)/h);
  int ny = (int)((top-bottom)/h);
  int i,j;

  xline = malloc(nx*sizeof(val));
  yline = malloc(ny*sizeof(val));
  
  for (i = 0; i<nx; i++)
    xline[i] = leftbound + i*(rightbound-leftbound)/(nx-1);
  
  for (i = 0; i<ny; i++)
    yline[i] = bottom + i*(top-bottom)/(ny-1);

  int k = 1;
  for (i = 0; i<nx; i++)
    for (j = 0; j<ny; j++)
      if (xline[i]*xline[i]+yline[j]*yline[j] > radius*radius)
        {
          x = realloc(x,k*sizeof(val));
          y = realloc(y,k*sizeof(val));
          x[j+ny*i] = xline[i];
          y[j+ny*i] = yline[j];
          k += 1;
        }

  N = k-1;
}

int main(void){

  val
    *x,
    *y,
    *Vx,
    *Vy;
    
  int N;
  bool flag = true;
  InitVal(&N,x,y);

    
  return 0;
}
