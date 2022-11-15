/* FILE NAME:   worker.h
 * PURPOSE:     Worker class declaration.
 * PROGRAMMERS: Kononov Svyatoslav,
 *              Matveev Yaroslav,
 *              Rybkin Ivan.
 * LAST UPDATE: 13.11.2022
 */

#ifndef WORKER_H_
#define WORKER_H_

#include <string>

// Worker class
class Worker {

public:

    // Worker status
    enum WorkerState {
        healthy,
        sick,
        holidayPaid,
        holidayUnpaid
    };

    // Worker type
    enum WorkerType {
        day,
        night
    };

private:

    int worker_id_ = 0;
    std::string worker_name_ = "";
    int worker_spec_ = 22;
    WorkerState worker_state_ = healthy;
    WorkerType worker_type_ = night;

public:

    // Default constructor.
    Worker(void);

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
    Worker(int worker_id, std::string worker_name, int worker_spec, WorkerState worker_state, WorkerType worker_type);

    /* Get worker's ID function.
     * ARGUMENTS: None.
     * RETURNS:
     *     (int) worker's ID.
     */
    int GetWorkerID(void);

    /* Get worker's name function.
     * ARGUMENTS: None.
     * RETURNS:
     *     (std::string) worker's name.
     */
    std::string GetWorkerName(void);

    /* Get worker's specification function.
     * ARGUMENTS: None.
     * RETURNS:
     *     (int) worker's specification.
     */
    int GetWorkerSpecification(void);

    /* Get worker's state function.
     * ARGUMENTS: None.
     * RETURNS:
     *     (WorkerState) worker's state.
     */
    WorkerState GetWorkerState(void);

    /* Get worker's type function.
     * ARGUMENTS: None.
     * RETURNS:
     *     (WorkerType) worker's type.
     */
    WorkerType GetWorkerType(void);

    /* Set worker's ID function.
     * ARGUMENTS:
     *     - worker's ID:
     *           int worker_id;
     * RETURNS: None.
     */
    void SetWorkerID(int worker_id);

    /* Set worker's name function.
     * ARGUMENTS:
     *     - worker's name:
     *           std::string worker_name;
     * RETURNS: None.
     */
    void SetWorkerName(std::string worker_name);

    /* Set worker's specification function.
     * ARGUMENTS:
     *     - worker's specification:
     *           int worker_spec;
     * RETURNS: None.
     */
    void SetWorkerSpecification(int worker_spec);

    /* Set worker's state function.
     * ARGUMENTS:
     *     - worker's state:
     *           WorkerState worker_state;
     * RETURNS: None.
     */
    void SetWorkerState(WorkerState worker_state);

    /* Set worker's type function.
     * ARGUMENTS:
     *     - worker's type:
     *           WorkerType worker_type;
     * RETURNS: None.
     */
    void SetWorkerType(WorkerType worker_type);

    // Friendly standard output operator
    friend std::ostream & operator<<(std::ostream &out, Worker &w);
}; /* End of 'Worker' class */

#endif // WORKER_H_

/* End of 'worker.h' file */