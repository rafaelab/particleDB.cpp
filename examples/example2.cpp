#include "particleDB.h"

#include <iostream>
#include <vector>

using namespace particleDB;


int main() {
	
	// read database for selected particles
	std::vector<int> pIds = {13, 15, 211, 111};
	Database* db = new Database(pIds);


	// test retrieving particle properties
	Particle p1 = db->getParticleFromId(211);
	std::cout << p1 << std::endl;

	try { // we expect an exception
		Particle p2 = db->getParticleFromId(11);
	} catch (...) {
		std::cout << "There is not particle with id 11 in the database. An error would be thrown." << std::endl;
	}


	return 0;
}