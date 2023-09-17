#include "particleDB/particle.h"


namespace particleDB {


Particle::Particle() {	
}

void Particle::setId(int i) {
	id = i;
}

void Particle::setMass(double m) {
	mass = m;
}

void Particle::setMassUncertaintyUpper(double dmu) {
	massErrorU = dmu;
}

void Particle::setMassUncertaintyLower(double dml) {
	massErrorL = dml;
}

void Particle::setWidth(double w) {
	width = w;
}

void Particle::setWidthUncertaintyUpper(double dwu) {
	widthErrorU = dwu;
}

void Particle::setWidthUncertaintyLower(double dwl) {
	widthErrorL = dwl;
}

void Particle::setLifetime(double t) {
	lifetime = t;
}

void Particle::setLifetimeUncertaintyUpper(double dtu) {
	lifetimeErrorU = dtu;
}

void Particle::setLifetimeUncertaintyLower(double dtl) {
	lifetimeErrorL = dtl;
}

void Particle::setIsospin(float i) {
	isospin = i;
}

void Particle::setParityC(uint8_t c) {
	parityC = c;
}

void Particle::setParityG(uint8_t g) {
	parityG = g;
}

void Particle::setParityP(uint8_t p) {
	parityP = p;
}

void Particle::setAntiparticleFlag(char anti) {
	antiparticleFlag = anti;
}

void Particle::setRank(uint8_t r) {
	rank = r;
}

void Particle::setStatus(char s) {
	status = s;
}

void Particle::setCharge(double q) {
	charge = q;
}

void Particle::setNamePDG(std::string s) {
	namePDG = s;
}

void Particle::setNameTeX(std::string s) {
	nameTeX = s;
}

void Particle::setQuarks(std::string s) {
	quarks = s;
}

void Particle::setDecayBranchingRatios(std::vector<double> br) {
	for (size_t i = 0; i < br.size(); i++) {
		decayBranchingRatios.push_back(br[i]);
	}
}

void Particle::setDecayProducts(std::vector<std::vector<int>> sec) {
	for (size_t i = 0; i < sec.size(); i++) {
		decayProducts.push_back(sec[i]);
	}
}

int Particle::getId() const{
	return id;
}

double Particle::getMass() const {
	return mass;
}

double Particle::getMassUncertaintyUpper() const {
	return massErrorU;
}

double Particle::getMassUncertaintyLower() const {
	return massErrorL;
}

double Particle::getWidth() const {
	return width;
} 

double Particle::getWidthUncertaintyUpper() const {
	return widthErrorU;
} 

double Particle::getWidthUncertaintyLower() const {
	return widthErrorL;
} 

double Particle::getLifetime() const {
	return lifetime;
} 

double Particle::getLifetimeUncertaintyUpper() const {
	return lifetimeErrorU;
} 

double Particle::getLifetimeUncertaintyLower() const {
	return lifetimeErrorL;
} 

double Particle::getCharge() const {
	return charge;
} 

uint8_t Particle::getParityC() const {
	return parityC;
} 

uint8_t Particle::getParityG() const {
	return parityG;
} 

uint8_t Particle::getParityP() const {
	return parityP;
} 

float Particle::getIsospin() const {
	return isospin;
} 

char Particle::getAntiparticleFlag() const {
	return antiparticleFlag;
}

uint8_t Particle::getRank() const {
	return rank;
}

char Particle::getStatus() const {
	return status;
}

std::string Particle::getQuarks() const {
	return quarks;
}

std::string Particle::getNamePDG() const {
	return namePDG;
}

std::string Particle::getNameTeX() const {
	return nameTeX;
}

std::vector<double> Particle::getDecayBranchingRatios() const {
	return decayBranchingRatios;
}

std::vector<std::vector<int>> Particle::getDecayProducts() const {
	return decayProducts;
}

void Particle::addDecayChannel(const double& br, const std::vector<int>& sec) {
	decayBranchingRatios.push_back(br);
	decayProducts.push_back(sec);
}

bool Particle::isUnstable() const {
	if (lifetime > 0 && lifetimeErrorL < lifetime && lifetime < std::numeric_limits<double>::max())
		return false;
	
	return true;
}

bool Particle::isStable() const {
	return ! isUnstable();
}

bool Particle::isDecayDataAvailable() const {
	if (decayBranchingRatios.size() > 0 && decayProducts.size() == decayBranchingRatios.size())
		return true;
	return false;
}

double Particle::getDecayBranchingRatioForChannel(const size_t& i) const {
	if (! isDecayDataAvailable()) {
		throw std::runtime_error("No decay data available for this particle.");
	}
	return decayBranchingRatios[i];
}

std::vector<int> Particle::getDecayProductsForChannel(const size_t& i) const {
	if (! isDecayDataAvailable()) {
		throw std::runtime_error("No decay data available for this particle.");
	}
	return decayProducts[i];
}

unsigned int Particle::numberOfDecayChannels() const {
	if (! isDecayDataAvailable()) {
		std::cout << "No decay data available for this particle." << std::endl;
		return 0;
	}

	return decayBranchingRatios.size();
}

std::ostream& operator<<(std::ostream& os, const Particle& p) {
	os << "Particle: " <<  p.getNamePDG() << "\n";
	os << "  . id = " << p.getId() << "\n";
	os << "  . charge = " << p.getCharge() / eplus << "  (" << p.getCharge() << " C)" << "\n";
	os << "  . mass = " << p.getMass() << " (+" << p.getMassUncertaintyUpper() << ", -" << p.getMassUncertaintyLower() << ") kg \n";
	if (p.getLifetime() < std::numeric_limits<double>::max())
		os << "  . lifetime = " << p.getLifetime() << " (+" << p.getWidthUncertaintyUpper() << ", -" << p.getWidthUncertaintyLower() << ") s \n";
	os << "  . representation TeX = " << "  ($" << p.getNameTeX() << ")$ "; 
	
	return  os;
}



} // namespace