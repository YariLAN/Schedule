/* FILE NAME:   excel.cpp
 * PURPOSE:     Import and export from Excel files implementation.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#include "../excel/excel.h"
#include "../cmake/config.h"

/* Import workers from .csv function.
 * ARGUMENTS:
 *     - path to .csv file:
 *           std::string file_path;
 * RETURNS:
 *     (std::vector<Worker>) imported workers.
 */
std::vector<Worker> ImportCSV(std::string file_path) {
    // List of workers
    std::vector<Worker> workers;

    
    // Open workers database file
    
    std::string path_to_csv = std::string(PROJ_DIR) + "/bin/excel/";
    std::ifstream file((path_to_csv + file_path).c_str());

    // Check if file was opened
    if (!file.is_open())
        return {};

    // Read database file
    while (file.good()) {
        // Read line to string
        std::string line;
        getline(file, line, '\n');

        // Worker fields
        std::vector<std::string> fields;

        // Put line in string stream
        std::stringstream ss(line);

        // Read fields from string stream
        while (getline(ss, line, ';'))
            fields.push_back(line);

        // Initialise worker from read fields
        if (line != "")
            workers.push_back(Worker(stoi(fields[0]), fields[1],
                stoi(fields[3]), (Worker::WorkerState)stoi(fields[5]), Worker::WorkerType::night));
    }

    // Close database file
    file.close();

    // Return workers
    return workers;
} /* End of 'ImportCSV' function */

/* End of 'excel.cpp' file */