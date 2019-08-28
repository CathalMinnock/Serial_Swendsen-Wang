#include "stuff.h"
#include <time.h>

void init() {
	srand(time(NULL));
	int option_index = 0;
	x_size = 8; y_size = 8; z_size = 8; 
	q = 2; beta = 0.4; filename = "apple.txt";
	samples = 1; steps_between_samples = 1;
	while((option_index = getopt(argc, argv, "x:y:z:q:b:s:f:a:" )) != -1) {
		switch(option_index) {
			case 'x':
				x_size = atoi(optarg);
				break;
			case 'y':
				y_size = atoi(optarg);
				break;
			case 'z':
				z_size = atoi(optarg);
				break;
			case 'q':
				q = atoi(optarg);
				break;
			case 'b':
				beta = atof(optarg);
				break;
			case 's':
				samples = atoi(optarg);
				break;
            case 'a':
                steps_between_samples = atoi(optarg);
                break;
			case 'f':
				filename = optarg;
				break;
			default:
				printf("Option incorrect\n");
				exit(1);
		}
	}
	x_values = malloc(q * sizeof(double));
	y_values = malloc(q * sizeof(double));
	for(i=0; i < q; ++i) {
		x_values[i] = sin( (2 * M_PI * i ) / (double) q);
		y_values[i] = cos( (2 * M_PI * i ) / (double) q);
	}
}
int main()
{	
	int i, j;
	FILE *fp1;
	init_lattice();
	randomize_lattice();
	for(i = 0; i < 10 * steps_between_samples; ++i)
		sw_iterate(prob);
	for(i = 0; i < samples; ++i) {
		for(j = 0; j < steps_between_samples; ++j)
			sw_iterate(prob);
		mag = magnetization();
		fprintf(fp1, "%lf\n", mag);
	}
	fclose(fp1);
	free_lattice();
	return 0;
}
