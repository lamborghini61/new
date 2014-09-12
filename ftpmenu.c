/**************************************************************************************************/
/* Copyright (C) Sun Zenan, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  ftpmenu.c                                                            */
/*  PRINCIPAL AUTHOR      :  SunZenan                                                             */
/*  SUBSYSTEM NAME        :  ftpmenu                                                              */
/*  MODULE NAME           :  ftpmenu                                                              */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  any                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/11                                                           */
/*  DESCRIPTION           :  It is a ftpmenu program                                              */
/**************************************************************************************************/



#include<stdio.h>
#include<stdlib.h>


#define DESC_LEN         1024
#define CMD_MAX_LENS     50

typedef struct DataNode
{
    char   *cmd;
    char   *desc;
    struct DataNode *next;
}tDataNode;

static tDataNode list[]=
{
{"help","it is a help cmd",&list[1]},
{"version","this is the first version",NULL}
};
main()
{   while(1)
    {
    char cmd[CMD_MAX_LENS];
    tDataNode *head=NULL;
    printf("please enter cmd:");
    scanf("%s",&cmd);
    tDataNode *p=list;
    while(p!=NULL)
    {   if(!strcmp(p->cmd,cmd))
        {
	    printf("%s- %s",p->cmd,p->desc);
	    break;
        }

        p=p->next;
     }
    if(p==NULL)
    printf("it is a wrong cmd");

    }
}