/**************************************************************************************************/
/* Copyright (C) Sun Zenan, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  menu.h                                                               */
/*  PRINCIPAL AUTHOR      :  SunZenan                                                             */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  any                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/26                                                           */
/*  DESCRIPTION           :  It is a module program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Sun Zenan, 2014/09/29
 *
 */
#include"linktable.h"

#define DESC_LEN         1024
#define MAX_LENTH        1024

typedef struct DNode
{
    tLinkTableNode *pNext;
    char*    cmd;
    char*    dsc;
} tDNode;

/*show all commands*/
int showlist(tLinkTable* head);

/*find a command from the menu linktable*/
tDNode* Find(tLinkTable *head, char *cmd);

/*initialise the ftpmenu linktable*/
tLinkTable* InitMenu();

/*add a command to the ftpmenu linktable*/
int AddCmd(tLinkTable* head);

/*delete a command from the ftp linktable*/
int DelCmd(tLinkTable *head, char *cmd);
/*start the menu linktable*/
int MenuStart();
