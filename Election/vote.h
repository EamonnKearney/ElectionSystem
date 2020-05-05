#pragma once
#include <vector>

typedef unsigned int candidate;

class vote {

	std::vector<candidate> prefVect; //Vector holding the candidate preferences
	
public:

	vote(const std::vector<candidate>& prefs);

	bool spent() const;

	candidate first_preference() const;

	void discard(candidate c);

	std::vector<candidate> getPrefs() const;
};
