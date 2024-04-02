#pragma once

#include <iostream>
#include <string>
#include <queue>

class Client {
private:
	std::string id;
	int position;

public:
	int timearrived = 0;
	int timequeue = 0;
	int timeserved = 0;
	int timetaken = 0;

	Client(int &timearrived) :timearrived(timearrived) {};

	void arrive(std::queue<Client> &clientqueue);

	void doneWaiting(int& time);

	void beingServed();

	void served(int& time);
};