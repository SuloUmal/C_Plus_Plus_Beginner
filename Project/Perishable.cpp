#include "Perishable.h"
#include "Good.h"
#include "Date.h"

using namespace std;

namespace aid
{
	Perishable::Perishable() : Good('P')
	{
		errorState.clear();
	}

	std::fstream& Perishable::store(std::fstream& file, bool newLine) const
	{
		Good::store(file, false);
		file << "," << date;
		if (newLine) file << endl;
		return file;
	}
	std::fstream& Perishable::load(std::fstream& file)
	{
		Good::load(file);	
		date.read(file);
		file.ignore();
		return file;
	}
	std::ostream& Perishable::write(std::ostream& os, bool linear) const
	{
		Good::write(os, linear);
	if (isClear() && !isEmpty())
		{
			if (linear)
				os << date;
			else
			{
				os << endl << " Expiry date: ";
				os << date;
			}
		}
		return os;
	}
	std::istream& Perishable::read(std::istream& is)
	{
		is.clear();
		Good::read(is);
		errorState.clear();
		if (errorState.isClear())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			date.read(is);
		}

		if (date.errCode() == CIN_FAILED)
		{

			errorState.message("Invalid Date Entry");
		}

		if (date.errCode() == YEAR_ERROR)
		{
			errorState.message("Invalid Year in Date Entry");
		}

		if (date.errCode() == MON_ERROR)
		{
			errorState.message("Invalid Month in Date Entry");
		}

		if (date.errCode() == DAY_ERROR)
		{
			errorState.message("Invalid Day in Date Entry");
		}

		if (date.errCode() == PAST_ERROR)
		{
			errorState.message("Invalid Expiry in Date Entry");
		}

		if (date.errCode() != NO_ERROR)
		{
			is.setstate(std::ios::failbit);
		}

		return is;
	}

	const Date& Perishable::expiry() const
	{
		return date;
	}

	iGood* CreateProduct(char tag) {
		if (tag == 'N' || tag == 'n') return new Good();
		if (tag == 'P' || tag == 'p') { return new Perishable(); }
		else { return nullptr; }
	}
}