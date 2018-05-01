#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int w, h;

void WriteBMP (char *pixels)
{
	int bmi[] = { w * h * 3 + 54, 0, 54, 40, w, h, 1 | 24 << 16, 0, 0, 0, 0, 0, 0 };
	FILE *bmp = fopen ("graph.bmp", "w");
	fprintf (bmp, "BM");
	fwrite (bmi, 52, 1, bmp);
	fwrite (pixels, 1, w * h * 3, bmp);
	fclose (bmp);
}

void svbmp (double x[], double y[])
{
	char pixels[w * h * 3];

	int i;
	/* 绘制基底 */
	int z;
	for (i = 0; i < w * h * 3;)
	{
		pixels[i] = 255;
		++i;
	}
	for (i = 0; i < w * h * 3;)
	{
		pixels[i] = 230;
		++i;
		pixels[i] = 230;
		++i;
		pixels[i] = 230;
		i = i + 10 * 3 - 2;
	}
	for (i = 0; i < w * h * 3; i++)
	{
		if (i % (10 * w * 3) == 0)
		{
			for (z = i; z < i + w * 3;)
			{
				pixels[z] = 230;
				++z;
				pixels[z] = 230;
				++z;
				pixels[z] = 230;
				++z;
			}
		}
	}
	for (i = 0; i < w * h * 3;)
	{
		pixels[i] = 100;
		++i;
		pixels[i] = 100;
		++i;
		pixels[i] = 100;
		i = i + 100 * 3 - 2;
	}
	for (i = 0; i < w * h * 3; i++)
	{
		if (i % (100 * w * 3) == 0)
		{
			for (z = i; z < i + w * 3;)
			{
				pixels[z] = 100;
				++z;
				pixels[z] = 100;
				++z;
				pixels[z] = 100;
				++z;
			}
		}
	}

	/* 绘制点 */
	/* 自定颜色 */
	int t = 0;
	for (i = 0; i < w * h * 3; i++)
	{
		if (i == (int) ((int) (y[t] * 1000) * w * 3 + x[t] * 1000 * 3))
		{
			z = i;
			/* blue */
			pixels[z + 0] = 0;
			/* green */
			pixels[z + 1] = 0;
			/* red */
			pixels[z + 2] = 255;
			++t;
		}
	}
	WriteBMP (pixels);
}
