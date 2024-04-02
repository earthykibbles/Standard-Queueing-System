#pragma once

#include <iostream>
#include "client.h"


void Client::arrive(std::queue<Client>& clientqueue) {
	clientqueue.push(*this);
}

void Client::doneWaiting(int &time) {
	this->timequeue = time - this->timearrived;
}

void Client::beingServed() {
	this->timeserved++;
}

void Client::served(int& time) {
	this->timetaken = (int) this->timeserved + (int) this->timequeue;
	std::cout << "Time Spent in Queue: " << this->timetaken << "\n";
}