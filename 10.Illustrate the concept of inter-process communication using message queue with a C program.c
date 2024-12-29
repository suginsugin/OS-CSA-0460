#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_TEXT 100

struct message {
    long msg_type;
    char text[MAX_TEXT];
};

int main() {
    key_t key;
    int msgid;
    struct message msg;

    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);

    msg.msg_type = 1;
    strcpy(msg.text, "Hello, this is a message!");

    msgsnd(msgid, &msg, sizeof(msg), 0);
    printf("Message sent: %s\n", msg.text);

    msgrcv(msgid, &msg, sizeof(msg), 1, 0);
    printf("Message received: %s\n", msg.text);

    msgctl(msgid, IPC_RMID, NULL);
    return 0;
}
