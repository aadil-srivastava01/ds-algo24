/* Problem Statement:

deadline, meaning there is no value in completing the work after the deadline. Additionally, each job has an associated payment
representing the profit for completing that job. Given this information, write a function that returns the maximum profit that can
be obtained in a 7-day period.
Each job will take 1 full day to complete, and the deadline will be given as the number of days left to complete the job. For example, if a job has a deadline of 1, then it can only be completed if it is the first job worked on. If a job has a deadline of 2, then it could be started on the first or second day.
Note: There is no requirement to complete all of the jobs. Only one job can be worked on at a time, meaning that in some scenarios it will be impossible to complete them all.
Sample Input
jobs = [ {"deadline": 1, "payment": 1}, {"deadline": 2, "payment": 1}, {"deadline": 2, "payment": 2}
]
Sample Output
3 // Job would be completed first, followed by job 2. Job 1 is not completed.

Solution Complexity:

Time: O(nlog(n)) | Space: O(1)

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>
using namespace std;
int optimalFreelancing(vector<unordered_map<string, int>> &jobs)
{
    unordered_map<int, int> maxProfitForDays;
    array<int, 7> maxOnDay{{0, 0, 0, 0, 0, 0, 0}};
    sort(jobs.begin(), jobs.end(), [](auto &a, auto &b)
         { return a["payment"] > b["payment"]; });

    int deadline{0};
    for (auto &job : jobs)
    {
        deadline = job.at("deadline") - 1 > 6 ? 6 : job.at("deadline") - 1;
        while (deadline >= 0)
        {
            if (maxOnDay.at(deadline) == 0)
            {
                maxOnDay.at(deadline) = job.at("payment");
                break;
            }
            else
                deadline--;
        }
    }
    return accumulate(maxOnDay.begin(), maxOnDay.end(), 0);
}

int main()
{
    vector<unordered_map<string, int>> jobs = {
        {{"deadline", 1}, {"payment", 1}}};
    cout << optimalFreelancing(jobs) << endl;

    return 0;
}