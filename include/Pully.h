#ifndef PULLY_H
#define PULLY_H

extern double m1;
extern double m2;
extern double g;

extern double force;
extern double s;
extern int u;
extern double v;
extern double a;
extern double t;
extern double tension;

extern int choice;

void get_masses();
void calculate_accelartion_tension(double m1, double m2);
void get_suvat();
int calculate_suvat();
void print_everything();

#endif
