#include <functions.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ArgC, char ** ArgV)
{
	
	int MyPriority = 0;
	int MyPid;
	int CheckPriority = 0;
	int MyTime = 0;
	int CheckTime = 0;
	int I, J, K;
	int numer;
	if(ArgC != 4)
	{
		printf("Uzycie: %s <priorytet tej aplikacji>\n", ArgV[0]);
		return 1;
	}
	
	MyPriority = atoi(ArgV[1]);
	MyPid = getpid();
	numer = atoi(ArgV[3]);
	
	if(MyPriority < 1 || MyPriority > 3)
	{
		printf("Zly typ");
		return 2;
	}
	if(MyPriority ==2 || MyPriority == 3)
		MyTime = atoi(ArgV[2]);

	setid(MyPid, MyPriority);
	printf("Ustawiony typ: %d \n",MyPriority);
	
	CheckPriority = getid(MyPid);
	printf("Sprawdzam Typ: %d\n",CheckPriority);
	
	if(CheckPriority==2)
	{
		if(MyTime >=1000)
			return 3;		
		settime(MyPid,MyTime);
		CheckTime=gettime(MyPid);
		printf("Ustawiony czas%d \n",CheckTime);	
	}
	if(CheckPriority==3)
	{
		settime(MyPid,MyTime);
		CheckTime=gettime(MyPid);		
		printf("Ustawiony czas%d\n",CheckTime);	
	}	
		
		


	
	for(I = 0; I < 10; I++)
	{
		for(J = 0; J < 65535 * 256; J++) 
			K=12*3%4;
		printf("== Proces o id: %d, czasie: %d, numerze nadania: %d wykonany w %d\n", MyPriority, MyTime, numer, (I+1)*10);
		if(CheckPriority==2)
		{MyTime = gettime(MyPid);			
		printf("Age = %d \n",MyTime);}
		if(CheckPriority==3)
		{MyTime = gettime(MyPid);			
		printf("Time = %d \n",MyTime);}
	}
	
	printf("== Koncze: %d\n", MyPriority);

	return 0;
}
