#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
	string host = argv[1];
	string port = argv[2];
	string dbName = argv[3];
	string username = argv[4];
	string password = argv[5];

	connection C("dbname = "
				 + dbName + " user = "
				 + username + " password = "
				 + password + " hostaddr = "
				 + host + " port = "
				 + port);
	if (C.is_open()) {
		cout << "Opened database successfully: " << C.dbname() << endl;
	} else {
		cout << "Can't open database" << endl;
		return 1;
	}

	C.disconnect();
	return 0;
}