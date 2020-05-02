#ifndef AID_HELPER___
#define AID_HELPER___
namespace aid {
	class Error {
		char* msg;
		void set();
	public:
		Error& operator=(const Error& copy) = delete;
		Error(const Error& copy) = delete;
		explicit Error(const char* errorMessage = nullptr);
		virtual ~Error();
		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;

	};
	std::ostream& operator<<(std::ostream& os, const Error& obj);
}
#endif