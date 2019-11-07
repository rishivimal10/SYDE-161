//  Student Name: Rishi Vimalendran
//  Student Number:  20826980
//
//  SYDE 121 Assignment: 02
//  Filename: lab02_01
//
// I hereby declare that this code, submitted for credit for the course//  SYDE121, is a product of my own efforts.  This coded solution has//  not been plagiarized from other sources and has not been knowingly//  plagiarized by others.
//
// Project : Prime Numbers
// Purpose : To output prime numbers less than a given value and to check if those prime numbers have odd sums and/or are palindromes

/* Test Values: 30, 12000, 100001, 0, 1, 12, 150000
 
 Valid Range: Integers: [2, 2,147,483,647]
 
 */
#include <iostream>

using namespace std;

int main ()
{
    // initializing variables
    int value = 0;
    bool is_prime_number = true;
    bool has_odd_sum = true;
    
    //asks the user to input a value and assigns it to a variable
    cout << "Enter a value" << "\n";
    cin >> value;
    
    // checks to see that the entered value is greater than 1
    if (value < 2)
    {
        cout << "Value must be greater than 1! Rerun Program! \n";
    }
    
    else
    {
        // Initial for loop allows every integer between [2, value] to be checked
        for (int i = 2; i <= value; i++)
        {
            // re-initialize boolean variables at every instance of the loop
            is_prime_number = true;
            has_odd_sum = true;
            
            // this loop checks to see if the value from the initial for loop is prime by dividing it by every integer less than the value and checking if the mod is 0
            for (int k = 2; k < i ; k++)
            {
                
                if (i % k == 0)
                {
                    is_prime_number = false;
                }
                
            }
            
            if (is_prime_number == true)
            {
                cout << i;
                
                // for every prime number less than 100000, the sum of the digits is checked to see if its odd
                if (i < 100000)
                {
                    //initializing new variables to be used just inside of this if statement
                    int num = i, digit = 0, sum = 0;
                    
                    // the remainder after dividing the prime number by 10 is found, which is the rightmost digit of the number. That digit is then added to the sum. Then the prime number gets divided by 10, which causes it to lose its rightmost digit as the quotient is an integer. The loop is repeated until the prime number becomes 0.
                    while (num > 0)
                    {
                        digit = num % 10;
                        sum += digit;
                        num /= 10;
                    }
                    
                    // if the sum is divisible by 2, then the prime number is not odd
                    if (sum % 2 == 0)
                    {
                        has_odd_sum = false;
                    }
                }
                
                else if (i > 100000)
                {
                    has_odd_sum = false;
                }
                
                // if the prime number is less than 10000 then it is checked to see if the number is a palindrome
                if (i < 10000)
                {
                    // new variables initialized just to be used inside this if statement
                    int reverse_num = 0, digit = 0, num = i;
                    
                    // the prime number gets modded by 10 to get the remainder, which is the leftmost digit. That digit is then added to the reverse number, by multiplying the current reverse number by 10 so that all digits are shifted left. The prime number is then divided by 10 to remove the rightmost digit. The loop is repeated until the prime number becomes 0.
                    while (num > 0)
                    {
                        digit = num % 10;
                        reverse_num = (reverse_num * 10) + digit;
                        num /= 10;
                        
                        // checks to see if the reverse number equals the original prime number. If it does then a message is outputted
                        if (reverse_num == i)
                        {
                            cout << ": This number is a palindrome";
                            
                        }
                    }
                }
                
                // checks to see if the boolean for the odd sum is true. It it is, a message is outputted
                if (has_odd_sum == true)
                {
                    cout << ": The sum of the digits is odd";
                }
                
                
                cout << "\n";
            }
        }
        
    }
    
}


