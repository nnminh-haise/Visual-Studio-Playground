#include <iostream>
#include <string>
#include <format>
#include <fstream>
#include "Functions/rndlib.hpp"
#include "Helper/Helper.h"

struct Record {
	std::string makh;
	std::string cmnd;
	std::string ho;
	std::string ten;
	Sex gioitinh = MALE;
	Date ngaysinh;
	std::string diachi;
	std::string sdt;
	std::string email;
	std::string masothue;

	Record() {}

	void setTableName(std::string name) {
		this->tableName = name;
	}

	std::string getTableName() {
		return this->tableName;
	}

	static std::string surroundBySingleQuote(std::string target) {
		return std::format("'{}'", target);
	}

	std::string toString() {
		return "(" +
			surroundBySingleQuote(makh) + ", " +
			surroundBySingleQuote(cmnd) + ", " +
			"N" + surroundBySingleQuote(ho) + ", " +
			"N" + surroundBySingleQuote(ten) + ", " +
			"N" + surroundBySingleQuote(gioitinh.toString()) + ", " +
			surroundBySingleQuote(ngaysinh.toString()) + ", " +
			surroundBySingleQuote(diachi) + ", " +
			surroundBySingleQuote(sdt) + ", " +
			surroundBySingleQuote(email) + ", " +
			surroundBySingleQuote(masothue) + ")";
	}

private:
	std::string tableName;
};

Record generate() {
	Record record;

	record.makh = "KH" + Random::String(8, "1234567890");
	record.cmnd = Random::String(10, "1234567890");
	record.ho = lastNames[Random::integer(0, (int)lastNames.size() - 1)] + " " +
				middleNames[Random::integer(0, (int)middleNames.size() - 1)];
	record.ten = firstNames[Random::integer(0, (int)firstNames.size() - 1)];
	record.gioitinh.setSex(Random::integer(0, 1));
	record.ngaysinh = Date::randomDate();
	record.ngaysinh.setFormat(Date::Format::YYYYMMDD);
	record.diachi = " ";
	record.sdt = Random::String(10, "1234567890");
	record.email = Random::String(10, "qwertyuiopasdfghjklzxcvbnm1234567890") + "@gamil.com";
	record.masothue = Random::String(10, "1234567890");

	return record;
}

void globalSetup();

int main() {
	globalSetup();

	std::ofstream fileOut("query.sql");

	Record record;
	record.setTableName("KHACHHANG");

	int rep = 20;
	std::string query{};
	while (rep--) {
		query = std::format("INSERT INTO {}", record.getTableName());
		fileOut << query << std::endl;
		Record record = generate();
		fileOut << "Values " + record.toString() << std::endl;
	}

	return 0;
}

void globalSetup() {
	srand(time(NULL));
}
