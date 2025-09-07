#include <vector>
#include <string>
#include "trendtracker.h"




using namespace std;



// Creates a new Trendtracker tracking no hashtags.
		//
		// Must run in O(1) time.
		Trendtracker::Trendtracker(){

            E.clear();


        };

		// Inserts a hashtag (tweeted 0 times) into the Trendtracker.
		// If the hashtag already is in Trendtracker, does nothing.
		//
		// Must run in O(n) time.
		void Trendtracker::insert(string ht){

            for(int i = 0; i < E.size(); i++){

                if (E[i].hashtag == ht){

                    return;
                }

			}

				Entry newEntry;
				
				newEntry.hashtag = ht;

				newEntry.pop = 0;

				E.push_back(newEntry);

        }

		// Return the number of hashtags in the Trendtracker.
		//
		// Must run in O(1) time.
		int Trendtracker::size(){

            return E.size();

        }

		// Adds 1 to the total number times a hashtag has been tweeted.
		// If the hashtag does not exist in TrendTracker, does nothing.
		//
		// Must run in O(n) time.
		void Trendtracker::tweeted(string ht){

			for(int i = 0; i < E.size(); i++){

				if(E[i].hashtag == ht){

					E[i].pop++;

					return;
				}
				
			}


        }

		// Returns the number of times a hashtag has been tweeted.
		// If the hashtag does not exist in Trendtracker, returns -1.
		//
		// Must run in O(n) time.
		int Trendtracker::popularity(string name)
        {
			for(int i = 0; i < E.size(); i++){

				if(E[i].hashtag == name){

					return E[i].pop;
				}

			}

			return -1;
        }

		// Returns a most-tweeted hashtag.
		// If the Trendtracker has no hashtags, returns "".
		//
		// Must run in O(n) time.
		string Trendtracker::top_trend(){

			if(E.size() == 0){

				return "";
			}

			int mostweet = E[0].pop;

			string Nht = E[0].hashtag;


			for(int i = 0; i < E.size(); i++){

				if(E[i].pop > mostweet) {

					mostweet = E[i].pop;

					Nht = E[i].hashtag;
				}

			}

			return Nht;



			}

    
		// Fills the provided vector with the 3 most-tweeted hashtags,
		// in order from most-tweeted to least-tweeted.
		//
		// If there are fewer than 3 hashtags, then the vector is filled
		// with all hashtags (in most-tweeted to least-tweeted order).
		//
		// Must run in O(n) time.
		void Trendtracker::top_three_trends(vector<string> &T)
        {
			T.clear();

    if (E.empty())
        return;

    int cap = 3;
    vector<Entry> eTops;
    Entry placeholder;
    placeholder.pop = -1;
    for (int k = cap; k > 0; k--)
        eTops.push_back(placeholder);

    
    for (int n = 0; n < E.size(); n++)
    {
        
        if (E[n].pop > eTops[cap -1].pop)
        {
            
            int spot = cap -1;

            
            for (int k = spot; k >= 0; k--)
            {
                if (E[n].pop > eTops[k].pop)
                {
                    
                    eTops[spot] = eTops[k];

                    
                    spot = k;

                    
                    if (!spot)
                        eTops[spot] = E[n];
                    continue;
                }

                
                eTops[spot] = E[n];
            }
        }
    }

  
    for (int k = 0; k < cap; k++)
    {
        if (eTops[k].pop == -1)
            break;

        T.push_back(eTops[k].hashtag);
    }
}

		// Remove the given hashtag from the trendtracker.
		//
		// Must run in O(n) time.
		void Trendtracker::remove(string ht){

			for(int i = 0; i < E.size(); i++){

				if(E[i].hashtag == ht){

					E.erase(E.begin() + i);

					return;

				}

			}




        }

		// Fills the provided vector with the k most-tweeted hashtags,
		// in order from most-tweeted to least-tweeted.
		//
		// If there are fewer than k hashtags, then the vector is filled
		// with all hashtags (in most-tweeted to least-tweeted order).
		//
		// Must run in O(nk) time.
		void Trendtracker::top_k_trends(vector<string> &T, int k){

			T.clear();
    if (E.empty() || k <= 0) return;

    int cap = k;

    vector<Entry> eTops;

    Entry placeholder;

    placeholder.pop = -1;

   		 for (int i = 0; i < cap; i++)
        eTops.push_back(placeholder);

    for (int n = 0; n < E.size(); n++) {


        if (E[n].pop > eTops[cap - 1].pop) 
		{
            int spot = cap - 1;

            for (int j = spot; j >= 0; j--) 
			{
                if (E[n].pop > eTops[j].pop) 
				
				{
                    eTops[spot] = eTops[j];

                    spot = j;

                    if (spot == 0)

                        eTops[spot] = E[n];

                    continue;
                }
                eTops[spot] = E[n];
                break;
            }
        }
    }

    for (int i = 0; i < cap; i++) {

        if (eTops[i].pop == -1) break;

        T.push_back(eTops[i].hashtag);
    }
}

