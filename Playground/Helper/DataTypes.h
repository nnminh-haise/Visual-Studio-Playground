#pragma once

#ifndef __DATA_TYPES__
#define __DATA_TYPES__

#include <string>
#include <vector>

const std::vector<std::string> firstNames = {
  "Anh",
  "Minh",
  "Linh",
  "Quang",
  "Huyen",
  "Tuan",
  "Lan",
  "Hoang",
  "Mai",
  "Dat",
  "Thao",
  "Vinh",
  "Thuy",
  "Duc",
  "Ngoc",
  "Phuong",
  "Sang",
  "Nga",
  "Khanh",
  "Hieu"
};

const std::vector<std::string> middleNames = {
		"Van",
		"Thanh",
		"Ngoc",
		"Bao",
		"Xuan",
		"Khanh",
		"Hoai",
		"Thien",
		"Nhu",
		"Minh"
};

const std::vector<std::string> lastNames = {
		"Nguyen",
		"Tran",
		"Le",
		"Pham",
		"Hoang",
		"Do",
		"Vo",
		"Ngo",
		"Dang",
		"Huynh"
};


#define MALE 0
#define FEMALE 1
#define SEX int
struct Sex {
	Sex(int sex);

	void setSex(int sex);

	std::string toString(bool vn = false);

private:
	Sex& operator=(SEX sex);

private:
	int data;
};

#endif // !__DATA_TYPES__


