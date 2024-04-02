#include <iostream>
#include <queue>
#include <vector>
#include <random>
#include "client/client.h"
#include "server/server.h"

int main()
{
	int systime = 1000;
	std::queue<Client> clientqueue;


	// Generate Servers
	int totalservers = 5;
	std::vector<Server> servers;

	for (int i = 0; i < totalservers; i++) {
		Server server;
		servers.push_back(server);
	}


	while (systime != 0) {

		// Generate clients in a poisson distribution
		std::random_device rd;
		std::mt19937 gen(rd());
		double mean = 0.0833;
		std::poisson_distribution<int> poisson_dist(mean);

		int value = poisson_dist(gen);

		for (int i = 0; i < value; i++) {
			Client client;
			client.arrive(clientqueue);
		}

		if (clientqueue.size() > servers.size()) {
			for (auto& server : servers) {
				if (server.isServerBusy()) {
					server.serve();
				}
				else {
					server.callNext(clientqueue);
				}
			}
		}

		
		systime--;
	}
	std::cout << "Current Queue Size" << "\t" << clientqueue.size() << "\n";

	for (auto& server : servers) {
		std::cout << "Total clients served" <<"\t" << server.clients_served << "\n";
	}
}
