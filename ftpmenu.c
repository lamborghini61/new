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

int showlist();

typedef struct DataNode
{
    char*   cmd;
    char*   dsc;
    int     (*handler)();
    struct  DataNode *next;
} tDataNode;


static tDataNode menulist[]=
{

    {"showlist","it is a showlist cmd\n",showlist,&menulist[1]},
    {"version","it is the first version\n",NULL,&menulist[2]},
    {"send","it is a send cmd\n",NULL,&menulist[3]},
    {"rec","it is a rec cmd\n",NULL,NULL}
};


main()
{   
    while(1)
    {
        char cmd[CMD_MAX_LENS];
        tDataNode *head=NULL;
        printf("please enter cmd:\n");
        scanf("%s",&cmd);
        tDataNode *p=menulist;
        while(p!=NULL)
        {   
            if(!strcmp(p->cmd,cmd))
            {
	        printf("%s- %s\n",p->cmd,p->dsc);
	        if(p->handler!=NULL)
                p->handler();
                break;
            } 

            p=p->next;
        }
        if(p==NULL)
        {   
            printf("it is a wrong cmd\n");
        }
     }
}

int showlist()
{
    tDataNode *p=&menulist[1];
    while(p)
    {
        printf("%s,%s",p->cmd,p->dsc);
        p=p->next;
    }
    return 0;
}

tDataNode *FindCmd(tDataNode *head)
{  tDataNode *p=head;  
 while(1)
    {
        char cmd[CMD_MAX_LENS];
        tDataNode *head=NULL;
        printf("please enter cmd:\n");
        scanf("%s",&cmd);
        while(p!=NULL)
        {
            if(!strcmp(p->cmd,cmd))
            {
                printf("%s- %s\n",p->cmd,p->dsc);
                if(p->handler!=NULL)
                p->handler();
                return p;
            }

            p=p->next;
        }
        if(p==NULL)
        {
            printf("it is a wrong cmd\n");
         return NULL;
        }
     }




}
