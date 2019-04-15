# transitive-champions
My solution to Oliver Roeder's "transitive champions" riddle. (NCAA Division 1 Basketball 2018-19)

I wrote a program that, given a text file of results and a team name, builds a (quite rudimentary) graph where the edges are that team's losses to their opponents, and those opponents' losses to their opponents, etc.
Then, using a recursive depth-first search, the program counts the total number of teams connected in this way. It also writes to .csv ("adjacency_list.csv") the pared-down lines from the input files.

#Data from MasseyRatings.com:
Women's: https://www.masseyratings.com/scores.php?s=305973&sub=305973&all=1
Men's: https://www.masseyratings.com/scores.php?s=cb2019&sub=ncaa-d1&all=1&sch=1

#Example use:
C:\Users\cgrilson7\transitiveChamps>countChamps mens_results.txt Virginia
Number of teams who played a D1 opponent in the 2018-19 season: 650
Number of transitive champions: 359
Leaving 291 teams who are not transitive champions.

C:\Users\cgrilson7\transitiveChamps>countChamps womens_results.txt Baylor
Number of teams who played a D1 opponent in the 2018-19 season: 2020
Number of transitive champions: 1776
Leaving 244 teams who are not transitive champions.

#Results:
I took advantage of some handy functions in R's igraph to look at some of the paths running through the graph.
- ALL men's D1 teams were transitive champions in 2018-19!
- The champion with the highest degree of separation (8) - that is, the one at the end of the longest path to Virginia - was a Division II team, Fayettville St. Go Broncos!
      That path:
      Virginia lost to
      Duke who lost to
      Syracuse who lost to 
      Old Dominion who lost to
      Southern Miss who lost to 
      Longwood who lost to
      SC Upstate who lost to
      UNC Asheville who lost to
      Fayetteville St
