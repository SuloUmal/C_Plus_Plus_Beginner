#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <memory>
#include <fstream>
#include <iomanip>
#include "Good.h"
#include "Error.h"
using namespace std;


namespace aid
{
	Good::Good(char name) {
		setEmpty(name);

	}

	Good::Good(const char* sku, const char* name, const char* unit, int numHand, bool taxApply, double pric, int numNeed) {
		set(sku, name, unit, numHand, taxApply, pric, numNeed);
	}

	//added new function for constructor
	void Good::set(const char* sku, const char* nam, const char* unit, int numHand, bool taxApply, double pric, int numNeed) {
		if (indicator == 'P'){ setEmpty('P');
		}
		else { setEmpty(); }
		strncpy(itemSku, sku, max_sku_length);
		strncpy(goodUnit, unit, max_unit_length);
		name(nam);
		qntOnHand = numHand;
		priceNoTax = pric;
		taxable = taxApply;
		qntNeed = numNeed;
	}
	//added new function for constructor
	void Good::setEmpty(char type) {
		indicator = type;
		itemSku[0] = '\0';
		goodUnit[0] = '\0';
		goodPtr = nullptr;
		qntOnHand = 0;
		qntNeed = 0;
		priceNoTax = 0;
		taxable = false;
	}

	Good::~Good()
	{
		delete[] goodPtr;
		goodPtr = nullptr;
	}
	Good::Good(const Good &copy)
	{
		int size = strlen(copy.goodPtr);

		indicator = copy.indicator;

		strncpy(itemSku, copy.itemSku, max_sku_length);
		itemSku[max_sku_length] = '\0';

		strncpy(goodUnit, copy.goodUnit, max_unit_length);
		goodUnit[max_unit_length] = '\0';

		qntOnHand = copy.qntOnHand;
		qntNeed = copy.qntNeed;
		priceNoTax = copy.priceNoTax;
		taxable = copy.taxable;

		if (copy.goodPtr != nullptr)
		{
			goodPtr = nullptr;
			goodPtr = new char[size];

			for (int i = 0; i < size; ++i)
			{
				goodPtr[i] = copy.goodPtr[i];
			}
			goodPtr[size] = '\0';
		}
	}

	void Good::name(const char* name)
	{
		if (name != nullptr)
		{
			int size = strlen(name);

			goodPtr = new char[size];
			for (int i = 0; i < size; ++i)
			{
				goodPtr[i] = name[i];
			}

			goodPtr[size] = '\0';
		}
	}
	const char* Good::name() const {
		return goodPtr;
	}
	const char* Good::sku() const {
		return itemSku;
	}
	const char* Good::unit() const {
		return goodUnit;
	}

	bool Good::taxed() const {
		return taxable;
	}

	double Good::itemPrice() const {
		return priceNoTax;
	}
	double Good::itemCost() const {
		return taxable ? priceNoTax + priceNoTax * tax_rate : priceNoTax;
	}
	void Good::message(const char* err) {
		return errorState.message(err);
	}
	bool Good::isClear() const {
		return errorState.isClear();
	}

	Good& Good::operator=(const Good &copy)
	{
		if (this != &copy)
		{
			indicator = copy.indicator;

			strncpy(itemSku, copy.sku(), max_sku_length);

			strncpy(goodUnit, copy.unit(), max_unit_length);

			qntOnHand = copy.qntOnHand;
			qntNeed = copy.qntNeed;
			priceNoTax = copy.priceNoTax;
			taxable = copy.taxable;

			if (copy.goodPtr != nullptr)
			{
				int length = strlen(copy.goodPtr);

				goodPtr = new char[length];
				for (int i = 0; i < length; ++i)
				{
					goodPtr[i] = copy.goodPtr[i];
				}
				goodPtr[length] = '\0';
			}
			else
			{	
				delete[] goodPtr;
				goodPtr = nullptr;
			}
		}

		return *this;
	}

