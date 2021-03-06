//  Hello World client
//  Connects REQ socket to tcp://localhost:5559
//  Sends "Hello" to server, expects "World" back

#include "msg.pb.h"
#include "zhelpers.h"
#include <string>
using namespace std;

int main (void)
{
    void *context = zmq_ctx_new ();
    hello msg1;
    msg1.set_id(101);
    msg1.set_str("hello wuyilun");
	string msg_send;
	msg1.SerializeToString(&msg_send);

    //  Socket to talk to server
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5559");

    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
		char *s = (char *)msg_send.c_str();
        s_send (requester, s); 
        char *string = s_recv (requester);
        printf ("Received reply %d [%s]\n", request_nbr, string); 
        free (string);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}
