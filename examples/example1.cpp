#include "particles.h"

#include <iostream>
#include <vector>

using namespace particles;


int main() {
	// read database
	Database* db = new Database();

	// test retrieving particle properties
	Particle p = db->particleFromId(211);
	std::cout << p << std::endl;

	// test retrieving particle decay channels
	bool decayData = p.isDecayDataAvailable();
	if (! decayData)
		std::cout << "No decay data available for this particle." << std::endl;
	std::cout << "Number of decay channels: " << p.numberOfDecayChannels() << std::endl;

	for (size_t i = 0; i < p.numberOfDecayChannels(); i++) {
		double br = p.getDecayBranchingRatioForChannel(i);
		std::vector<int> secs = p.getDecayProductsForChannel(i);
		std::cout << br << " "; 
		for (size_t j = 0; j < secs.size(); j++) {
			std::cout << secs[j] << " ";
		}
		std::cout << std::endl;
	}


	return 0;
}