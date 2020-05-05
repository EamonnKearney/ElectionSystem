#include "vote.h"
#include <vector>
#include <algorithm>

using namespace std;

	typedef unsigned int candidate; //Candidate type

	vote::vote(const vector<candidate>& prefs) {
		/*set up a vote with a sequence of candidate
identifiers in preference order (first preference first).*/
		 prefVect = prefs;
	}

	bool vote::spent() const {
		/*Returns true if vote has no preferences left.*/
		return prefVect.empty();
	}

	candidate vote::first_preference() const {
		/*returns the current first preference of the vote. Clients
may only call this member function if spent() is false*/
		return prefVect[0];
	}

	void vote::discard(candidate c) {
		/*removes any occurrence of the named candidate from the
vote*/
		prefVect.erase(remove(prefVect.begin(), prefVect.end(), c), prefVect.end());
	}

	vector<candidate> vote::getPrefs() const {
		return prefVect;
	}
