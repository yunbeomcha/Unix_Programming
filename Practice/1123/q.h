#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define QKEY            (key_t)011011
#define QPERM           0660 //permission
#define MAXOBN          50
#define MAXPRIOR        10

struct q_entry {
        long mtype;
        char mtext [MAXOBN+1];
}; //메세지 프로토타입

int init_queue(void) {

        int queue_id;
        key_t msq_key;

        //msq_key = ftok("keyfile", 1);
        if ((queue_id = msgget((key_t)011011, IPC_CREAT | QPERM)) == -1)
                perror("msgget failed");

        return (queue_id);
}

int proc_obj (struct q_entry *msg) {

        printf("\npriority: %ld name: %s\n", msg->mtype, msg->mtext);
}

