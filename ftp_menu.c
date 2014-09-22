/**************************************************************************************************/
/* Copyright (C) Sun Zenan, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  ftp_menu.c                                                           */
/*  PRINCIPAL AUTHOR      :  SunZenan                                                             */
/*  SUBSYSTEM NAME        :  ftp_menu                                                             */
/*  MODULE NAME           :  ftp_menu                                                             */
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
#include"linktable.h"

#define DESC_LEN         1024
#define MAX_LENTH        128

typedef struct DNode
{
    tLinkTableNode *pNext;
    char*    cmd;
    char*    dsc;
    int      (*handler)();

} tDNode;

int help();

int showlist(tLinkTable* head)
{   
    tDNode *p = (tDNode*)GetLinkTableHead(head);
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->dsc);
        p = (tDNode*)GetNextLinkTableNode(head,(tLinkTableNode *)p);
    }
    return 0;
}

tDNode* Find(tLinkTable *head, char *cmd)
{
    tDNode * p = (tDNode*)GetLinkTableHead(head);
    while(p!=NULL)
    {
        if(!strcmp(p->cmd,cmd))
        {
            return p;
        }
        p = (tDNode*)GetNextLinkTableNode(head,(tLinkTableNode *)p);
    }
    return NULL;
}


static tDNode menulist[]=
{     
    {NULL,"help","it is the menulist:\n",help},
    {NULL,"version","it is the first version\n",NULL},
    {NULL,"send","it is the send cmd\n",NULL},
    {NULL,"recv","it is the recv cmd\n",NULL}

};

tLinkTable *head=NULL;
main() 
{   
    head = CreateLinkTable();
    AddLinkTableNode(head,(tLinkTableNode*) &menulist[0]);
    AddLinkTableNode(head,(tLinkTableNode*) &menulist[1]);
    AddLinkTableNode(head,(tLinkTableNode*) &menulist[2]);
    AddLinkTableNode(head,(tLinkTableNode*) &menulist[3]);
    while(1) 
    {
        char cmd[MAX_LENTH]; 
        printf("please enter the cmd:\n");
        scanf("%s",cmd);
        tDNode *p = Find(head,cmd);
        if(p==NULL)
        {   
            printf("it is a wrong cmd\n");
            continue;
        }
        printf("%s- %s\n",p->cmd,p->dsc);
        if(p->handler!=NULL)
        { 
            p->handler();
        }
    }
}

int help()
{
    showlist(head);
    return 0;
}

   


