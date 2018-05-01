#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void svbmp (double x[], double y[]);

int w, h;

double expression (double x)
{
	double y;
	y = pow (x, 2);
	return y;
}

void main ()
{
	w = 1000, h = 1000;
	//scanf("%d %d", w, h)
	double x[w];
	double y[h];
	int i;
	for (i = 0; i < w; i++)
	{
		x[i] = i * 0.001;
		y[i] = expression (x[i]);
	}
	svbmp (x, y);
}
