/* FILE NAME:   logic.cpp
 * PURPOSE:     Schedule creation automation logic implementation.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#include "logic.h"

#include "../worker/worker.h"

/* Create worker's schedule function.
 * ARGUMENTS:
 *     - alternations of dates variations:
 *           int date_id;
 *     - number of days:
 *           int days_amount;
 * RETURNS:
 *     (std::vector<int>) worker`s schedule.
 */
std::vector<int> CreateSchedule(int date_id, int days_amount) {
    // Alternations of dates
    std::vector<int>
        l1 = { 1, 1 },
        l2 = { 0, 0 },
        l3 = { 0, 1 },
        l4 = { 1, 0 };

    // Create schedule and allocate memory for it
    std::vector<int> rasp;
    rasp.resize(days_amount);

    // Fill worker's schedule with alternating working days
    for (int i = 0; i < days_amount; i++)
        switch (date_id) {
            case 1:
                rasp[i] = l1[i % 2];
                if (i % 2 == 1)
                    date_id = 2;
                break;
            case 2:
                rasp[i] = l2[i % 2];
                if (i % 2 == 1)
                    date_id = 1;
                break;
            case 3:
                rasp[i] = l3[i % 2];
                if (i % 2 == 1)
                    date_id = 4;
                break;
            case 4:
                rasp[i] = l4[i % 2];
                if (i % 2 == 1)
                    date_id = 3;
                break;
            default:
                break;
        }

    // Return created schedule
    return rasp;
} /* End of 'CreateSchedule' function */

/* Randomise set of workers IDs function.
 * ARGUMENTS:
 *     - list of workers IDs:
 *           std::vector<Worker> workers_ids;
 * RETURNS:
 *     (std::vector<int>) list of randomized IDs.
 */
std::vector<int> RandomiseWorkers(std::vector<Worker> workers_ids) {
    // Create list of workers and allocate memory for it
    std::vector<int> workers_randomised;
    workers_randomised.resize(workers_ids.size());

    // Copy workers IDs to the list
    for (int i = 0; i < workers_ids.size(); i++)
        workers_randomised[i] = workers_ids[i].GetWorkerID();

    // Randomly swap workers IDs
    for (int i = workers_ids.size() - 1; i > 0; --i)
        std::swap(workers_randomised[i], workers_randomised[rand() % (i + 1)]);

    // Return randomized set of IDs
    return workers_randomised;
} /* End of 'RandomiseWorkers' function */

/* Group workers function.
 * ARGUMENTS:
 *     - list of workers IDs:
 *           std::vector<int> workers_ids;
 * RETURNS:
 *     (std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>) workers groups.
 */
std::tuple<std::vector<int>, std::vector<int>, std::vector<int>> GroupWorkers(std::vector<int> workers_ids) {
    // Workers groups
    std::vector<int> v1, v2, v3;

    if (workers_ids.size() % 2 == 0) {
        // If there is even number of workers then there are two groups
        v1.resize(workers_ids.size() / 2);
        copy(workers_ids.begin(), workers_ids.begin() + (workers_ids.size() / 2), v1.begin());
        v2.resize(workers_ids.size() / 2);
        copy(workers_ids.begin() + (workers_ids.size() / 2), workers_ids.end(), v2.begin());
    } else {
        // If there is odd number of workers then there are three groups
        v1.resize(workers_ids.size() / 2);
        copy(workers_ids.begin(), workers_ids.begin() + (workers_ids.size() / 2), v1.begin());
        v2.resize(workers_ids.size() / 2);
        copy(workers_ids.begin() + (workers_ids.size() / 2), workers_ids.end() - 1, v2.begin());
        v3.resize(1);
        v3[0] = workers_ids[workers_ids.size() - 1];
    }

    // Return workers groups
    return make_tuple(v1, v2, v3);
} /* End of 'GroupWorkers' function */

/* End of 'logic.cpp' file */