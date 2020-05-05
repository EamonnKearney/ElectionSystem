#pragma once
#include "vote.h"



class election {

	std::vector<vote> votes; //Vector holding the candidate preferences
	
public:

	election();

	void add_vote(const vote& v);

	int vote_count() const;

	void eliminate(candidate c);

	std::vector<std::pair<candidate, int>> ranked_candidates() const;

};