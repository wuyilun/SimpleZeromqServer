/*************************************************************************
    > File Name: connectPSQL.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 09 Jan 2015 05:33:23 AM CST
 ************************************************************************/

#include"connectPSQL.hpp"

connectPSQL *connectPSQL::instance = NULL;
connectPSQL *connectPSQL::createConnection()
{
	if(instance == NULL)	
		instance = new connectPSQL();
	else
		return instance;
}

connectPSQL::connectPSQL()
{
	c = new connection("dbname=exampledb user=dbuser_wuyilun password=woshiheike hostaddr=127.0.0.1 port=5432");
	if(c->is_open()){
		cout << "Opened database successfully: " << c->dbname() << endl;
		w = new work(*c);
	}else{
		cout << "Can't open database" << endl;
	}
}

void connectPSQL::execSql(string &s)
{
	w->exec(s);
	cout << "execute successfully!" << endl;
}

void connectPSQL::commitSql()
{
	w->commit();
}
