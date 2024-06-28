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
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{

	size_t Station::m_widthField = 1;
	size_t Station::id_generator = 0;

	Station::Station (const std::string& str)
	{
		Utilities Ut{};
		size_t pos = 0;
		bool flag = false;

		m_item = Ut.extractToken(str, pos, flag);
		m_next_serial = stoi(Ut.extractToken(str, pos, flag));
		m_quant = stoi(Ut.extractToken(str, pos, flag));

		if (m_widthField < Ut.getFieldWidth())
		{
			m_widthField = Ut.getFieldWidth();
		}

		m_descpt = Ut.extractToken(str, pos, flag);
		m_stat_id = ++id_generator;
	}
	const std::string& Station::getItemName() const
	{
		return m_item;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_next_serial++;
	}
	size_t Station::getQuantity() const
	{
		return m_quant;
	}
	void Station::updateQuantity()
	{
		if (m_quant > 0)
			m_quant--;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		
			os << right<< setfill('0') << setw(3)  << m_stat_id << " | " <<setfill(' ')<<left << setw(m_widthField+1) << m_item << " | " << setfill('0') << right<<setw(6)  << m_next_serial << " | " << setfill(' ');
		
			if (full)
			{
				os << right<< setw(4) << m_quant << " | " << m_descpt;
		}
		

			os << endl;
		
	}
}
