/* triangle.c -- Joseph Petitti */

#include <stdio.h>
#include <math.h>

int main(void) {
	double x1, y1, x2, y2, x3, y3;
	printf("Enter the x- and y-coordinates of point A: ");
	scanf("%lf %lf", &x1, &y1);
	printf("Enter the x- and y-coordinates of point B: ");
	scanf("%lf %lf", &x2, &y2);
	printf("Enter the x- and y-coordinates of point C: ");
	scanf("%lf %lf", &x3, &y3);
	
	double ab = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	double bc = sqrt(pow((x2 - x3), 2) + pow((y2 - y3), 2));
	double ca = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
	printf("Length of AB is %.3lf\n", ab);
	printf("Length of BC is %.3lf\n", bc);
	printf("Length of CA is %.3lf\n", ca);
	printf("Circumference is %.3lf\n", ab + bc + ca);

	double s = .5 * (ab + bc + ca);
	double area = sqrt(s * (s - ab) * (s - bc) * (s - ca));
	printf("Area is %.3lf\n", area);

	return 0;
}
