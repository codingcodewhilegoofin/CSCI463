

// Include STL libraries  
#include <iostream>
#include <iomanip>
#include <cstdint>


/**
 * 	Convert a 32 bit signed integer to binary, then format. 
 *
 * 	The function will take a 32 bit signed integer as a parameter and then create a bitmask for each necessary 
 * 	step. The conditional if statments will decide if we have a negative or positive hexidecimal value to 
 * 	convert. Then with the correct formatting it will print sign, exp , and sig figures in hex. 
 * 	It will then also check if our exponent is positive or negitive. Once it has logically sorted 
 * 	which sign it needs to print it will iterate through our bitmask to print the corrent IEEE -754 Floating
 * 	point conversion of our original integer. 
 *
 * 	@param x Is our 32 bit integer passed from main()
 *
 * 	@return this function is void and returns nothing
 *
 * 	@note this function should take positive and negative integers as well as hexideciamal or decimal 
 * 	      input from the user. 
 *
 * 	@warning may not recgonize an input in decimal vs binary ( accepts both )
 *
 * 	@bug Seems to be an off by 1 error/ a few differences especially for negitive exponent values   
 *
 * 	          
 **/
void printBinFloat(uint32_t x)
{

	// Variables
	uint32_t originalValue = 0x80000000; // To obtain the original hex value in binary we use a bitmask to convert 				   
	bool sign = x & 0x80000000;
	int32_t exp = ((x & 0x7f800000) >> 23) - 127; // In order to get our exponent we must subtract -127 and shift right
	uint32_t sig = x & 0x007fffff; // We only want the significand here so we use a bitmask to extract it 
	int32_t temp = 0x00400000; // Will hold a temporary bitmask for iteration

	std::cout << "0x" << std::setfill('0') << std::hex << std::setw(8) << x << " =";///Format our hex -> binary comparison

	// Iterate through our first bitmask in order to print the full 32 bit representation in binary of the inputed value.  
	for (size_t i = 0; i < 32; ++i)
	{
		// Then modulo in order to seperate it into 4 bit chunks 
		if (i%4==0)
		{
			std::cout << " ";
		}

		// We need to print 1 if the condition holds true, otherwise print 0 
		std::cout << (x & originalValue ? '1' : '0');

		// Use of shift bitwise operator to shift 1 bit after each space is added 
		originalValue = (originalValue >> 1);

	}

	
	std::cout << std::endl;
	
	// Formating the output to exact specifications , using conversions from hex to decimal
	std::cout << "sign: " << sign << std::endl;
	std::cout << " exp: 0x" << std::setfill('0') << std::setw(8) << std::hex << exp << std::dec << " (" << exp << ")" << std::endl;
	std::cout << " sig: 0x" << std::setfill('0') << std::setw(8) << std::hex << sig << std::endl;

	
	if (( exp == 0x00000080 ) && (sign == 0 ) )// Check if it is positive infinity 
	{
		std::cout << "+" << "inf" ;
	}
	else if ((exp == 0x00000080) && (sign == 1))// Check if it is negative infinity 
	{
		std::cout << "-" << "inf" ;
	}
	else
	{
		
		if ((uint32_t(exp) == 0xffffff81) && (sign == 0))// Check if our number is 0 or not
		{
			std::cout << "+" << "0";
		}
		else if ((uint32_t(exp) == 0xffffff81) && (sign == 1))// Check if our number is -0 or not
		{
			std::cout << "-" << "0";
		}
		else
		{
			// Check for signed bit if its neg 
			if (sign == true)
			{
				// Check if exponent is pos 
				if (exp > 0)
				{
					std::cout << "-" << "1";

					
					// We iterate through our bitmask with a temporary value to get our floating point representation 
					for (int i = 0; i < 23; ++i)
					{
						std::cout << (sig & temp ? '1' : '0');// Evaluate for bitmask where we should place our 1 or 0

						
						temp = (temp >> 1); // Shift our bit to the right by 1
					}


					//Now we iterate for the exact ammount of times we need to print 0 to represent the exponent
					for (int i = 0; i < (exp-23); ++i)
					{
						std::cout << "0";
					}

					std::cout << ".0";
				}
				// Check if exp is neg 
				else if (exp < 0)
				{

					int32_t expcounter = ((exp + 1) * -1);// If exponent is negative we need the absolute value of this

					std::cout << "-";
					std::cout << "0.";

					for (int i = 0; i < (expcounter); ++i)
					{
						std::cout << "0";
					}

					
					std::cout << "1"; // We need an extra 1 

					for (int i = 0; i < 23; ++i)
					{
						std::cout << (sig & temp ? '1' : '0');

						//When we shift the bit we need to go left now instead of right
						temp = (temp << 1);
					}

				}
				// Check if exp is 0 
				else if ( exp == 0)
				{
					std::cout << "-" << "1.";

					int32_t expcounter = exp;

					for (int i = 0; i < 23; ++i)
					{
						std::cout << (sig & temp ? '1' : '0');

						temp = (temp >> 1);
					}

					for (int i = 0; i < expcounter; ++i)
					{
						std::cout << "0";
					}

				}
				// Check if exp is undefined
				else
				{
					std::cout << "Error: exponent was not a number";
				}
			}
			// Check for signed bit if its pos 
			else if ( sign == false)
			{
				// Check if exponent is pos 
				if (exp > 0)
				{
					std::cout << "+1";

					for (int i = 0; i < 23; ++i)
					{
						std::cout << (sig & temp ? '1' : '0');

						temp = (temp >> 1);
					}

					for (int i = 0; i < (exp-23); ++i)
					{
						std::cout << "0";
					}

					std::cout << ".0";
				}
				// Check if exp is neg 
				else if (exp < 0)
				{
					
					int32_t expcounter = ((exp + 1) * -1);

					std::cout << "+";
					std::cout << "0.";

					for (int i = 0; i < (expcounter); ++i)
					{
						std::cout << "0";
					}

					std::cout << "1";

					for (int i = 0; i < 23; ++i)
					{
						std::cout << (sig & temp ? '1' : '0');

						temp = (temp << 1);
					}

				}
				// Check if exp 0 
				else if (exp == 0)
				{
					std::cout << "+" << "1.";

					int expcounter = exp;

					for (int i = 0; i < 23; ++i)
					{
						std::cout << (sig & temp ? '1' : '0');

						temp = (temp >> 1);
					}

					for (int i = 0; i < expcounter; ++i)
					{
						std::cout << "0";
					}

				}
				// Check if exp is undefined  
				else
				{
					std::cout << "Error: exponent was not a number";
				}

			}
			else
			{
				std::cout << "Error: Signed bit was not 0 or 1";
			}

		}

	}

}

/**
 *	Very simple main function to convert 
 *
 *	The main function will take input from the user as a 32 bit 
 *	unsinged integer. Then it loops and passes this value in 
 *	hexidecimal to our printBinFloat() function untill it 
 *	recgonizes an invalid input. 
 *
 *	@param none 
 *
 *	@note none 
 *
 *	@warning could use more input verification 
 *
 *	@bug no known bugs at this time 
 *
 *
 */
int main()
{
	// Input 
	uint32_t x = 0x3d200000;

	// Conditional loop that will continuously read a unsigned integer from the user
	// and convert it to hexidecimal, then passed to the printBinFloat() function
	while( std::cin >> std::hex >> x )
	{
		// Pass our variable(s) to be printed 
		printBinFloat(x);

		std::cout << std::endl;
	
	}

 	return 0;
 }
