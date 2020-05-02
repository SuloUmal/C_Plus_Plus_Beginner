#ifndef AID_IGOOD_H
#define AID_IGOOD_H
#include <iostream>
#include <fstream>
namespace aid
{
    class iGood
    {
    public:
        virtual std::fstream& store(std::fstream& file, bool newLine=true) const = 0;

        virtual std::fstream& load(std::fstream& file) = 0;

        virtual std::ostream& write(std::ostream& os, bool linear) const = 0;

        virtual std::istream& read(std::istream& is) = 0;

        virtual bool operator==(const char* identical) const = 0;

        virtual double total_cost() const = 0;

        virtual const char* name() const = 0;

        virtual void quantity(int qty) = 0;

        virtual int qtyNeeded() const = 0;

        virtual int quantity() const = 0;

        virtual int operator+=(int unit) = 0;

        virtual bool operator>(const iGood&) const = 0;

	virtual ~iGood() {};
    };

    std::ostream& operator<<(std::ostream& os, const iGood& object);

    std::istream& operator>>(std::istream& is, iGood& object);

    double operator+=(double& price, const iGood& object);

    iGood* CreateProduct(char tag);

}

#endif