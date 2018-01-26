#include <stdio.h>
int * queue;
int size;
int head;
int tail;

void initQ(int _size){
	size =_size;
	queue = (int*) malloc (sizeof(int)*size);
	head=0;
	tail =0;
}

bool insertQ (int data){
	if((tail+1)%size==head){
		return false;
	}
	queue[tail]=data;
	tail=(tail+1)%size;
	return true;
}

int delQ(){
	if (head==tail){	
		return -999;
	}
	int temp;
	temp =queue[head];
	head=(head+1)%size;
	return temp;
}

int main(int argc, char *argv[])
{
	initQ(10);	
	for(int i=1; i<=10; i++){
		insertQ(i);
	}
	int temp;
	for(;(temp=delQ())!=-999;)
	{
		printf("%d", temp);
	}
}




