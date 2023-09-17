#include "particleDB.h"

#include <iostream>
#include <vector>

using namespace particleDB;


int main() {
	
	// read database
	Database* db = new Database();

	// test retrieving particle properties
	Particle p1 = db->particleFromId(211);
	std::cout << p1 << std::endl;

	// test retrieving particle properties
	Particle p2 = db->particleFromId(15);
	std::cout << p2 << std::endl;

	return 0;
}