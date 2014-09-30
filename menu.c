/**************************************************************************************************/
/* Copyright (C) Sun Zenan, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  SunZenan                                                             */
/*  SUBSYSTEM NAME        :  test                                                                 */
/*  MODULE NAME           :  test                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  any                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/26                                                           */
/*  DESCRIPTION           :  It is a module test program                                          */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Sun Zenan, 2014/09/29
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"
#include"menu.h"

#define FAILURE  -1
#define SUCCESS   0


int showlist(tLinkTable* head)
{   
    if(head==NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}

tDNode* Find(tLinkTable *head, char *cmd)
{
    
}

int AddCmd(tLinkTable* head)
{
    if(head==NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}

int DelCmd(tLinkTable *head, char *cmd)
{
    if(head==NULL||cmd==NULL)
    {
        return FAILURE;
    }
    return SUCCESS;
}
static tDNode menulist[]=
{     

};

tLinkTable* InitMenu() 
{   
    tLinkTable *head=NULL;
    return head;
}


int MenuStart()
{   
    tLinkTable* p=InitMenu();
    while(1)
    {
        if(p==NULL)
        {
            return FAILURE;
            break;
        }
        else
        {
            break;
        }
    }
    return SUCCESS;
}
