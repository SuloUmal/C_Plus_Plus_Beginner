#ifndef CONTACT_HELPER
#define CONTACT_HELPER
namespace sict {
	const int MAX_CHAR = 20;

	class Contact {
		char name[MAX_CHAR];
		long long* phoneList;
		int size;

	public:
		Contact();
		Contact(const char*  , const long long*  , int );
		Contact(const Contact& objectCopy);
		Contact& operator=(const Contact& rhs);
		Contact& operator+=(long long number);
		bool isEmpty() const;
		void display() const;
		~Contact();
	};
}

#endif