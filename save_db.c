#include "main.h"
#include <stdio_ext.h>
/*save database function definition*/
status save_db(c_db *hash_t)
{
    char file[20],choice;
    /*reading the file name from user*/
    printf("Enter the file name\n");
    scanf("%s",file);
    /*opening the user entered file in write mode*/
    FILE *fptr = fopen(file, "w");
    /*condition to check file exist or not*/
    if(fptr != NULL)
    {
	fseek(fptr, 0 ,SEEK_END);
	/*condition to check file empty*/
	if(fptr != 0)
	{
	    /*asking permission from user to overwrite*/
	    printf("can I overwrite the content (y/n)\n");
	    __fpurge(stdin);
	    /*reading the choice from user*/
	    scanf("%c",&choice);
	    if(choice == 'n')
	    {
		return e_failure;
	    }
	}
    }
    /*loop to iterate all the index*/
    for(int key=0; key<27; key++)
    {
	m_node *temp = hash_t[key].m_link;
	/*condition to check if index of link is NULL*/
	if(temp == NULL)
	    /*continue to loop*/
	    continue;
	/*traversing till temp reaches NULL*/
	while(temp != NULL)
	{
	    /*storing into the file*/
	    fprintf(fptr, "%s" , "#");
	    fprintf(fptr, "%d;" , key);
	    fprintf(fptr, "%s;" , temp->word);
	    fprintf(fptr, "%d;" , temp->file_count);
	    s_node *stemp = temp->m_sub_link;
	    /*traversing untill stemp reaches NULL*/
	    while(stemp != NULL)
	    {
		/*printing to the file*/
		fprintf(fptr,"%s;",stemp->file_name);
		fprintf(fptr,"%d;",stemp->word_count);
		/*traverse in forward direction*/
		stemp = stemp->s_sub_link;
	    }
	    /*traverse in forward direction*/
	    temp = temp->m_main_link;
	    fprintf(fptr, "%s" , "#");
	    fprintf(fptr, "%s" , "\n");
	}
    }
    fclose(fptr);
    return e_success;
}

