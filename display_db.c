#include "main.h"
/*display database function definition*/
status display_db(c_db *hash_t)
{
    printf("index	word	filecount     files    wordcount\n");
    /*loop to display all index data*/
    for(int key=0; key<27; key++)
    {
	m_node *temp2 = hash_t[key].m_link;
	if(temp2 == NULL)
	    continue;
	else
	{
	    /*traversing untill temp2 reaches NULL*/
	    while(temp2 != NULL)
	    {
		/*printing the data*/
		printf("[%d]	",key);
		printf("[%s]	",temp2->word);
		printf("  [%d]	",temp2->file_count);
		s_node *stemp = temp2->m_sub_link;
		/*traversing untill stemp reaches NULL*/
		while(stemp != NULL)
		{

		    printf("  %s	",stemp->file_name);
		    printf("%d	",stemp->word_count);
		    /*traverse in forward direction*/
		    stemp = stemp->s_sub_link;
		}
		printf("\n");
		/*traverse in forward direction*/
		temp2 = temp2->m_main_link;
	    }
	}
    }
}


