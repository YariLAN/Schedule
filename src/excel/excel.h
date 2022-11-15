/* FILE NAME:   excel.h
 * PURPOSE:     Import and export from Excel files declaration.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#ifndef EXCEL_H_
#define EXCEL_H_

#include <fstream>
#include <sstream>
#include <vector>

#include "../worker/worker.h"

/* Import workers from .csv function.
 * ARGUMENTS:
 *     - path to .csv file:
 *           std::string file_path;
 * RETURNS:
 *     (std::vector<Worker>) imported workers.
 */
std::vector<Worker> ImportCSV(std::string file_path);

#endif // EXCEL_H_

/* End of 'excel.h' file */