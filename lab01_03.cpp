//  Student Name: Rishi Vimalendran
//  Student Number:  20826980
//
//  SYDE 121 Assignment: 01
//  Filename: lab01_03
//
// I hereby declare that this code, submitted for credit for the course//  SYDE121, is a product of my own efforts.  This coded solution has//  not been plagiarized from other sources and has not been knowingly//  plagiarized by others.
//
// Project : Series Summation
// Purpose : To find the sum of any series of integers

/* Test Values: [1, 100], [1, 1000], [5, 10000], [1, 9], [5, 2], [-5, 1]
 
 Valid Range: (lower_integer_bound_c++, upper_integer_bound_c++) for both values, as long as the end value is greater than the start value
 
 Outputs for Part A: [1, 100] = 5050, [1, 1000] = 500500, [5, 10000] = 50004990
 */

#include <iostream>

int main()
{
    // initializing all variables
    int starting_value = 0;
    int ending_value = 0;
    int sum = 0;
    int number_of_integers = 0;
    
    // prompts the user for a starting value and assigns it to the starting_value variable
    std::cout << "Enter a starting value \n";
    std::cin >> starting_value;
    
    // prompts the user for a ending value and assigns it to the ending_value variable
    std::cout << "\nEnter an ending value \n";
    std::cin >> ending_value;
    
    // checks to see that the ending value given is less than the starting value given
    if (ending_value < starting_value)
    {
        std::cout << "Ending value must be greater than starting value";
        return 0;
    }
   
    else
    {
     
        //finds the number of integers in the series
        number_of_integers = (ending_value - starting_value) + 1;
        
        //uses the given formula to calculate the sum (double is used to account for odd numbers)
        sum =  (double(number_of_integers)/2)*(2*starting_value + (number_of_integers - 1));
        
        // outputs the sum
        std::cout << "The sum is " << sum << "\n";
        return 0;

    }
}
