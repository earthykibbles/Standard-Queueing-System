#pragma once

#include <iostream>
#include "client.h"


void Client::arrive(std::queue<Client>& clientqueue) {
	clientqueue.push(*this);
}