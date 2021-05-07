#include <iostream>
#include "../inc/Member.h"
#include "../inc/Owner.h"
#include "../inc/csvio.h"

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
	
	// CSV reader/writer test
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "| READ IN FIRST OWNER                            |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;	
	
	// Note: also works with Member, but you need a separate reader for each.
	
	// File names must be const char* type
	const char* fileout = "vendorout.csv";
	const char* filein = "vendor.csv";
	
	// The constructor for the reader, it must take BOTH an input and output
	// file. You can make them NULL if need be
	CSVReader reader(fileout, filein); 
	
	// The owner that will be written to
	Owner test_owner;
	
	// This will read the next line in the csv and write it to the owner in parameter
	// Outputs true if successful, false if not
	reader.readline(test_owner); 
	
	std::cout << test_owner << std::endl;
	
	// Don't forget to close the reader
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "| WRITE OUT FIRST OWNER                          |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;	
	
	// Takes in an owner and writes it to the csv
	reader.ownertocsv(test_owner);
	
	// Don't forget to close the reader
	reader.close();
	
	// This is just printing the added line in the csv
	std::ifstream file(fileout);
	std::string temp;
	std::getline(file, temp);
	std::getline(file, temp);
	std::cout << temp << std::endl;
	file.close();
	
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "| READ IN FIRST MEMBER                           |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;	
	const char* filein2 = "solutions.csv";
	const char* fileout2 = "solutionsout.csv";
	
	CSVReader reader2(fileout2, filein2);
	Member test_member;
	reader2.readline(test_member);
	
	std::cout << test_member << std::endl;
	
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << "| WRITE OUT FIRST VENDOR                         |" << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;	
	
	reader2.membertocsv(test_member);

	reader2.close();

	std::ifstream file2(fileout2);
	std::getline(file2, temp);
	std::getline(file2, temp);
	std::cout << temp << std::endl;
	file2.close();
	
	
	// Queue test
	
	// Reader test
	
	return 0;
}
