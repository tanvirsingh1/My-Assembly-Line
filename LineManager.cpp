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
#include <algorithm>
#include <numeric>
#include <functional>

#include <string>
#include <fstream>
#include "LineManager.h"
#include "Workstation.h"

using namespace std;

namespace sdds
{
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		Utilities ut{};
		string first_stat{};
		string last_stat{};
		
		string line{};
		ifstream fil(file);

		
		if (fil)
		{
			while (getline(fil, line))
			{
				size_t pos = 0;
				bool flag = false;

				first_stat = ut.extractToken(line, pos, flag);
				if (flag)
				{
					last_stat = ut.extractToken(line, pos, flag);
				}
				else
				{
					last_stat = "";
				}
				auto res = find_if(stations.begin(), stations.end(), [&](const Workstation* ws) {
					return  first_stat == ws->getItemName();
					});

				if (res != stations.end())
				{
					m_activeLine.push_back(*res);
				}

				auto res2 = find_if(stations.begin(), stations.end(), [&](const Workstation* ws) {
					return  last_stat == ws->getItemName();
					});

				if (res2 != stations.end())
				{
					m_activeLine.back()->setNextStation(*res2);
				}
			}

		
		}
		else
		{
			throw "Invalid file name";
		}
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {

			bool flag = any_of(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* bws) {
				if (bws->getNextStation() != nullptr) {
					if (ws->getItemName() == bws->getNextStation()->getItemName())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
				

				});
			if (flag == false)
			{
				m_firstStation = ws;
			}
			});
		m_cntCustomerOrder = g_pending.size();
		fil.close();

	}
	void LineManager::reorderStations()
	{
		vector<Workstation*> L_sorted{};
		
		Workstation* station = m_firstStation;

		while (station !=nullptr) {
			L_sorted.push_back(station);
			station = station->getNextStation();
		}
		copy(L_sorted.begin(), L_sorted.end(),m_activeLine.begin());

	}
	bool LineManager::run(std::ostream& os)
	{
		static int m_cnt = 0;

		os << "Line Manager Iteration: "<<++m_cnt << endl;

		if (!g_pending.empty())
		{
		
			*m_firstStation += std::move(g_pending.front());
			
			g_pending.pop_front();
		}

	
		std::for_each(m_activeLine.begin(), m_activeLine.end(),
			[&](Workstation* work) { work->fill(os); });


		std::for_each(m_activeLine.begin(), m_activeLine.end(),
			[&](Workstation* work) { work->attemptToMoveOrder(); });

		size_t done = g_completed.size();
		size_t not_done = g_incomplete.size();
		return m_cntCustomerOrder == done + not_done;
	}
	void LineManager::display(std::ostream& os) const
	{
		for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* wk) {
			wk->display(os); });
	}
}