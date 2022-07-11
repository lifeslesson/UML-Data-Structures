#ifndef QITEM_H
#define QITEM_H

#include <string>
using namespace std;

class QItem {
public:
    /**********************************************************************
     * MODIFY THIS CLASS AS YOU SEE FIT--MY SOLUTION USED THE DATA MEMBERS
     *   SHOWN BELOW AND HAD FUNCTIONS THAT ALLOWED ME TO MODIFY AND READ
     *   THEM AS NEEDED, BUT YOU MAY COME UP WITH SOMETHING DIFFERENT
     * ********************************************************************/

    QItem();
    QItem(unsigned int cNum, unsigned int arrTime, unsigned int svcTime);
    unsigned int getCustomerNumber();
    unsigned int getArrivalTime();
    unsigned int getServiceTime();
    void setCustomerNumber(unsigned int num);
    void setArrivalTime(unsigned int num);
    void setServiceTime(unsigned int num);

private:
    unsigned cNum;		// Customer number
    unsigned arrTime;	// Arrival time
    unsigned svcTime;	// Time required to service customer
};
#endif