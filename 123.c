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

/*
 * Revision log:
 *
 * Created by Sun Zenan, 2014/09/13
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<list.h>

#define DESC_LEN         1024
#define CMD_MAX_LENS     50

int showlist();
tDataNode* FindCmd(tDataNode *head,char *cmd);
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
{   while(1)
    {char cmd[CMD_MAX_LENS]; 
     printf("please enter the cmd:\n");
     scanf("%s",cmd);
     tDataNode *P;
     tDataNode* p=FindCmd(menulist,cmd);
     if(p!=NULL)
    {
       printf("%s- %s\n",p->cmd,p->dsc);
       if(p->handler!=NULL)
           p->handler();
    }
    else printf("it is a wrong number\n");
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

tDataNode *FindCmd(tDataNode *head, char *cmd)
{   tDataNode *p=head;  
    while(p!=NULL)
    {
        if(!strcmp(p->cmd,cmd))
        {
            return p;
        }

        p=p->next;
    }
    if(p==NULL)
    {
        return NULL;
    }
    
}
