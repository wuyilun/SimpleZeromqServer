/*************************************************************************
    > File Name: tryConnection.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 09 Jan 2015 05:44:10 AM CST
 ************************************************************************/

#include<iostream>
#include"connectPSQL.hpp"
using namespace std;

int main()
{
	connectPSQL *c = connectPSQL::createConnection();
	string sql = "create table company5226(id int, age int);"; 
	c->execSql(sql);
	c->commitSql();
	c->disconnect();
}

