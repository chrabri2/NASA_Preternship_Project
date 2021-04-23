#include <iostream>
#include "../inc/Member.h"
#include "../inc/Owner.h"

int main(int argc, char** argv) {	
	if (argc > 1) {
		std::cout << "Too many arguments, " << argv[1] << std::endl;
		exit(1);
	}

	
	// Class test
	Owner nullOwner;
	Member nullMember;
	
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "| EMPTY MEMBERS OF CLASSES                       |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
		
	std::cout << nullOwner << std::endl;
	std::cout << nullMember << std::endl;
	
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "| READ IN VALUES OF CLASSES                      |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;	
	
	// TODO: Add in CSV reader

	// Queue test
	
	// Reader test
	
	return 0;
}
