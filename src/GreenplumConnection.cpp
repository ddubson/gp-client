#include "GreenplumConnection.h"
#include "pqxx/pqxx"

using namespace std;

GreenplumConnection::GreenplumConnection(string hostname,
										 string port,
										 string databaseName,
										 string userName,
										 string password) {
	pqxx::connection C("dbname = "
					   + databaseName + " user = "
					   + userName + " password = "
					   + password + " hostaddr = "
					   + hostname + " port = "
					   + port);
	this->greenplumDriverConnection = &C;

	if (this->greenplumDriverConnection->is_open()) {
		cout << "Opened Greenplum DB: " << this->greenplumDriverConnection->dbname() << endl;
	} else {
		cout << "Can't open database" << endl;
	}
}

GreenplumConnection::~GreenplumConnection() {
	greenplumDriverConnection->disconnect();
	cout << "Disconnected from " << greenplumDriverConnection->dbname() << endl;
}

std::set<std::string> GreenplumConnection::listAllSchemas() {
	std::set<std::string> setOfSchemas;
	try {
		pqxx::work w(*greenplumDriverConnection);

		pqxx::result schemasResult = w.exec("select nspname from pg_catalog.pg_namespace;");
		w.commit();

		for (const auto &i : schemasResult) {
			setOfSchemas.insert(i[0].c_str());
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return setOfSchemas;
}