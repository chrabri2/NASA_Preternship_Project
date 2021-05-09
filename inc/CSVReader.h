// CSVReader class
// Reads and writes various class objects between data and csv files.

#ifndef CSVREADER_H
#define CSVREADER_H

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
		std::vector<std::string> fields; // In case it is needed in future
		
		// Parses a delimited string (by ',') into a vector
		std::vector<std::string> splitstring(std::string& line) const {
			std::vector<std::string> parsed_string; // Delimited version of line
			
			// This block uses ',' as a delimiter to split the string into a vector
			size_t pos = 0;
			std::string field;
			while ((pos = line.find(',')) != std::string::npos) { // Continues as long as ',' is found
			    field = line.substr(0, pos); 
				parsed_string.push_back(field); // Adds field to the vector
				line.erase(0, pos + 1); // Removes the first part of the string
			}
			parsed_string.push_back(line); // Gets the last field that doesn't have a ','.
			
			return parsed_string;
		}
		
		std::string ownertostring(const Owner& owner_in) {
			std::string line = "";
			line += owner_in.get_Type().append(",");
			line += owner_in.get_Members().append(",");
			line += owner_in.get_CampID().append(",");
			line += owner_in.get_CampName().append(",");
			line += owner_in.get_ChallID().append(",");
			line += owner_in.get_ChallType().append(",");
			line += owner_in.get_Coordinator().append(",");
			line += std::to_string(owner_in.get_WeightAccepted()).append(",");
			line += std::to_string(owner_in.get_Volume()).append(",");
			line += std::to_string(owner_in.get_Energy()).append(",");
			line += std::to_string(owner_in.get_SoundsVolume()).append(",");
			line += std::to_string(owner_in.get_Years()).append(",");
			line += std::to_string(owner_in.get_SurfaceTemp()).append(",");
			line += std::to_string((int)owner_in.get_Preprocesses()).append(",");
			line += std::to_string(owner_in.get_AwardAmount()).append(",");
			line += std::to_string(owner_in.get_ActualCost()).append(",");
			line += std::to_string(owner_in.get_BudgetCost()).append(",");
			line += std::to_string(owner_in.get_EstDollars()).append(",");
			
			return line;
		}
		
		
		std::string membertostring(const Member& member_in) {
			std::string line = "";
			line += member_in.get_Type().append(",");
			line += member_in.get_Members().append(",");
			line += ",";
			line += ",";
			line += member_in.get_CampID().append(",");
			line += member_in.get_CampName().append(",");
			line += member_in.get_ChallID().append(",");
			line += member_in.get_ChallType().append(",");
			line += member_in.get_Coordinator().append(",");
			line += std::to_string(member_in.get_WeightAccepted()).append(",");
			line += std::to_string(member_in.get_Volume()).append(",");
			line += std::to_string(member_in.get_Energy()).append(",");
			line += std::to_string(member_in.get_SoundsVolume()).append(",");
			line += std::to_string(member_in.get_Years()).append(",");
			line += std::to_string(member_in.get_SurfaceTemp()).append(",");
			line += std::to_string((int)member_in.get_Preprocesses()).append(",");
			
			return line;
		}
		
		// Reads a line and sets the fields variable
		void setfields() {
			std::string line;
			if (!std::getline(instream, line)) {
				std::cout << "The input file is missing fields" << std::endl;
			}
			
			outstream << line << std::endl;
			
			fields = splitstring(line);
		}
		
	public:
		
		// File contructor (this is the one)
		CSVReader(const char* &file_output, const char* &file_input) :
			outstream(file_output),
			instream(file_input), 
			fields() {setfields();}
		
		// closer (important for closing streams)
		void close() {
			outstream.close();
			instream.close();
		}
		
		bool readline(Owner& owner_in) {
			// Reads one line from instream to line
			std::string line;
			if (!std::getline(instream, line)) {
				std::cout << "Readline either found an empty line or the end of file" << std::endl;
				return false;
			}
			
			// Parse the string to a vector
			std::vector<std::string> parsed_string = splitstring(line);
			
			// Flag for constructor at 13
			bool preprocess_waste;
			if (parsed_string.at(13) == "y" || parsed_string.at(13) == "Y") 
				preprocess_waste = true;
			else
				preprocess_waste = false;
			
			Owner owner_out(
				std::stof(parsed_string.at(14)),
				std::stof(parsed_string.at(15)),
				std::stof(parsed_string.at(16)),
				std::stof(parsed_string.at(17)),
				parsed_string.at(0),
				parsed_string.at(1),
				parsed_string.at(2),
				parsed_string.at(3),
				parsed_string.at(4),
				parsed_string.at(5),
				parsed_string.at(6),
				std::stof(parsed_string.at(7)),
				std::stof(parsed_string.at(8)),
				std::stod(parsed_string.at(9)),
				std::stof(parsed_string.at(10)),
				std::stof(parsed_string.at(11)),
				std::stof(parsed_string.at(12)),
				preprocess_waste
			);
			
			owner_in = owner_out;
			return true;
		}

		bool readline(Member& member_in) {
			// Reads one line from instream to line
			std::string line;
			if (!std::getline(instream, line)) {
				std::cout << "Readline either found an empty line or the end of file" << std::endl;
				return false;
			}

			// Parse the string to a vector
			std::vector<std::string> parsed_string = splitstring(line);
			
			// Flag for constructor at 13
			bool preprocess_waste;
			if (parsed_string.at(15) == "1") 
				preprocess_waste = true;
			else
				preprocess_waste = false;
			
			Member member_out(
				0,
				0,
				false,
				parsed_string.at(0),
				parsed_string.at(1),
				parsed_string.at(4),
				parsed_string.at(5),
				parsed_string.at(6),
				parsed_string.at(7),
				parsed_string.at(8),
				std::stof(parsed_string.at(9)),
				std::stof(parsed_string.at(10)),
				std::stod(parsed_string.at(11)),
				std::stof(parsed_string.at(12)),
				std::stof(parsed_string.at(13)),
				std::stof(parsed_string.at(14)),
				preprocess_waste
			);
			
			member_in = member_out;
			return true;
		}
		
		void ownertocsv(const Owner& owner_in) {
			std::string line = ownertostring(owner_in);
			outstream << line << std::endl;
		}
		
		void membertocsv(const Member& member_in) {
			std::string line = membertostring(member_in);
			outstream << line << std::endl;
		}
};

#endif
