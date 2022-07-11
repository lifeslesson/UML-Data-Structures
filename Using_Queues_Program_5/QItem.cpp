#include "QItem.h"
#include "Queue.h"

#include <iostream>
#include <string>

using namespace std;


//String or int. possibly change
QItem::QItem() {
	cNum = 0;
	arrTime = 0;
	svcTime = 0;
}

QItem::QItem(unsigned int cNum, unsigned int arrTime, unsigned int svcTime) {
	cNum = cNum;
	arrTime = arrTime;
	svcTime = svcTime;
}

unsigned int QItem::getCustomerNumber() {
	return cNum;
}

unsigned int QItem::getArrivalTime() {
	return arrTime;
}

unsigned int QItem::getServiceTime() {
	return svcTime;
}

void QItem::setCustomerNumber(unsigned int num) {
	cNum = num;
}

void QItem::setArrivalTime(unsigned int num) {
	arrTime = num;
}

void QItem::setServiceTime(unsigned int num) {
	svcTime = num;
}