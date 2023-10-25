#include "main.h"
int flag = 0;
/*function definition for read and validate*/
status read_and_validate(int argc,char *argv[], f_list **head)
{
    for(int i=1; i<argc; i++)
    {
	/*open files function call*/
	if(open_files(argv[i]) == e_success)
	{
	    f_list *new = malloc(sizeof(f_list));
	    /*condition to check head is NULL or not*/
	    if(*head == NULL)
	    {
		/*storing the file name*/
		*head = new;
		strcpy(new->f_name,argv[i]);
		new->link = NULL;
	    }
	    else
	    {
		f_list *temp = *head;
		f_list *prev =NULL;
		/*traversing till temp reaches NULL*/
		while(temp != NULL)
		{
		    /*condition to check file is duplicate */
		    if(strcmp(temp->f_name , argv[i]) == 0)
		    {
			printf("%s file is duplicate\n",argv[i]);
			flag = 1;
			break;
		    }
		    prev = temp;
		    temp = temp->link;
		}
		if(flag == 0)
		{
		    /*stoing the file name*/
		strcpy(new->f_name, argv[i]);
		prev->link = new;
		new->link = NULL;
		}
		flag = 0;
	    }
	}
    }
printf("open file successful\n");
return e_success;
}
/*open file function definition*/
status open_files(char *argv)
{
    FILE *fptr= fopen(argv, "r");
    /*condoition to check file is opened successfully or not*/
    if (fptr != NULL)
    {
	/*condition to check file have .txt extension or not*/
	if(strcmp((strstr(argv,".")),".txt") == 0)
	{
	    fseek(fptr, 0, SEEK_END);
	    /*condition to check file is empty or not*/
	    if(ftell(fptr) != 0)
	    {
		fclose(fptr);
		return e_success;
	    }
	    else
	    {
		printf("Error :file is empty %s\n",argv);
		return e_failure;
	    }
	}
	else
	{
	    printf("Error : file does not have .txt extension %s\n",argv);
	    return e_failure;
	}
    }
    else
    {
	printf("Error : file does not exist %s\n",argv);
	return e_failure;
    }

}
