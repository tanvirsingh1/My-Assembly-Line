/*BTP-305 Final Project
Module: N/A
Name : Tanvir Singh
Seneca Email :tanvir-singh1@myseneca.ca
Student ID : 104642210
Section information code = BTP305NAA
Date : 2022-11-18
I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
Date       Reason
---------------------------------------------------------- - */

#ifndef UTILITIES_SDDS_H
#define UTILITIES_SDDS_H

#include <iostream>
namespace sdds {
	class Utilities
	{
		size_t m_widthField = 1u;
		static char m_delimiter;

	public:
		Utilities() = default;
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
	
	};
	void ERASESPACES(std::string& s);

}



#endif // !

