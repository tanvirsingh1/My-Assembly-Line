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

#ifndef SDDS_CUSTOMER_ORDER_H
#define SDDS_CUSTOMER_ORDER_H
#include <iostream>
#include "Station.h"
#include "Utilities.h"
namespace sdds{

	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};
class CustomerOrder
{
	std::string m_name{};
	std::string m_product{};
	size_t m_cntItem{};
	Item** m_lstItem{};
	static size_t m_widthField;

public:
	CustomerOrder() = default;
	CustomerOrder(const std::string& str);
	CustomerOrder& operator=(const CustomerOrder& CO) = delete;
	CustomerOrder(const CustomerOrder& CO);
	CustomerOrder(CustomerOrder&& CO) noexcept;
	CustomerOrder& operator=(CustomerOrder&& CO)noexcept;

	~CustomerOrder();

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};
}

#endif

