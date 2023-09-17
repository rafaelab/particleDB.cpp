#include "particleDB/database.h"


namespace particleDB {


/****************************************************************************************/
Database::Database(bool initialiseDecays) {
	initTable();
	if (initialiseDecays)
		initDecayTable();
}

Database::Database(std::vector<int> particles, bool initialiseDecays) {
	initTable(particles);
	if (initialiseDecays)
		initDecayTable(particles);
}

Database::~Database() {
}

void Database::initTable(std::vector<int> particles) {
	std::string filename = getDataPath("particle2022.csv");
	std::ifstream infile(filename.c_str());
	if (!infile.good())
		throw std::runtime_error("Problem loading table of particle properties: " + filename + ".");

	double massUnits = MeV / c_squared;
	double widthUnits = MeV;
	double chargeUnits = eplus / 3;  // 3 from scikit-hep convention
	std::unordered_map<std::string, float> isospinDict;
	isospinDict[""] = -100;
	isospinDict["?"] = -200;
	isospinDict["0"] = 0.;
	isospinDict["1"] = 1.;;
	isospinDict["2"] = 2.;
	isospinDict["1/2"] = 0.5;
	isospinDict["3/2"] = 1.5;
	isospinDict["5/2"] = 2.5;

	int lineCounter = 0;
	std::string line;
	while (std::getline(infile, line)) {
		if (line.find('#') != std::string::npos)
			continue;

		std::stringstream lineStream(line);

		std::string entry;
		std::vector<std::string> entries;
		while (std::getline(lineStream, entry, ',')) {
			entries.push_back(entry);
		}

		if (particles.size() == 0 || std::find(particles.begin(), particles.end(), std::stoi(entries[0])) != particles.end()) {
			Particle *particle = new Particle();
			particle->setId(std::stoi(entries[0]));
			particle->setMass(std::stod(entries[1]) * massUnits);
			particle->setMassUncertaintyUpper(std::stod(entries[1]) * massUnits);
			particle->setMassUncertaintyLower(std::stod(entries[2]) * massUnits);
			particle->setWidth(std::stod(entries[4]) * widthUnits);
			particle->setWidthUncertaintyUpper(std::stod(entries[5]) * widthUnits);
			particle->setWidthUncertaintyLower(std::stod(entries[6]) * widthUnits);
			particle->setIsospin(isospinDict.at(entries[7]));
			particle->setParityG(std::stoi(entries[8]));
			particle->setParityP(std::stoi(entries[9]));
			particle->setParityC(std::stoi(entries[10]));
			particle->setAntiparticleFlag(entries[11][0]);
			particle->setCharge(std::stod(entries[12]) * chargeUnits);
			particle->setRank(std::stoi(entries[13]));
			particle->setStatus(std::stoi(entries[14]));
			particle->setNamePDG(entries[15]);
			particle->setQuarks(entries[16]);
			particle->setNameTeX(entries[17]);
			particle->setLifetime(h_planck / (2. * M_PI) / particle->getWidth());
			particle->setLifetimeUncertaintyUpper(h_planck / (2. * M_PI) / (particle->getWidth() * particle->getWidth()) * particle->getWidthUncertaintyUpper());
			particle->setLifetimeUncertaintyLower(h_planck / (2. * M_PI) / (particle->getWidth() * particle->getWidth()) * particle->getWidthUncertaintyLower());

			particleMap[particle->getId()] = *particle;
		}

		lineCounter++;
	}
}

void Database::initDecayTable(std::vector<int> particles) {
	std::string filename = getDataPath("particleDecays.csv");
	std::ifstream infile(filename.c_str());
	if (!infile.good())
		throw std::runtime_error("Problem loading table of particle decays: " + filename + ".");

	int lineCounter = 0;
	std::string line;
	while (std::getline(infile, line)) {
		if (line.find('#') != std::string::npos)
			continue;

		std::stringstream lineStream(line);

		std::string entry;
		std::vector<std::string> entries;
		while (std::getline(lineStream, entry, ',')) {
			entries.push_back(entry);
		}

		if (particles.size() == 0 || std::find(particles.begin(), particles.end(), std::stoi(entries[0])) != particles.end()) {
			int primary = std::stoi(entries[0]);
			double branchingRatio = std::stod(entries[1]);
			std::vector<int> secondaries;
			for (size_t i = 2; i < entries.size(); i++) {
				secondaries.push_back(std::stod(entries[i]));
			}
			particleMap[primary].addDecayChannel(branchingRatio, secondaries);
		}

		lineCounter++;
	}

}

Particle Database::particleFromId(const int& id) const {
	return find(id);
}

Particle Database::find(const int& id) const {
	if (! particleExists(id))
		throw std::runtime_error("Cannot retrieve inexistent particle with id " + std::to_string(id) + ".");

	std::unordered_map<int, Particle>::const_iterator it = particleMap.find(id);
	return (*it).second;
}

bool Database::particleExists(const int& id) const {
	// std::unordered_map<int, Particle>::const_iterator it = particleMap.find(id);
	// if (it == particleMap.end())
	// 	return false;

	// return true;
	return tableContains(particleMap, id);
}

void Database::remove(const int& id) {
	if (! particleExists(id))
		throw std::runtime_error("Cannot retrieve inexistent particle with id " + std::to_string(id) + ".");

	particleMap.erase(id);
}

std::unordered_map<int, Particle> Database::getParticleMap() const {
	return particleMap;
}

Particle Database::operator[](const int& id) {
	std::unordered_map<int, Particle>::const_iterator it = particleMap.find(id);
	return (*it).second;
}




} // namespace