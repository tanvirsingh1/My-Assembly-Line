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

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>

namespace sdds{
class Station
{
	int m_stat_id{};
	std::string m_item{};
	std::string m_descpt{};
	unsigned int m_next_serial{};
	unsigned int m_quant{};
	static size_t m_widthField;
	static size_t id_generator;
public:
	Station() = default;
	Station(const std::string& str);
	const std::string& getItemName() const;
	size_t getNextSerialNumber();
	size_t getQuantity() const;
	void updateQuantity();
	void display(std::ostream& os, bool full) const;

};
}


#endif // !

