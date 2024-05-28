/*

    This program serves to help drive the development of the clock heatmap software.
        1 - Given a sample of the number of users per hour for the last day, first normalize the data.
        2 - To normalize, divide all values by the maximum value.
        3 - Convert normalized data to analog values.
        4 - Write the analog values to the corresponding channels on the mux.

*/

#include <stdio.h>

/*

    To compile the code to an executable file, type this into the command prompt:
        gcc -o "Name of Exec File" filename.c
    Then, to run the compiled program:
        ./name_of_exec_file

*/

float sample_data[12] = {
    10,
    10,
    3,
    2,
    1,
    20,
    20,
    35,
    35,
    50,
    55,
    55
};

float largest(float arr[], int n)
{
    int i;
    
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements from second and
    // compare every element with current max 
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

//This function normalizes the traffic data for each hour and converts to analog output (0 to 255)
float weights(int hour){
    printf("%0.0f\t",largest(sample_data, 12));
    float weight = (sample_data[hour]/largest(sample_data, 12));
    weight = 255*weight;
    return weight;
}

int main(){

    float analogVals[12];

    for(int i = 0; i < 12; i++){
        analogVals[i] = weights(i);
        printf("%0.0f\t",sample_data[i]);
        printf("Channel %d is set at %0.0f\n",i,analogVals[i]);
    };

    
}