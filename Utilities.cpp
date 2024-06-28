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

#include <iostream>
#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds
{

	char Utilities::m_delimiter = '|';
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		
		string token{};
		more = true;
		size_t start = next_pos;
		if (str.length() > next_pos)
		{
			next_pos = str.find(m_delimiter, next_pos);

			if (next_pos!= string::npos)
			{
				token = str.substr(start, next_pos - start);
			
			}
			else
			{
				token = str.substr(start, str.length());
				more = false; 
	
			}

		}

	
		 
		if (!token.empty() )
		{
			ERASESPACES(token);

			if (str.find(m_delimiter, next_pos) != string::npos)
				more = true;

			next_pos = next_pos + 1;		
			if (m_widthField < token.length())
			{
				m_widthField = token.length();
			}
			
		}

		else
		{
			throw "ERROR: No token.";
		}

		return token;
	}
	
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
	void ERASESPACES(std::string& s)
	{
		s = s.erase(0, s.find_first_not_of(' '));
		s = s.erase(s.find_last_not_of(' ') + 1, s.length() - s.find_last_not_of(' '));

	}
}
