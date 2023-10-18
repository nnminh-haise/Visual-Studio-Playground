#include "DataTypes.h"


Sex::Sex(int sex) {
	this->data = sex;
}

void Sex::setSex(int sex) {
	this->data = sex;
}

std::string Sex::toString(bool vn) {
	switch (this->data) {
		case (0): return vn ? "NAM" : "MALE";
		case (1): return vn ? "NU" : "MALE";
	}
	return "";
}

Sex& Sex::operator=(SEX sex) { // TODO: insert return statement here
	return *this;
}
