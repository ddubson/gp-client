#include <iostream>
#include "GreenplumConnection.h"

using namespace std;

int main(int argc, char *argv[]) {
	string host = argv[1];
	string port = argv[2];
	string dbName = argv[3];
	string username = argv[4];
	string password = argv[5];

	auto *connection = new GreenplumConnection(host, port, dbName, username, password);
	std::set<std::string> setOfSchemas = connection->listAllSchemas();
	cout << "Schemas" << endl << endl;
	cout << "Size " << setOfSchemas.size();
	for (const auto &setOfSchema : setOfSchemas)
		std::cout << setOfSchema << endl;

	cout << endl;
	return 0;
}