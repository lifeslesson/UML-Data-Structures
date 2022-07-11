/*Nathan Dynice
   Dr. M Geiger
   Data Structured summer 2022 */

   /***************************************************************
    * I BELIEVE YOU'LL NEED TO INCLUDE ALL OF THESE HEADER FILES; *
    *   FEEL FREE TO MODIFY THIS LIST AS NEEDED                   *
    ***************************************************************/
#include "QItem.h"
#include "Queue.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;
void readPrintFile(string userFile, Queue<QItem>& q1, Queue<QItem>& q2);
void runOrder(Queue<QItem>& q1, Queue<QItem>& q2);


int main() {
    Queue<QItem>expressLane;
    Queue<QItem>normalLane;

    string userFile;

    cout << "Enter input file name: ";
    getline(cin, userFile);
    cout << "Reading " << userFile << " ..." << endl;

    readPrintFile(userFile, normalLane, expressLane);
    runOrder(normalLane, expressLane);

    return 0;
}

/****************************************************************
 * VARIABLE DECLARATIONS SHOULD INCLUDE (BUT NOT BE LIMITED TO):
 *   - VARIABLES TO READ FROM THE FILE (INPUT STREAM, STRING FOR NAME,
 *       ETC.)
 *   - TWO QUEUES REPRESENTING THE TWO LANES YOU'RE MODELING
 *   - AT LEAST ONE TEMPORARY QItem VARIABLE TO STORE USER INPUT
 *       BEFORE ADDING IT TO EACH "LANE"
 *       (YOU MAY WANT A SECOND TEMP VARIABLE SO YOU CAN USE THE
 *        TEMP VARIABLES TO REPRESENT THE CUSTOMERS YOU'RE
 *        SERVING, AND HAVE THE QUEUES JUST HOLD WAITING CUSTOMERS)
 *   - A VARIABLE TO COUNT TIME
 *   - SOMETHING TO TRACK (1) WHETHER YOU'RE SERVING A CUSTOMER FROM
 *        EACH QUEUE AND (2) HOW LONG THAT CUSTOMER HAS LEFT
 * ***************************************************************/

 /*****************************************************************
  * START WITH FILE HANDLING AS DESCRIBED IN THE SPEC
  *   (THE TEST CASES ARE DESIGNED SO YOU CAN TEST THE FILE HANDLING
  *    WITHOUT IMPLEMENTING ANYTHING ELSE IN THE REST OF THE PROGRAM!)
  * ***************************************************************/

  /*****************************************************************
   * THEN, ADD THE LOOP THAT TRACKS TIME AND HANDLES CUSTOMER SERVICE
   * ***************************************************************/


void readPrintFile(string userFile, Queue<QItem>& q1, Queue<QItem>& q2) {
    QItem tempInfo;
    ifstream inFS;
    string neLane;
    char laneLetter;
    unsigned int arrivalTime, serviceTime, linePosition;

    linePosition = 0;

    inFS.open(userFile);
    while (1) {
        inFS >> laneLetter;
        if (laneLetter == 'E') {
            ++linePosition;
            neLane = "express";
            tempInfo.setCustomerNumber(linePosition);
            inFS >> arrivalTime;
            tempInfo.setArrivalTime(arrivalTime);
            inFS >> serviceTime;
            tempInfo.setServiceTime(serviceTime);
            q2.enqueue(tempInfo);
        }
        if (laneLetter == 'N') {
            ++linePosition;
            neLane = "normal";
            tempInfo.setCustomerNumber(linePosition);
            inFS >> arrivalTime;
            tempInfo.setArrivalTime(arrivalTime);
            inFS >> serviceTime;
            tempInfo.setServiceTime(serviceTime);
            q1.enqueue(tempInfo);

        }
        cout << "Customer " << linePosition << " to " << neLane << " lane  (A = " << arrivalTime << ", S = " << serviceTime << ")" << endl;

        if (inFS.eof()) {
            cout << "Done reading " << userFile << endl;
            break;
        }
    }
    inFS.close();
}

void runOrder(Queue<QItem>& q1, Queue<QItem>& q2) {
    unsigned int sTime, normalTime, expressTime, nServiceTime, eServiceTime;
    sTime = 1;
    normalTime = 0;
    expressTime = 0;
    nServiceTime = 0;
    eServiceTime = 0;

    while (!q1.empty() || !q2.empty()) {
        if (normalTime == 0 && q1.getFront().getArrivalTime() <= sTime && nServiceTime == 0) {
            if (!q1.empty()) {
                cout << "T=" << sTime << ":Serving customer " << q1.getFront().getCustomerNumber() << " in normal Lane" << endl;
                normalTime = q1.getFront().getServiceTime();
                nServiceTime = 1;
            }
        }
        else {
            if (expressTime == 0 && q2.getFront().getArrivalTime() <= sTime && eServiceTime == 0) {
                if (!q2.empty()) {
                    cout << "T=" << sTime << ":Serving customer " << q2.getFront().getCustomerNumber() << " in express Lane" << endl;
                    expressTime = q2.getFront().getServiceTime();
                    eServiceTime = 1;
                }
            }
        }

        if (normalTime != 0) {
            --normalTime;
        }
        if (expressTime != 0) {
            --expressTime;
        }
        if (normalTime == 0 && nServiceTime == 1) {
            cout << "T=" << sTime << ": Done serving customer " << q1.getFront().getCustomerNumber() << " in normal Lane" << endl;
            nServiceTime = 0;
            q1.dequeue();
        }
        else {
            if (expressTime == 0 && eServiceTime == 1) {
                cout << "T=" << sTime << ": Done serving customer " << q2.getFront().getCustomerNumber() << " in express Lane" << endl;
                eServiceTime = 0;
                q2.dequeue();
            }
        }
        ++sTime;
    }
    cout << "Done serving all customers" << endl;
}