	std::fstream& Good::store(std::fstream& file, bool newLine) const
	{
		file << indicator << "," << itemSku << "," << goodPtr << "," << goodUnit << "," << taxable << "," << priceNoTax << "," << qntOnHand << "," << qntNeed;
		if (newLine) file << endl;
		return file;
	}
	std::fstream& Good::load(std::fstream &file)
	{

		char itemSku[max_sku_length + 1];
		char name[max_name_length + 1];
		char goodUnit[max_unit_length + 1];
		int qntOnHand;
		int qntNeed;
		double priceNoTax;
		bool taxable;
		char ask;
		char throw_char;
		file.getline(itemSku, max_sku_length, ',');
		file.getline(name, max_sku_length, ',');
		file.getline(goodUnit, max_sku_length, ',');

		file >> ask;
		if (ask == '1')
		{
			taxable = true;
		}
		else if (ask == '0')
		{
			taxable = false;
		};
		file >> throw_char >> priceNoTax >> throw_char >> qntOnHand >> throw_char >> qntNeed >> throw_char;

		set(itemSku, name, goodUnit, qntOnHand, taxable, priceNoTax, qntNeed);

		return file;
	}
	std::ostream& Good::write(std::ostream &os, bool linear) const
	{
		if (errorState.isClear()) {
			if (!isEmpty()) {
				if (linear)
				{

					os << setw(max_sku_length) << left << itemSku << '|' << setw(20);
					if (goodPtr == nullptr) os << ""; else
						os << left << goodPtr << '|';
					os << setw(7) << right << fixed << setprecision(2) << itemCost() << '|'
						<< setw(4) << right << qntOnHand << '|'
						<< setw(10) << left << goodUnit << '|'
						<< setw(4) << right << qntNeed << '|';
				}
				else
				{
					os << " Sku: " << sku() << endl
						<< " Name (no spaces): " << goodPtr << endl
						<< " Price: " << itemPrice() << endl << " Price after tax: ";
					if (taxable) {
						os << itemCost() << endl;
					}
					else {
						os << "N/A"
							<< endl;
					}

					os << " Quantity on Hand: " << quantity() << " " << unit() << endl
						<< " Quantity needed: " << qtyNeeded();
				}
			}
		}
		else { os << errorState; }
		return os;
	}
	std::istream& Good::read(std::istream& is)
	{
		char itemSku[max_sku_length + 1];
		char goodPtr [max_name_length + 1];
		char goodUnit[max_unit_length + 1];
		int qntOnHand;
		int qntNeed;
		double priceNoTax;
		char choice;
		bool taxable;
		Error errorState;
		this->errorState.clear();
		cout << " Sku: ";
		is >> itemSku;

		cout << " Name (no spaces): ";
		is >> goodPtr;

		cout << " Unit: ";
		is >> goodUnit;

		cout << " Taxed? (y/n): ";
		is >> choice;
		if (choice != 'y' && choice != 'Y'&& choice != 'n'&& choice != 'N') {
			this->errorState.message("Only (Y)es or (N)o are acceptable");
			is.setstate(std::ios::failbit);
		}
		else
			if (choice == 'Y' || choice == 'y')
			{
				taxable = true;
			}
			else if (choice == 'N' || choice == 'n')
			{
				taxable = false;
			}
		if (!is.fail() && this->errorState.isClear()) {
			cout << " Price: ";
			is >> priceNoTax;
			if (is.fail()) {
				this->errorState.message("Invalid Price Entry");
				is.setstate(std::ios::failbit);
			}
		}
		if (!is.fail() && this->errorState.isClear()) {
			cout << " Quantity on hand: ";
			is >> qntOnHand;
			if (is.fail()) {
				this->errorState.message("Invalid Quantity Entry");
				is.setstate(std::ios::failbit);
			}
		}
		if (!is.fail() && this->errorState.isClear()) {
			cout << " Quantity needed: ";
			is >> qntNeed;
			if (is.fail()) {
				this->errorState.message("Invalid Quantity Needed Entry");
				is.setstate(std::ios::failbit);
			}
		}
		if (!is.fail() && this->errorState.isClear()) {
			set(itemSku, goodPtr, goodUnit, qntOnHand, taxable, priceNoTax, qntNeed);
		}
	
		return is;
	}

	bool Good::operator==(const char* compare) const {
		return strcmp(itemSku, compare) == 0;
	}

	double Good::total_cost() const {
		return itemCost()*qntOnHand;
	}
	void Good::quantity(int units)
	{
		qntOnHand = units;
	}
	bool Good::isEmpty() const {
		return strcmp(itemSku, "") == 0;
	}
	int Good::qtyNeeded() const
	{
		return qntNeed;
	}
	int Good::quantity() const
	{
		return qntOnHand;
	}
	bool Good::operator>(const char* itemSku) const {
		return strcmp(itemSku, "") == 1;
	}

	bool Good::operator>(const iGood& object) const {
		return strcmp(name(), object.name()) == 1;
	}
	int Good::operator+=(int add) {
		return qntOnHand += add;
	}

	std::ostream& operator<<(std::ostream& os, const iGood& object) {
		return object.write(os, true);
	}

	std::istream& operator>>(std::istream& is, iGood& object) {
		return object.read(is);
	}

	double operator+=(double& total, const iGood& object) {
		return total + object.total_cost();

	}
}