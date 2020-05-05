#include "vote.h"
#include "election.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

fstream in("votes.txt"); //Input vote document
typedef vector<double>::size_type vec_size;

election read_votes(istream& in) { 

	election elect;
	string line;
	candidate cand;

	while (getline(in, line))
	{
		stringstream s(line);
		vector<candidate> candVect;
		while (s >> cand) //Each candidate
		{
			try
			{
				candVect.push_back(cand); //Placing candidates into a vector.
			}
			catch (const exception&)
			{
				cout << "Voting error";
			}
			
		}
		vote newVote(candVect); //Create new vote from the candidate vector.
		elect.add_vote(newVote); //Add vote to the election.
	}
	return elect;
}

int main(){
	election elect = read_votes(in); //Votes entered into election.
	int round = 1;
	bool elected = false;
	candidate eliminatedCand = 0;
	while (elected == false)
	{
		//Rank the candidates.  Returns a vector of pairs (Candidates to number of 1st prefs)
		auto candRank = elect.ranked_candidates();
		
		cout << "\nRound " << round << "\nNumber of votes: " << elect.vote_count() << "\n";
		cout << "\nFirst Preference Votes: \n";
		//Loop through the candidates
		for (vec_size i = 0; i < candRank.size(); i++)
		{
			//Output the candidates in order of first prefs, descending.
			cout << "Candidate " << candRank[i].first << " - Votes: " << candRank[i].second << '\n';
		}

		//If top candidate has over 50% of the votes - wins election
		if (candRank.front().second > elect.vote_count() / 2) {
			cout << "\nCandidate " << candRank.front().first << " has been elected.\n";
			break;
		}
		//Else last candidate eliminated, next round
		else {
			cout << "\nCandidate " << candRank.back().first << " eliminated.\n";
			elect.eliminate(candRank.back().first);

			round++;
			eliminatedCand = candRank.back().first;
			
			
		}
	}
	return 0;
}