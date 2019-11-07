//  Student Name: Rishi Vimalendran
//  Student Number:  20826980
//
//  SYDE 121 Assignment: 04
//  Filename: lab04_02
//
// I hereby declare that this code, submitted for credit for the course//  SYDE121, is a product of my own efforts.  This coded solution has//  not been plagiarized from other sources and has not been knowingly//  plagiarized by others.
//
// Project : Basic Data Analysis
// Purpose : Allows user to input data and outputs stats on the data such as mean, standard deviation, min, and max
/*
 I ran the program multiple times to see if there were any issues present in my code. There was an issue with the stats being affected by the uninitialized "0" values in the array and so I fixed that with a counter that counts the number of inputs.
 */

#include <iostream>
#include <math.h>
using namespace std;

void initialize_array (double array [], int array_elements, int& input_counter);
//INPUT: an array, and the max number of elements, allows user to enter values for array one by one
//PROCESSING: Checks to see if the user is done inputting values, and only adds the first 20 inputted double values to the array

void output_stats (double array [], int input_counter);
//INPUT: The array and the number of values inputted by the user
//PROCESSING: calculates the mean, the min value, the max value, population standard deviation of all the values in the array up until the number of inputs by the user
//OUTPUT: Outputs the mean, the min value, the max value, and population standard deviation

void array_editor (double array [], int input_counter);
//INPUT: The array and the number of values inputted by the user. Allows the user to input a location in the array, up to the number of initial inputs, and then input a new value for that location
//PROCESSING: Checks to see if the inputted location is less than the number of initial inputs, and then changes the value of the location to the new value inputted by the user

int main()
{
    const int MAX_ARRAY = 20;
    double number_array [MAX_ARRAY];
    int input_counter = 0;
    
    initialize_array(number_array, MAX_ARRAY, input_counter);
    output_stats(number_array, input_counter);
    array_editor(number_array, input_counter);
}

void initialize_array (double array [], int array_elements, int& input_counter)
{
    string input;
    bool is_done = false;
    double num_input = 0;
    
    cout << "Enter Values (enter 'd' or 'done' to stop): \n";
    
    while (is_done == false)
    {
        cin >> input;
        if (input == "d" || input == "done")
        {
            is_done = true;
        }
        else
        {
            num_input = stod (input);
            if (input_counter < array_elements)
            {
                array [input_counter] = num_input;
                input_counter += 1;
            }
        }
    }
}

void output_stats (double array [], int input_counter)
{
    double array_min = array [0], array_max = array [0];
    double sum = 0;
    double mean;
    double standard_deviation;
    double sum_of_deviations = 0;
    
    for (int i = 0; i < input_counter; i++)
    {
        sum += array [i];
        
        if (array_min > array [i])
        {
            array_min = array[i];
        }
        
        if (array_max < array [i])
        {
            array_max = array [i];
        }
    }
    mean = sum / input_counter;
    
    for (int i = 0; i < input_counter; i++)
    {
        sum_of_deviations += pow (array[i] - mean, 2);
    }
    
    standard_deviation = sqrt (sum_of_deviations/input_counter);
    
    cout << "\nThe Maximum Value: " << array_max << endl;
    cout << "The Minimum Value: " << array_min << endl;
    cout << "The Mean of the Valyes: " << mean << endl;
    cout << "The Standard Deviation of the Values: " << standard_deviation << endl;
}

void array_editor (double array [], int input_counter)
{
    bool is_done = false;
    string input;
    int location_input;
    double value_input;
    
    
    while (is_done == false)
    {
        cout << "\nEnter the location of the value (enter 'q' or 'quit' to quit): ";
        cin >> input;
        
        if (input == "q" || input == "quit")
        {
            is_done = true;
        }
        
        else
        {
            location_input = stod (input);
            
            if (location_input > input_counter)
            {
                cout << "\nThat location is invalid";
            }
            
            else
            {
                cout << "\nEnter the new value: ";
                cin >> value_input;
                
                array [location_input] = value_input;
                output_stats(array, input_counter);
            }
            
        }
        
    }
}
