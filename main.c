/*
Name:Pratik B Chavan
Date:25/10/2023
Description:Inverted search project
*/
#include "main.h"
int main(int argc, char *argv[])
{
    /*declaring variables*/
    int option, f=0;
    f_list *head = NULL;
    c_db arr[27];
    /*filling the parts of the hash table*/
    for(int i=0; i<27; i++)
    {
	arr[i].key = i;
	arr[i].m_link = NULL;
    }
    /*condition if user does not pass any CLA print below statement*/
    if(argc <= 1)
    {
	printf("Error : insufficient arguements\nUsage: ./a.out file1.txt file2.txt file3.txt\n");
	return 0;
    }
    else
    {
	/*function call for read and validate files passed by user*/
	if(read_and_validate(argc,argv,&head) == e_success)
	{
	    printf("read and validate is completed\n");
	}
	else
	{
	    printf("Error : read and validate is completed\n");
	    return 0;
	}
    }
    while(1)
    {
	printf("1.create_db\n2.display_db\n3.search_db\n4.save_db\n5.Update_db\n6.exit\n");
	printf("Enter the choice\n");
	scanf("%d",&option);
	switch(option)
	{
	    case 1:
		if(f == 0)
		{
		    f=1;
		    /*create database function call*/
		    if(create_db(head,arr) == e_success)
		    {
			printf("data base is created\n");
		    }
		    else
		    {
			printf("Error : data base creation\n");
		    }
		}
		else
		    printf("create database is not possible after update database\n");
		break;
	    case 2:
		/*display database function call*/
		display_db(arr);
		break;
	    case 3:
		/*search database function call*/
		if(search_db(arr) == DATA_NOT_FOUND)
		    printf("Word not found\n");
		break;
	    case 4:
		/*save database functin call*/
		if(save_db(arr) == e_success)
		{
		    printf("saving database is completed\n");
		}
		else
		{
		    printf("Error : saving database\n");
		}
		break;
	    case 5:
		if(f == 0)
		{
		    f=1;
		    /*update database function call*/
		    if(update_db(arr) == e_success)
		    {
			printf("update database is completed\n");
		    }
		    else
		    {
			printf("Error : update database\n");
		    }
		}
		else
		{
		    printf("update database is not possible after create database\n");
		}
		break;
	    case 6:
		return 0;
	}
    }
}

