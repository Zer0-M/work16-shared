#include "shared.h"

int main(){
    key_t key;
    int shmid;
    int* status=malloc(sizeof(int));

    key = ftok("/key", 'R');
    shmid = shmget(key, 200, 0644 | IPC_CREAT);
    char *shaddress=shmat(shmid,0,0);
    if(*shaddress == -1){
        printf("%s\n",strerror(errno));
    }
    if(!strcmp(shaddress,"")){
        printf("segment created\n");
    }
    else{
        printf("data : %s\n",shaddress);
    }
    char * yn1=malloc(sizeof(char));
    printf("Do you want to change data(Y/N):");
    fgets(yn1,5,stdin);
    yn1[strlen(yn1)-1]='\0';
    if(!strcmp(yn1,"Y")){
        printf("Enter new data:");
        fgets(shaddress,200,stdin);
        shaddress[strlen(shaddress)-1]='\0';
    }
    char * yn2=malloc(sizeof(char));
    printf("Do you want to delete the segment(Y/N):");
    fgets(yn2,5,stdin);
    yn2[strlen(yn2)-1]='\0';
    if(!strcmp(yn2,"Y")){
        shmctl(shmid,IPC_RMID, NULL);
    }
    free(yn1);
    free(yn2);
}