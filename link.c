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

