/* FILE NAME:   worker.cpp
 * PURPOSE:     Worker class implementation.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#include "worker.h"

#include <iostream>

// Default constructor
Worker::Worker(void) {}

/* Worker class constructor.
 * ARGUMENTS:
 *     - worker's ID:
 *           int worker_id;
 *     - worker's name:
 *           std::string worker_name;
 *     - worker's specification:
 *           int worker_spec;
 *     - worker's state:
 *           WorkerState worker_state;
 *     - worker's type:
 *           WorkerType worker_type;
 */
Worker::Worker(int worker_id, std::string worker_name, int worker_spec, WorkerState worker_state, WorkerType worker_type) {
    this->worker_id_ = worker_id;
    this->worker_name_ = worker_name;
    this->worker_spec_ = worker_spec;
    this->worker_state_ = worker_state;
    this->worker_type_ = worker_type;
} /* End of 'Worker' function */

/* Get worker's ID function.
 * ARGUMENTS: None.
 * RETURNS:
 *     (int) worker's ID.
 */
int Worker::GetWorkerID(void) {
    return this->worker_id_;
} /* End of 'GetWorkerID' function */

/* Get worker's name function.
 * ARGUMENTS: None.
 * RETURNS:
 *     (std::string) worker's name.
 */
std::string Worker::GetWorkerName(void) {
    return this->worker_name_;
} /* End of 'GetWorkerName' function */

/* Get worker's specification function.
 * ARGUMENTS: None.
 * RETURNS:
 *     (int) worker's specification.
 */
int Worker::GetWorkerSpecification(void) {
    return this->worker_spec_;
} /* End of 'GetWorkerSpecification' function */

/* Get worker's state function.
 * ARGUMENTS: None.
 * RETURNS:
 *     (WorkerState) worker's state.
 */
Worker::WorkerState Worker::GetWorkerState(void) {
    return this->worker_state_;
} /* End of 'GetWorkerState' function */

/* Get worker's type function.
 * ARGUMENTS: None.
 * RETURNS:
 *     (WorkerType) worker's type.
 */
Worker::WorkerType Worker::GetWorkerType(void) {
    return this->worker_type_;
} /* End of 'GetWorkerType' function */

/* Set worker's ID function.
 * ARGUMENTS:
 *     - worker's ID:
 *           int worker_id;
 * RETURNS: None.
 */
void Worker::SetWorkerID(int worker_id) {
    this->worker_id_ = worker_id;
} /* End of 'SetWorkerID' function */

/* Set worker's name function.
 * ARGUMENTS:
 *     - worker's name:
 *           std::string worker_name;
 * RETURNS: None.
 */
void Worker::SetWorkerName(std::string worker_name) {
    this->worker_name_ = worker_name;
} /* End of 'SetWorkerName' function */

/* Set worker's specification function.
 * ARGUMENTS:
 *     - worker's specification:
 *           int worker_spec;
 * RETURNS: None.
 */
void Worker::SetWorkerSpecification(int worker_spec) {
    this->worker_spec_ = worker_spec;
} /* End of 'SetWorkerSpecification' function */

/* Set worker's state function.
 * ARGUMENTS:
 *     - worker's state:
 *           WorkerState worker_state;
 * RETURNS: None.
 */
void Worker::SetWorkerState(WorkerState worker_state) {
    this->worker_state_ = worker_state;
} /* End of 'SetWorkerState' function */

/* Set worker's type function.
 * ARGUMENTS:
 *     - worker's type:
 *           WorkerType worker_type;
 * RETURNS: None.
 */
void Worker::SetWorkerType(WorkerType worker_type) {
    this->worker_type_ = worker_type;
} /* End of 'SetWorkerType' function */

/* Print worker function.
 * ARGUMENTS:
 *     - output stream reference:
 *           std::ostream &out;
 *     - worker reference:
 *           Worker &w;
 * RETURNS:
 *     (std::ostream &) output stream reference.
 */
std::ostream & operator<<(std::ostream &out, Worker &w) {
    // Print all worker's fields
    out << w.GetWorkerID() << "\t" << w.GetWorkerName() << "\t"
        << w.GetWorkerSpecification() << "\t" << (int)w.GetWorkerState();

    // Return output stream reference
    return out;
} /* End of 'operator<<' function */

/* End of 'worker.cpp' file */