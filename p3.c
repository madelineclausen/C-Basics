#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct events {
	char name[256];
	int starttime;
	int endtime;
};

int main ()
{
	struct events allevents[24];
	for (int x=0; x<24; x++)
	{
		struct events newevent;
		newevent.starttime = -1;
		allevents[x] = newevent;
	}
	int numevents = 0;
	char usercommand[300];
	printf("$ ");
	fgets(usercommand, 300, stdin);
	char *word = strtok(usercommand, "  \n\t");
	while (strcmp(word, "quit") != 0)
	{
		if (strcmp(word, "add") == 0)
		{
			struct events newevent;
			char *newname = strtok(NULL, "  \n\t");
			strcpy(newevent.name, newname);
			char *newstarttime = strtok(NULL, "  \n\t");
			newevent.starttime = atoi(newstarttime);
			char *newendtime = strtok(NULL, "  \n\t");
			newevent.endtime = atoi(newendtime);
			bool overlapcheck = false;
			if (newevent.starttime < 24 && newevent.endtime < 24 && newevent.starttime < newevent.endtime) 
			{
				for (int x=0; x<24; x++)
				{
					if (overlapcheck == false)
					{
						if (newevent.starttime > allevents[x].starttime)
						{
							if (newevent.starttime < allevents[x].endtime)
							{
								printf("Event overlap error\n");
								overlapcheck = true;
							}
						}
						else
						{
							if (newevent.endtime > allevents[x].starttime)
							{
								printf("Event overlap error\n");
								overlapcheck = true;
							}
						}
					}
				}
				if (overlapcheck == false)
				{
					allevents[newevent.starttime] = newevent;
					numevents++;
				}
			}
		}
		if (strcmp(word, "delete") == 0)
		{
			char *deletename = strtok(NULL, "  \n\t");
			for (int i=0; i<24; i++)
			{
				if (strcmp(allevents[i].name, deletename) == 0)
				{
					allevents[i].starttime = -1;
					numevents--;
				}
			}
		}
		if (strcmp(word, "printcalendar") == 0)
		{
			for (int j=0; j<24; j++)
			{
				if (allevents[j].starttime != -1)
				{
					printf("%s %d %d\n", allevents[j].name, allevents[j].starttime, allevents[j].endtime);
				}
			}
		}
		printf("$ ");
		fgets(usercommand, 300, stdin);
		word = strtok(usercommand, "  \n\t");
	}
	return 0;
}