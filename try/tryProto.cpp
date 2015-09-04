/*************************************************************************
    > File Name: tryProto.cpp
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 06 Jan 2015 06:29:16 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include"msg.pb.h"
#include<fstream>
using namespace std;

int main()
{
	hello h;
	h.set_id(1);
	h.set_str("wuyilun");

	fstream output("./log", ios::out | ios::trunc | ios::binary);

	if(!h.SerializeToOstream(&output)){
		cerr << "Failed to write msg." << endl;
		return -1;
	}
	return 0;
}

