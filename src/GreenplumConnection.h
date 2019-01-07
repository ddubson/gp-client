#include <pqxx/connection>
#include <set>
#include "iostream"

#ifndef GP_CLIENT_GREENPLUMCONNECTION_H
#define GP_CLIENT_GREENPLUMCONNECTION_H

class GreenplumConnection {
public:
	GreenplumConnection(std::string hostname,
						std::string port,
						std::string databaseName,
						std::string userName,
						std::string password);
	~GreenplumConnection();
	std::set<std::string> listAllSchemas();

private:
	pqxx::connection* greenplumDriverConnection;
};

#endif //GP_CLIENT_GREENPLUMCONNECTION_H
