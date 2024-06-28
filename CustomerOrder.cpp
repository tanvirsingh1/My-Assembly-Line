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
#include<iterator>
#include <iomanip>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;
	CustomerOrder::CustomerOrder(const std::string& str)
	{
		size_t pos = 0;
		Utilities Ut{};
		bool flag = false;

		string val{};
		if (!str.empty())
		{
			m_name = Ut.extractToken(str, pos, flag);
			
			m_product = Ut.extractToken(str, pos, flag);
			std::string sub = str.substr(pos, str.length());
			for (auto i = 0u; i < sub.length(); i++)
			{
				if (sub[i] == Ut.getDelimiter())
				{
					m_cntItem++;
				}
			}

			m_cntItem = m_cntItem + 1;
		
			m_lstItem = new Item * [m_cntItem];
		
			for (auto i = 0u; i < m_cntItem; i++)
			{
				val = Ut.extractToken(str, pos, flag);
			
				m_lstItem[i] = new Item(val);
			
			}
			if (m_widthField < Ut.getFieldWidth())
			{
				m_widthField = Ut.getFieldWidth();
			}

		}
}

	CustomerOrder:: CustomerOrder(const CustomerOrder& CO)
	{
		throw "Error";
	}
	CustomerOrder:: CustomerOrder(CustomerOrder&& CO) noexcept
	{
		*this = move(CO);
	}
	CustomerOrder& CustomerOrder:: operator=(CustomerOrder&& CO)noexcept
	{
		if (this != &CO)
		{
			for (auto i = 0u; i < m_cntItem; i++)
			{
				delete m_lstItem[i];

				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
			this->m_name = CO.m_name;
			m_product = CO.m_product;
			m_cntItem = CO.m_cntItem;
		
			m_lstItem = nullptr;

			m_lstItem = CO.m_lstItem;


			CO.m_lstItem = nullptr;
			CO.m_cntItem = 0;
	   }
		return *this;
	}

	CustomerOrder::~CustomerOrder()
	{

		for (auto i = 0u; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
			
			m_lstItem[i] = nullptr;
		}
		delete[] m_lstItem;
		m_lstItem = nullptr;
	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool val = true;
		for (auto i = 0u; i < m_cntItem; i++)
		{
		  val = m_lstItem[i]->m_isFilled;
		  if (val == false)
		  {
			  return false;
		  }
		}
		return true;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{

		bool val = true;

		for (auto i = 0u; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				if (!m_lstItem[i]->m_isFilled)
				{
					val = false;
				}


			}


		}

		return val;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		bool flag = true;
		for (auto i = 0u; i < m_cntItem && flag ; i++)
		{
			
			if ( m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
			{

				if (station.getQuantity() >0  )
				{
					flag = false;
				
					m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
					m_lstItem[i]->m_isFilled = true;
					station.updateQuantity(); 
					
					os << "    Filled " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;

				}
				else if(!m_lstItem[i]->m_isFilled && !station.getQuantity())
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << station.getItemName() << "]" << std::endl;
				}
			}

		}
	
	}
	void CustomerOrder::display(std::ostream& os) const
	{

			os << m_name << " - " << m_product << endl;

			for (auto i = 0u; i < m_cntItem; i++)
			{
				os << "[" << right<<setfill('0') << setw(6) << m_lstItem[i]->m_serialNumber << setfill(' ') << "] " << setw(m_widthField + 1) << left << m_lstItem[i]->m_itemName << "  - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
			}
		}
	
}