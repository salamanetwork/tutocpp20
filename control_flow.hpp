#ifndef __CONTROL_FLOW_H
#define __CONTROL_FLOW_H

#include <iostream>
#include <iomanip>
#include <ios>

#include <bitset>

/*
    - Short Circuit Evaluation:
        - (&&) == (AND) :
            - If one of the operands is 'false':
                - The result is 'FALSE'.
                - Put operands likely to be 'false' first.
        - (||) == (OR) :
            - If one of the operands is 'true':
                - The result is 'TRUE'.
                - Put operands likely to be 'true' first.
*/

void short_circuit_evaluation()
{
    bool
		a = true,
		b = true,
		c = true,
		d = false;

	bool
		v = false,
		x = false,
		y = false,
		z = true;

	bool result;

	std::cout << std::boolalpha;
	
	// AND : if one of the operands 'false', the result is false
	std::cout << "AND SHORT CIRCUIT: " << std::endl;
	result = a && b && c && d;	// result => false, because (d) is false
	std::cout << "result: " << result << std::endl;

	// OR : if one of the operands 'true', the result is true
	std::cout << "OR SHORT CIRCUIT: " << std::endl;
	result = v || x || y || z;	// result => true, because (z) is true
	std::cout << "result: " << result << std::endl;

	
}


/*
	- Itegral Logic Conditions
 		- (0) is always false.
   		- (1) is always true.
	 	- (Any number positive or negative except zero) will be alwys true.
   			- ex:
	  			-2 = true
	  			-9 = true
	  			 0 = false
	  			 1 = true
	   			15 = true
	   
*/
void itegral_logic_conditions()
{
	// int condition { 0 };			// Represents FALSE anyway.
	int condition { -10 };			// Represents TRUE anyway.

	std::cout << std::boolalpha;

	if(condition)
	{
		std::cout 
			<< "The Condition is: "
			<< static_cast<bool>(condition)	// using explicit type conversion
			<< std::endl
			<< "The Condition is TRUE and has a value of: " 
			<< condition
			<< std::endl;
	}
	else
	{
		std::cout 
			<< "The Condition is: "
			<< static_cast<bool>(condition)	// using explicit type conversion
			<< std::endl
			<< "The Condition is FALSE and has a value of: " 
			<< condition
			<< std::endl;
	}
	
}

/*
	- Ternary Operators:
 		- result = (eval_expr) ?  if_true_do : else_do;
   - Ternary Initialization:
   		- var { (eval_expr) ?  if_true_do : else_do };
*/

void ternary_ops()
{
	unsigned int a { 65 }, b { 71 }, result;

	result = (a > b) ? a : b;

	std::cout
		<< "a value is: "
		<< a
		<< std::endl
		<< "b value is: "
		<< b
		<< std::endl
		<< "a > b result is: "
		<< (
				(a > b) ? 
				"The value of a is greater than b." : 
				"The value of b is greater than a."
			)
		<< std::endl
		<< std::setw(20)
		<< "The result is: "
		<< result
		<< std::endl;
		
}

void ternary_init()
{
	int normal_speed	= 100;		// On normal speed
	int fast_speed 		= 200;		// On fast speed
	bool accelerate 	= true;		// Modifying the speed

	// Using ternary initialization
	int speed { (accelerate) ? fast_speed : normal_speed };

	std::cout 
		<< "Speed is: " 
		<< speed
		<< ( (accelerate) ? " on fast speed" : " on normal speed" )
		<< std::endl;
	
}


/*
	- if constexpr
 		- Do conditional at compile-time.
   		- The evaluated expression should be fully evaluated at compile-time:
	 		- const bool condition { true };
			- constexpr bool condition { true };
   
*/

void if_constexpr()
{
	const bool condition { false };
	// const bool condition { true };
	
	std::cout << std::boolalpha;
	
	if constexpr (condition)
	{
		std::cout
			<< "if constexpr evaluated as: "
			<< condition
			<< std::endl;
	}
	else
	{
		std::cout
			<< "if constexpr evaluated as: "
			<< condition
			<< std::endl;
	}
}







#endif









