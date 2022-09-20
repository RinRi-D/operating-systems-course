#include <stdio.h>
#include <stdlib.h>


void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int *result = malloc(sizeof(int));
    *result = *(double*)a + *(int*)b;
    return result;
}

void* addDouble(const void* a, const void* b){
    double *result = malloc(sizeof(double));
    *result = *(double*)a + *(double*)b;
    return result;
}

void* mulInt(const void* a, const void* b){
    int *result = malloc(sizeof(int));
    *result = *(double*)a * *(int*)b;
    return result;
}

void* mulDouble(const void* a, const void* b){
    double *result = malloc(sizeof(double));
    *result = *(double*)a + *(double*)b;
    return result;
}

void* meanInt(const void* a, const void* b){
    double *result = malloc(sizeof(double));
    *result = (*(double*)a + *(int*)b) / 2.0;
    return result;
}

void* meanDouble(const void* a, const void* b){
    double *result = malloc(sizeof(double));
    *result = (*(double*)a + *(double*)b) / 2.0;
    return result;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

	void* output;

	if (size==sizeof(int)){ // base is a pointer to an integer
        if (opr == meanInt) {
            output = malloc(sizeof(double));
            *(double *)output = *(double*)initial_value;
            for (int i = 0; i < n; ++i) {
                double* res = opr(output, ((int*)base) + i);
                *(double*)output = *res;
                free(res);
            }
        } else {
            output = malloc(sizeof(int));
            *(int *)output = *(int*)initial_value;
            for (int i = 0; i < n; ++i) {
                int* res = opr(output, ((int*)base) + i);
                *(int*)output = *res;
                free(res);
            }
        }
	}else{ // base is a pointer to a double
        for (int i = 0; i < n; ++i) {
            double* res = opr(output, ((double*)base) + i);
            *(double*)output = *res;
            free(res);
        }
	}

	return output;
}




int main(){

        int* ints = malloc(sizeof(int)*5);
        double* doubles = malloc(sizeof(double)*5);
        
        double *init_mult = malloc(sizeof(double));
        double *init_add = malloc(sizeof(double));
        double *init_mean_int = malloc(sizeof(double));
        double *init_mean_double = malloc(sizeof(double));
        *init_mult = 1;
        *init_add = 0;
        *init_mean_int = ints[0];
        *init_mean_double = doubles[0];

	// Addition
	
        int* result1a;
        
        result1a = aggregate(ints, sizeof(int), 5, init_add, addInt);
        
        printf("%d\n", *result1a);
        free(result1a);

	    double* result2a;
	
        result1a = aggregate(doubles, sizeof(double), 5, init_add, addDouble);
	
        printf("%f\n", *result2a);
        free(result2a);
                

	// Multiplication
	
        int* result1m;
        
        //<WRITE YOUR CODE HERE>;
        result1m = aggregate(ints, sizeof(int), 5, init_mult, mulInt);
        
        printf("%d\n", *result1m);
        free(result1m);

        double* result2m;
	    
        result2m = aggregate(doubles, sizeof(double), 5, init_mult, mulDouble);
        printf("%f\n", *result2m);
        free(result2m);
        
        
	// Mean
	
        double* result1mean;

        result1mean = aggregate(ints, sizeof(int), 5, init_mean_int, meanInt);
    
        printf("%lf\n", *result1mean);
        free(result1mean);

        double* result2mean;
	
        result2mean = aggregate(doubles, sizeof(double), 5, init_mean_double, meanDouble);
	
        printf("%f\n", *result2mean);
        free(result2mean);
	
        
        // free the pointers
        //<WRITE YOUR CODE HERE>;
        free(ints);
        free(doubles);
        free(init_add);
        free(init_mult);
        free(init_mean_double);
        free(init_mean_int);


        return EXIT_SUCCESS;
}