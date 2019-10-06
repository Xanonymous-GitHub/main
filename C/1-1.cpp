#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main(void)
{
	const float pi = acos(-1.0);
	float r, h, s1, s2, s;
	scanf("%1f%1f", &r, &h);
	s1 = pi * r * r;
	s2 = 2 * pi * r * h;
	s = s1 * 2.0 + s2;
	printf("Area = %.3f\n", s);
	return 0;
}
