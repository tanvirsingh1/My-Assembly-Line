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
#include <deque>
#include "Station.h"
#include "Workstation.h"

using namespace std;

namespace sdds {

	std::deque<CustomerOrder> g_pending{};
	std::deque<CustomerOrder> g_completed{};
	std::deque<CustomerOrder> g_incomplete{};
	Workstation::Workstation(const std::string& ref):Station(ref)
	{
	}
	void Workstation::fill(std::ostream& os)
	{

		if (!m_orders.empty() && !m_orders.front().isItemFilled(this->getItemName()))
		{		
				m_orders.front().fillItem(*this, os);
		}

	}
	bool Workstation::attemptToMoveOrder()
	{
		bool flag = false;
		if (m_orders.size() > 0)
		{
			if (m_orders.front().isItemFilled(Station::getItemName()) || !getQuantity())
			{

				if (m_next )
				{
					*m_next += std::move(m_orders.front());

				}
				else
				{
					if (m_orders.front().isOrderFilled())
						g_completed.push_back(std::move(m_orders.front()));
					else

						g_incomplete.push_back(std::move(m_orders.front()));


				}
				m_orders.pop_front();
				flag = true;

			}
		}
			
		
		return flag;
	}
	void Workstation::setNextStation(Workstation* station)
	{
		m_next = station;
		station = nullptr;
	}
	Workstation* Workstation::getNextStation() const
	{
		return m_next;
	}
	void Workstation::display(std::ostream& os) const
	{
		os << Station::getItemName() << " --> ";
		if (!m_next || m_next->getItemName().empty())
		{
			
			os << "End of Line\n";
		}
		else
		{
			os << m_next->getItemName() << endl;
		}
	}
	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}