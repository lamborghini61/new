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

#define DESC_LEN         1024
#define MAX_LENTH        50

typedef struct DNode
{
    char*   cmd;
    char*   dsc;
    int     (*handler)();
    struct  DNode *next;
} tDNode;

int help();

int showlist(tDNode *head);

tDNode* Find(tDNode *head,char *cmd);

static tDNode menulist[]=
{     
    {"help","it is the menulist:\n",help,&menulist[1]},
    {"version","it is the first version\n",NULL,&menulist[2]},
    {"send","it is a send cmd\n",NULL,&menulist[3]},
    {"rec","it is a rec cmd\n",NULL,NULL}
};
    
main() 
{   
    while(1) 
    {
        char cmd[MAX_LENTH]; 
        printf("please enter the cmd:\n");
        scanf("%s",cmd);
        tDNode *p=Find(menulist,cmd);
        if(p!=NULL)
        {
            printf("%s- %s\n",p->cmd,p->dsc);
            if(p->handler!=NULL)
                p->handler();
        }
        else printf("it is a wrong number\n");
    }
}

int help()
{   
    int a;
    a=showlist(&menulist[1]);
    return 0;
}

/*this fuction show the cmd list*/

int showlist(tDNode* head)
{   
    tDNode *p;
    for(p=head;p!=NULL;p=p->next)
    {
        printf("%s,%s",p->cmd,p->dsc);
    }
    return 0;
}

/*this fuction find the cmd from the list*/

tDNode *Find(tDNode *head, char *cmd)
{  
    tDNode *p;
    for(p=head;p!=NULL;p=p->next)
    {
        if(!strcmp(p->cmd,cmd))
        {
            return p;
        }
    }
    if(p==NULL)
    {
        return NULL;
    }
}

