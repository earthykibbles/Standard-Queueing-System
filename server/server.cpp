#include "server.h"
#include <random>


void Server::callNext(std::queue<Client>& clientqueue, int& time) {
    client = &clientqueue.front();
    clientqueue.pop();

    client->doneWaiting(time);

    determineTime();
    
    this->clients_served++;
}

void Server::determineTime() {
    std::random_device rd;
    std::mt19937 gen(rd());

    double mean = 300.0;
    double stddev = 50.0;
    std::normal_distribution<double> normal_dist(mean, stddev);
    this->time_to_finish = normal_dist(gen);
}

bool Server::isServerBusy() {
    if (this->time_to_finish > 0) {
        this->time_busy++;
        return true;
    }
    else {
        this->time_idle++;
        return false;
    }
}

void Server::wrapTask(int& time) {
    client->served(time);
}

void Server::serve() {
    client->beingServed();
    //std::cout << "Still Busy! " << "\t" << this->time_to_finish << " Seconds left." << "\n";
    this->time_to_finish--;
}