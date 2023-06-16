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










#endif









