
#include<iostream>
#include<pqxx/pqxx>
using namespace std;
using namespace pqxx;

class connectPSQL
{
	public:
		static connectPSQL *createConnection();
		static connectPSQL *instance;
		void disconnect(){
			if(instance != NULL){
				c->disconnect();
			}
		}
		void execSql(string &s);
		void commitSql();
	private:
		connectPSQL();
		connection *c;
		work *w;
};
