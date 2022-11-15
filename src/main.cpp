/* FILE NAME:   main.cpp
 * PURPOSE:     Main module implementation.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#include <ctime>

#include <iostream>
#include <map>

#include "cmake/config.h"
#include "excel/excel.h"
#include "logic/logic.h"
#include "testing/testing.h"
#include "ui/ui.h"
#include "worker/worker.h"

/* Main function.
 * ARGUMENTS: None.
 * RETURNS:
 *     (int) OS return code.
 */
int main(void) {
    // Change to russian locale
    setlocale(LC_ALL, "ru_RU.UTF-8");

    // Setup seed for randomiser
    srand(time(0));

    // List of workers
    std::vector<Worker> workers = ImportCSV("5.csv");

    // Print all imported workers
    for (auto person : workers)
        std::cout << person << std::endl;
    std::cout << std::endl;

    // User input variable
    bool print_sch;

    // Check if user wants to print a schedule
    std::cout << "Do you want to print a schedule for all workers? (1/0)" << std::endl;
    std::cin >> print_sch;
    std::cout << std::endl;

    // Number of days in schedule
    int days_amount = 0;

    // Get days amount in schedule
    if (print_sch) {
        std::cout << "How many days do you want to be in schedule?" << std::endl;
        std::cin >> days_amount;
        std::cout << std::endl;
    }

    // Get randomised set of workers IDs
    std::vector<int> workers_randomised = RandomiseWorkers(workers);

    // Create workers groups
    std::vector<int> group1, group2, group3;
    tie(group1, group2, group3) = GroupWorkers(workers_randomised);

    // Match workers IDs with corresponding groups and store them in dictionary
    std::map<int, int> workers_groups;

    // Print workers schedule
    std::cout << "Workers schedule:" << std::endl << std::endl;

    // Print first workers group schedule
    for (int i = 0; i < group1.size(); i++) {
        workers_groups[group1[i]] = 1;
        std::cout << workers[group1[i]].GetWorkerName() << std::endl;
        for (auto x : CreateSchedule(workers_groups[group1[i]], days_amount))
            std::cout << x << " ";
        std::cout << std::endl << std::endl;
    }

    // Print second workers group schedule
    for (int i = 0; i < group2.size(); i++) {
        workers_groups[group2[i]] = 2;
        std::cout << workers[group2[i]].GetWorkerName() << std::endl;
        for (auto x : CreateSchedule(workers_groups[group2[i]], days_amount))
            std::cout << x << " ";
        std::cout << std::endl << std::endl;
    }

    // Print third workers group schedule
    for (int i = 0; i < group3.size(); i++) {
        workers_groups[group3[i]] = 3;
        std::cout << workers[group3[i]].GetWorkerName() << std::endl;
        for (auto x : CreateSchedule(workers_groups[group3[i]], days_amount))
            std::cout << x << " ";
        std::cout << std::endl << std::endl;
    }

    // Return OS code of success
    return 0;
} /* End of 'main' function */

/* End of 'main.cpp' file */