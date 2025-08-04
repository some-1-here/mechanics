#include "Trailer.h"
#include <stdio.h>
#include <math.h>

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


void get_masses_driving_force(){
    printf("enter mass of car (m1) \n");
    scanf("%lf", &m1);
    printf("enter mass of trailer (m2) \n");
    scanf("%lf", &m2);
    printf("enter driving force (P) \n");
    scanf("%lf", &driving_force);
}

void calculate_acceleration_tension() {
    a = ( driving_force ) / ( m1 + m2 );
    tension = ( m2 ) * a;
}

void print_acceleration_tension() {
    printf("Tension = %f \nAcceleration = %f \n", tension, a);
}

void which_suvat() {
    printf("which SUVAT variables do you know? (enter 2)\n1) s \n2) u \n3) v \n4) t \n");
    scanf("%d  %d", &choice1, &choice2);
}

int calculate_suvat_depending_on_known_values() {
if ((choice1 == 1 && choice2 == 2) || (choice1 == 2 && choice2 == 1)) {
printf("enter s \n");
scanf("%lf", &s);
printf("enter u \n");
scanf("%lf", &u);
printf("1");
v = sqrt(( u * u) + ( 2 * a * s));
t = ( v - u) / a;
}

else if ((choice1 == 1 && choice2 == 3) || (choice1 == 3 && choice2 == 1)) {
printf("enter s \n");
scanf("%lf", &s);
printf("enter v \n");
scanf("%lf", &v);
printf("2");

u = sqrt((v * v) - 2 * a * s );
t = ( v - u) / a;
}

else if ((choice1 == 1 && choice2 == 4) || (choice1 == 4 && choice2 == 1)) {
printf("enter s \n");
scanf("%lf", &s);
printf("enter t \n");
scanf("%lf", &t);
printf("3");

u = (s - (0.5 * a * (t * t))) / t;
v = u + ( a * t );
}

else if ((choice1 == 2 && choice2 == 3) || (choice1 == 3 && choice2 == 2)) {
printf("enter u \n");
scanf("%lf", &u);
printf("enter v \n");
scanf("%lf", &v);
printf("4");

t = ( v - u) / a;
s = (( u + v ) / 2 ) * t;
}

else if ((choice1 == 2 && choice2 == 4) || (choice1 == 4 && choice2 == 2)) {
printf("enter u \n");
scanf("%lf", &u);
printf("enter t \n");
scanf("%lf", &t);
printf("5\n");

s = (u * t ) + ( 0.5 * a * ( t * t ));
v = u + ( a * t );
}

else if ((choice1 == 3 && choice2 == 4) || (choice1 == 4 && choice2 == 3)) {
printf("enter v \n");
scanf("%lf", &v);
printf("enter t \n");
scanf("%lf", &t);
printf("6\n");

u = v - (a * t);
s = (( u + v ) / 2 ) * t;
}

else {
printf("invalid choice");
return 1;
}
return 0;
}

void print_all_values() {
    printf("\nall results\n");
    printf("---------------\n");
    printf("acceleration=%f \ntension=%f\n", a, tension);
    printf("s=%f \nu=%f \nv=%f \na=%f \nt=%f \n", s, u, v, a, t);
}
