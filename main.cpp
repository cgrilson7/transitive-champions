#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <map>
#include <regex>
#include <set>

using namespace std;

// Containers and transitive champion counter
set<string> allTeams;
map<string, list<string>> losses;
map<string, bool> visited;
int numChamps = 0;

// Helper functions
vector<string> split(string const &input);
std::string trim(const std::string &s);

// Depth-first search
void DFS(string team);


int main(int argc, char* argv[])
{
    string inFname = argv[1];
    ifstream results(inFname);
    if (!results.is_open()) {
        cerr << "Can't open input file " << inFname << endl;
        return -1;
    }

    string game;

    while(getline(results, game)){
        game.erase(std::remove(game.begin(), game.end(), '@'), game.end());
        vector<string> teams = split(game);
        string w = trim(teams[1]);
        allTeams.insert(w);
        string l = trim(teams[2]);
        allTeams.insert(l);
        losses[l].push_back(w);
        visited[l] = false;
    }

    string champ = argv[2];
    DFS(champ);

    cout << "Number of teams who played a D1 opponent in the 2018-19 season: " << allTeams.size() << endl;
    cout << "Number of transitive champions: " << numChamps << endl;
    cout << "Leaving " << (allTeams.size() - numChamps) << " teams who are not transitive champions." << endl;

    return 0;
}

vector<string> split(string const &input) { 
    vector<string> tokens;
    regex rgx("[\\d-]+[\\s+@]");
    sregex_token_iterator it(input.begin(), input.end(), rgx, -1);
    sregex_token_iterator end;
    while(it != end){
        tokens.push_back(*it);
        ++it;
    }
    return tokens;
}

std::string trim(const std::string &s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isspace(*it))
        it++;

    string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && isspace(*rit))
        rit++;

    return string(it, rit.base());
}

void DFS(string team){
    visited[team] = true;
    ++numChamps;
    list<string>::iterator it;
    for(it = losses[team].begin(); it != losses[team].end(); ++it)
    {
        if(!visited[*it])
        {
            DFS(*it);
        }
    }
}