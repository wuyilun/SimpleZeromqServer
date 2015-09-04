//  Hello World worker
//  Connects REP socket to tcp://*:5560
//  Expects "Hello" from client, replies with "World"

#include "zhelpers.h"
#include "msg.pb.h"
//#include "connectPSQL.hpp"
#include <unistd.h>
#include <string>
using namespace std;

int main (void)
{
    void *context = zmq_ctx_new ();

    // Socket to talk to clients
    void *responder = zmq_socket (context, ZMQ_REP);
    zmq_connect (responder, "tcp://localhost:5560");

	// create database connection
    //connectPSQL *c = connectPSQL::createConnection();

    while (1) {
        // Wait for next request from client
        char *str = s_recv (responder);
		string recv_str = str;

		hello h_msg;
		h_msg.ParseFromString(recv_str);

		int i = 116;
		char is[10];
		if(h_msg.id() == 101)
	    {
			printf ("Received from message %d request: [%s]\n", h_msg.id(), h_msg.str().c_str());
			// 调用存储过程
//			sprintf(is, "%d", i);
//			string istr = is;
//			string sql = "select create_table_for_client(" + istr +");";
//			c->execSql(sql);
//			c->commitSql();
		}
		else if(h_msg.id() == 102)
		{
			printf("Received from message %d request: [%s]\n", h_msg.id(), h_msg.str().c_str());
			// 调用存储过程
//			sprintf(is, "%d", i);
//			string istr = is;
//			string sql = "select create_table_for_client(" + istr +");";
//			c->execSql(sql);
//			c->commitSql();
		}
		else
			printf ("Not Received from 101 message!");
        free (str);

        // Do some 'work'
        sleep (1);

        // Send reply back to client
		char s[] = "World";
        s_send (responder, s);
    }
	// 关闭连接
	//c->disconnect();
    // We never get here, but clean up anyhow
    zmq_close (responder);
    zmq_ctx_destroy (context);
    return 0;
}
