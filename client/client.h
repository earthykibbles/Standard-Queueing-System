#pragma once

#include <iostream>
#include <string>
#include <queue>

class Client {
private:
	std::string id;
	int position;

public:
	bool busy;
	float timequeue = 0;
	float timetaken = 0;

	void arrive(std::queue<Client> &clientqueue);

	void served();
};