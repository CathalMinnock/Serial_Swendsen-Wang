#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int x_size, y_size, z_size;
int q;
char *filename;
int samples, steps_between samples;

/* LINKED LIST STUFF */
typedef struct list_node {
	char spin;
	int label;
	struct list_node *next;
} list_node;

list_node* create_node(int label);
int search_list(list_node* head, int label);
void free_list();

/* LATTICE STUFF */
typedef struct point {
	char spin;
	int label;
	bool bond_x;
	bool bond_y;
	bool bond_z;
} point;

point ***lattice;
void init_lattice();
void randomize_lattice();
void reset_lattice();
void print_lattice(point ***lattice);
void print_lattice_labels(point ***lattice);
void free_lattice();

/* ITERATIONS, OBSERVABLES */
double beta, prob;
double *x_values, *y_values;
double mag;
double magnetization();
double magnetization_max();
void sw_iterate(double prob);

