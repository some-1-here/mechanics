#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double m1;
double m2;
double driving_force;
double tension;

// F=ma
double force;
double mass;

// SUVAT
double s = 0;
double u = 0;
double v = 0;
double a = 0;
double t = 0;

int choice1;
int choice2;

int main() {

printf("enter mass of car (m1) \n");
scanf("%lf", &m1);
printf("enter mass of trailer (m2) \n");
scanf("%lf", &m2);
printf("enter driving force (P) \n");
scanf("%lf", &driving_force); // corrected ¬

// fricitonless
// F = M * A -> A = F / M

a = ( driving_force ) / ( m1 + m2 );

// m2
// +T = m * a
tension = ( m2 ) * a;

printf("Tension = %f \nAcceleration = %f \n", tension, a);

printf("which SUVAT variables do you know? (enter 2)\n1) s \n2) u \n3) v \n4) t \n");
scanf("%d  %d", &choice1, &choice2);

if (choice1 == 1 && choice2 == 2 || choice1 == 2 && choice2 == 1) {
printf("enter s \n");
scanf("%lf", &s);
printf("enter u \n");
scanf("%lf", &u);
printf("1");
// calculations
v = sqrt(( u * u) + ( 2 * a * s));
t = ( v - u) / a;
}

else if (choice1 == 1 && choice2 == 3 || choice1 == 3 && choice2 == 1) {
printf("enter s \n");
scanf("%lf", &s);
printf("enter v \n");
scanf("%lf", &v);
printf("2");

u = sqrt((v * v) - 2 * a * s );
t = ( v - u) / a;
}

else if (choice1 == 1 && choice2 == 4 || choice1 == 4 && choice2 == 1) {
printf("enter s \n");
scanf("%lf", &s);
printf("enter t \n");
scanf("%lf", &t);
printf("3");

u = (s - (0.5 * a * (t * t))) / t;
v = u + ( a * t );
}

else if (choice1 == 2 && choice2 == 3 || choice1 == 3 && choice2 == 2) {
printf("enter u \n");
scanf("%lf", &u);
printf("enter v \n");
scanf("%lf", &v);
printf("4");

t = ( v - u) / a;
s = (( u + v ) / 2 ) * t;
}

else if (choice1 == 2 && choice2 == 4 || choice1 == 4 && choice2 == 2) {
printf("enter u \n");
scanf("%lf", &u);
printf("enter t \n");
scanf("%lf", &t);
printf("5\n");

s = (u * t ) + ( 0.5 * a * ( t * t ));
v = u + ( a * t );
}

else if (choice1 == 3 && choice2 == 4 || choice1 == 4 && choice2 == 3) {
printf("enter v \n");
scanf("%lf", &v);
printf("enter t \n");
scanf("%lf", &t);
printf("6\n");

u = v - (a * t);
s = (( u + v ) / 2 ) * t;
}

printf("s=%f \nu=%f \nv=%f \na=%f \nt=%f \n", s, u, v, a, t);

return 0;

}
/* SUVAT
S = ?
U = ?
V = ?
T = ?




//	v = sqrt(( u * u) + ( 2 * a * s));
  //      t = ( v - u) / a;
//	s = (u * t ) + ( 0.5 * a * ( t * t ));
//	v = u + ( a * t );
///	s = (( u + v ) / 2 ) * t;
//	u = sqrt((v * v) - 2 * a * s )
//	u = (s - (0.5 * a * (t * t)) / t
//	u = v - (a * t);
*/
