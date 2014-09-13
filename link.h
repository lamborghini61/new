/**************************************************************************************************/
/* Copyright (C) Sun Zenan, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  link.h                                                               */
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


typedef struct DataNode
{
    char*   cmd;
    char*   dsc;
    int     (*handler)();
    struct  DataNode *next;
} tDataNode;

int showlist();

tDataNode* FindCmd(tDataNode *head,char *cmd);
