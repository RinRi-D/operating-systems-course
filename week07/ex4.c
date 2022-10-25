#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Assuming that previous size is provided, since there is no standard way to know the size of the allocated block
void* myrealloc(void* ptr, size_t prev_size, size_t new_size) {
    if (ptr == NULL) prev_size = 0;

    char *res = malloc(new_size);
    size_t copy_size = (prev_size < new_size ? prev_size : new_size);

    for (size_t i = 0; i < copy_size; ++i) {
        res[i] = ((char*) ptr)[i];
    }

    free(ptr);

    return res;
}

// Copied and fixed the code from goo.gl/EMpzYz
// test myrealloc using ex3
int main() {
	//Allows you to generate random number
	srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%d",&n1);

	//Create a new array of n1 ints
	int* a1 = malloc(sizeof(int) * n1);
	int i;
	for(i=0; i<n1; i++){
		//Set each value in a1 to 100
		a1[i]=100;
		
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	//Dynamically change the array to size n2
	a1 = myrealloc(a1, sizeof(int) * n1, sizeof(int) * n2);

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    for (int i = n1; i < n2; ++i) {
        a1[i] = 0;
    }
	

	for(i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
    free(a1);
	
	return 0;
}
