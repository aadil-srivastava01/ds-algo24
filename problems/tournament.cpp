/* Problem Statement:

There's an algorithms tournament taking place in which teams of programmers compete against each other to solve algorithmic problems as fast as possible. Teams compete in a round robin, where each team faces off against all other teams. Only two teams compete against each other at a time, and for each competition, one team is designated the home team, while the other team is the away team. In each competition there's always one winner and one loser; there are no ties. A team receives 3 points if it wins and 0 points if it loses. The winner of the tournament is the team that receives the most amount of points.
Given an array of pairs representing the teams that have competed against each other and an array containing the results of each competition, write a function that returns the winner of the tournament. The input arrays are named competitions and results, respectively. The competitions array has elements in the form of [home Team, awayTeam], where each team is a string of at most 30 characters representing the name of the team. The results array contains information about the winner of each corresponding competition in the competitions array. Specifically, results[i] denotes the winner of competitions[i], where a 1 In the results array means that the home team in the corresponding competition won and a • means that the away team won.

It's guaranteed that exactly one team will win the tournament and that each team will compete against all other teams exactly once. It's also guaranteed that the tournament will always have at least two teams.
Sample Input:
competitions = [
                ["HTML", "C#"], ["C#", "Python"], ["Python", "HTML"]
            ]
results = [0, 0, 1]

Sample Output:
    "Python"

Solution Complexity:
O(n): Time | O(k): Space k-> Number of teams

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

string tournamentWinner(
    vector<vector<string>> &competitions, vector<int> &results)
{
    int maxWin{0};
    size_t index{0};
    string winnerName;
    unordered_map<string, int> leaderBoard;
    for (const int &winner : results)
    {
        if (winner)
        {
            ++leaderBoard[competitions.at(index).at(0)];
            if (maxWin < leaderBoard[competitions.at(index).at(0)])
            {
                maxWin = leaderBoard[competitions.at(index).at(0)];
                winnerName = competitions.at(index).at(0);
            }
        }
        else
        {
            ++leaderBoard[competitions.at(index).at(1)];
            if (maxWin < leaderBoard[competitions.at(index).at(1)])
            {
                maxWin = leaderBoard[competitions.at(index).at(1)];
                winnerName = competitions.at(index).at(1);
            }
        }
        ++index;
    }
    return winnerName;
}

int main()
{
    vector<vector<string>> competitions{{"HTML", "C#"}, {"C#", "Python"}, {"Python", "HTML"}};
    vector<int> results{0, 0, 1};
    cout << tournamentWinner(competitions, results) << endl;
    return 0;
}