#pragma once
#include <iostream>
#include <queue>
#include "../client/client.h"

class Server {
private:
	std::string id;
	int position;
public:
	float time_busy;
	float time_idle;
	int clients_served = 0;
	int time_to_finish = 0;

	void callNext(std::queue<Client>& clientqueue);
	void determineTime();
	bool isServerBusy();
	void serve();
};
