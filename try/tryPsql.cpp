
#include<iostream>
#include<pqxx/pqxx>
using namespace std;
using namespace pqxx;

int main(int argc, char* argv[])
{
	try{
		//connection C("dbname=exampledb user=dbuser_wuyilun password=woshiheike hostaddr=127.0.0.1 port=5432");
		connection *C = new connection("dbname=exampledb user=dbuser_wuyilun password=woshiheike hostaddr=127.0.0.1 port=5432");
		if(C->is_open()){
			cout << "Opened database successfully: " << C->dbname() << endl;
		}else{
			cout << "Can't open database" << endl;
			return 1;
		}
		string sql;
		sql =  "create table company2(" \
			   "id int primary key not null,"\
			   "name text not null,"\
			   "age int not null,"\
			   "salary real);"\
			   "create table company4444("\
			   "id int primary key not null,"\
			   "age int not null);";

		work *W = new work(*C);
		W->exec(sql);
		W->commit();
		cout << "Table created successfully" << endl;
		C->disconnect();
	}catch(const std::exception &e){
		cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}

