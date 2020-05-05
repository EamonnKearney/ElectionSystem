#include "election.h"
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

	election::election() {}

	void election::add_vote(const vote& v) {
		/*adds a vote to the collection.*/
		votes.push_back(v);
	}

	int election::vote_count() const {
		/*returns the number of votes currently left*/
		return votes.size();
	}

	void election::eliminate(candidate c) {
		/*removes any occurrence of the named candidate from each
vote, and removes any votes that are now spent*/

		typedef vector<double>::size_type vec_size;

		for (auto& v : votes) {
			v.discard(c);
		}
		votes.erase(remove_if(votes.begin(), votes.end(), [](const vote& v) {return v.spent(); }), votes.end());

	}

	vector<pair<candidate, int>> election::ranked_candidates() const {
		/*returns a collection of candidates left in the election paired with the number of first preferences each has, in
decreasing order of that number. (If two candidates have the same number of first
preferences, either order will do.)
*/
		typedef vector<double>::size_type vec_size;

		//Removed
		//Go through each vote in the election.  For each candidate count the number of first prefs.
		//Number of Candidates

		/*
		candidate highest = 1;
		for (auto& v : votes) {
			for (auto& c : v.getPrefs()) {
				if (c > highest) highest = c;
			}
		}*/

		map<candidate, int> candFirstPrefMap;
		vector<pair<candidate, int>> candFirstPrefPairVect;

		for  (auto& v : votes)
		{
			++candFirstPrefMap[v.first_preference()];
		}

		//convert map into pair and place into vector.
		for (pair<candidate, int> p : candFirstPrefMap)
		{
			candFirstPrefPairVect.push_back(p);
		}


		
		//Sort Vector
		sort(candFirstPrefPairVect.begin(), candFirstPrefPairVect.end(), [](const pair<candidate, int>& a, const pair<candidate, int>& b) {return a.second > b.second; });
		
		return candFirstPrefPairVect;
	}
