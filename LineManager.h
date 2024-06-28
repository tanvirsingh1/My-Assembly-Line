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

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <iostream>
#include <deque>
#include <vector>
#include "Utilities.h"
#include "CustomerOrder.h"
#include "Workstation.h"
namespace sdds{
class LineManager
{
	std::vector<Workstation*> m_activeLine{};
	size_t m_cntCustomerOrder{};
	Workstation* m_firstStation{};

public:
	LineManager(const std::string& file, const std::vector<Workstation*>& stations);

	void reorderStations();
	bool run(std::ostream& os);
	void display(std::ostream& os) const;

};
}

#endif // !



