#include "main.h"
/*search database function definition*/
status search_db(c_db *hash_t)
{
    /*declaring the varisbles*/
    char w[30];int key;
    /*reading the word from user*/
    printf("Enter the word you want to search\n");
    scanf("%s",w);
    /*calculating the index*/
    key = tolower(w[0]) % 97;
    m_node *temp = hash_t[key].m_link;
    /*condition to check if index of link in hash table is NULL*/
    if(temp == NULL)
	return DATA_NOT_FOUND;
    /*traversing untill temp reaches NULL*/
    while(temp != NULL)
    {
	/*comparing the word from the database with user entered word*/
	if(strcmp(temp->word,w) == 0)
	{
	    /*printin the file count*/
	    printf("The %s is present in (%d) files\n",w,temp->file_count);
	    s_node *stemp = temp->m_sub_link;
	    while(stemp != NULL)
	    {
		/*printing the word count*/
		printf("%s --- %d times\n",stemp->file_name,stemp->word_count);
		/*traverse in forward direction*/
		stemp = stemp->s_sub_link;
	    }
	    return e_success;
	}
	/*traverse in forward direction*/
	temp = temp->m_main_link;
    }
    return DATA_NOT_FOUND;
}


