/* FILE NAME:   logic.cpp
 * PURPOSE:     Schedule creation automation logic declaration.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#ifndef LOGIC_H_
#define LOGIC_H_

#include <tuple>
#include <vector>

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
std::vector<int> CreateSchedule(int date_id, int days_amount);

/* Randomise set of workers IDs function.
 * ARGUMENTS:
 *     - list of workers IDs:
 *           std::vector<Worker> workers_ids;
 * RETURNS:
 *     (std::vector<int>) list of randomized IDs.
 */
std::vector<int> RandomiseWorkers(std::vector<Worker> workers_ids);

/* Group workers function.
 * ARGUMENTS:
 *     - list of workers IDs:
 *           std::vector<int> workers_ids;
 * RETURNS:
 *     (std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>) workers groups.
 */
std::tuple <std::vector<int>, std::vector<int>, std::vector<int>> GroupWorkers(std::vector<int> workers_ids);

#endif // LOGIC_H_

/* End of 'logic.h' file */