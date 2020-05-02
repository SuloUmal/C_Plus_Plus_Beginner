#ifndef GOOD_AID__
#define GOOD_AID__
#include <string>
#include <iostream>
#include "iGood.h"
#include "Error.h"
namespace aid {

	class Good : public iGood {
#define max_sku_length 7
#define max_unit_length 10
#define max_name_length 75
#define tax_rate 0.13
		char indicator;
		char itemSku[max_sku_length + 1];
		char goodUnit[max_unit_length + 1];
		char* goodPtr;
		int qntOnHand;
		int qntNeed;
		double priceNoTax;
		bool taxable;
		void setEmpty(char type = 'N');
		void set(const char* sku, const char* name, const char* unit, int numHand, bool taxApply, double pric, int numNeed);
	protected:
		Error errorState;
		void name(const char* name);
		const char* sku() const;
		const char* name() const;
		const char* unit() const;
		bool taxed() const;
		double itemPrice() const;
		double itemCost() const;
		void message(const char*);
		bool isClear() const;
	public:
		Good(char ind = 'N');
		Good(const char* sku, const char* name, const char* unit, int numHand = 0, bool taxApply = true, double pric = 0, int numNeed = 0);
		Good(const Good& copy);
		Good& operator=(const Good& copy);
		~Good();
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const iGood& object) const;
		int operator+=(int);

	};
	std::ostream& operator<<(std::ostream& os, const iGood& object);
	std::istream& operator>>(std::istream& is, iGood& object);
	double operator+=(double&, const iGood& object);
}
#endif