#include <fstream>
#include <string>
#include <iostream>
#include "Owner.h"
#include "Member.h"
#include <vector>

class CSVReader {
	
	private:
		std::ofstream outstream;
		std::ifstream instream;
		
	public:
		
		// Copy Constructor(shouldn't be used)
		CSVReader(const CSVReader& CSVReader_in);
		
		// File contructor (this is the one)
		CSVReader(const char* &file_output, const char* &file_input) :
			outstream(file_output),
			instream(file_input) {}
		
		// Destructor (important for closing streams)
		~CSVReader() {
			outstream.close();
			instream.close();
		}
		
		// Assignment Operator (shouldn't be used)
		CSVReader& operator= (const CSVReader& rhs);
		
		void readline(/*Owner &owner_in*/) {
			// Reads one line from instream to line
			std::string line;
			std::getline(instream, line);
			std::vector<std::string> parsed_string; // Delimited version of line
			
			size_t pos = 0;
			std::string token;
			while ((pos = line.find(',')) != std::string::npos) {
			    token = line.substr(0, pos);
				parsed_string.push_back(token);
				line.erase(0, pos + 1);
			}
			std::cout << token << std::endl;
			
			Owner owner_out();
		}

		void readline(Member &member_in);
		
};
