/**************************************************************************************************/
/* Copyright (C) Sun Zenan, SSE@USTC, 2014-2015                                                   */
/*                                                                                                */
/*  FILE NAME             :  testcase.c                                                           */
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
#include"menu.h"

int results[7] = {1,1,1,1,1,1,1};
char err_info[7][100] =
{
    {"TC1: Start the menu linktable "},
    {"TC2.1: Add command to an empty linktable"},
    {"TC2.2: Add command to an exist linktable"},
    {"TC3.1: Delete command from an empty linktable"},
    {"TC3.2: Delete the command that not available from an empty linktable"},
    {"TC3.3: Delete the command that not available from an exist linktable"},
    {"TC3.4: Delete the command from an exist linktable"}
};

int main()
{  
    /*test InitMenu fuction*/
    tLinkTable *p = InitMenu();
    if(p == NULL)
    {   
        printf("TC1 fail\n");
        results[0] = 1;
    }
    else printf("TC1 success\n");
    tLinkTableNode * pNode = NULL;   
    /*test add command to empty table*/
    int addcmdret = AddCmd(p);
    if(addcmdret == SUCCESS)
    {
        printf("TC2.1 success\n");
        results[1] = 0;       
    }
    else printf("TC2.1 fail\n");    
    tLinkTable *head= (tLinkTable *)malloc(sizeof(tLinkTable));
    /*test add command to exist table*/
    int addcmdret1 = AddCmd(head);
    if(addcmdret1 == SUCCESS)
    {
        printf("TC2.2 success\n");
        results[2] = 0;       
    }
    else printf("TC2.2 fail\n");
    char cmd[MAX_LENTH]="command";
    /*test delete command from empty table*/
    int delcmdret = DelCmd(p,cmd);
    if(delcmdret == SUCCESS)
    {
        printf("TC3.1 success\n");
        results[3] = 0;       
    }
    else printf("TC3.1 fail\n");
    /*test delete command not available from empty table*/
    int delcmdret1 = DelCmd(p,NULL);
    if(delcmdret1 == SUCCESS)
    { 
        printf("TC3.2 success\n");
        results[4] = 0;       
    }
    else printf("TC3.2 fail\n");
    /*test delete command not available from exist table*/
    int delcmdret2 = DelCmd(head,NULL);
    if(delcmdret2 == SUCCESS)
    {
        printf("TC3.3 success\n");
        results[5] = 0;       
    } 
    else printf("TC3.3 fail\n");
    /*test delete command from exist table*/
    int delcmdret3 = DelCmd(head,cmd);
    if(delcmdret3 == SUCCESS)
    {
        printf("TC3.4 success\n");
        results[6] = 0;       
    }
    else printf("TC1 fail\n");
    /* test report */
    printf("Test report:\n");
    int i;
    for(i=0;i<=7;i++)
    {
        if(results[i] == 1)
        {
            printf("TestCase Number%dFailure - %s\n",i,err_info[i]);
        }
    }
}
