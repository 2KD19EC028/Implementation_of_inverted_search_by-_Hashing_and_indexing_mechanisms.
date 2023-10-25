#include "main.h"
/*create database function definition*/
status create_db(f_list *head, c_db *arr)
{
    /*temp is pointing to head*/
    f_list *temp = head;
    /*declaringf variables*/
    char index[30];
    int key;
    /*traversing untill temp reaches NULL*/
    while(temp != NULL)
    {
	/*opening the files in read mode*/
	FILE *fptr = fopen(temp->f_name, "r");
	/*reading the words from file untill file pointer reaches EOF*/
	while( fscanf(fptr,"%s",index) != EOF)
	{
	    /*calculating the index*/
	    key = tolower(index[0])% 97;
	    /*validating the index*/
	    if(key < 0 || key >25)
		key = 26;
	    if(arr[key].m_link == NULL)
	    {
		/*creating main node, sub node and updataing the data*/
		m_node *m_new = malloc(sizeof(m_node));
		if(m_new == NULL)
		    return e_failure;
		s_node *s_new = malloc(sizeof(s_node));
		if(s_new == NULL)
		    return e_failure;
		m_new->file_count = 1;
		strcpy(m_new->word,index);
		m_new->m_sub_link = s_new;
		m_new->m_main_link = NULL;
		s_new->word_count = 1;
		strcpy(s_new->file_name, temp->f_name);
		s_new->s_sub_link = NULL;
		arr[key].m_link = m_new;
	    }
	    else
	    {
		int f=0;
		m_node *temp1 = arr[key].m_link;
		m_node *prev= NULL;
		/*traversing untill temp reaches NULL*/
		while(temp1 != NULL)
		{
		    /*condition to check for same words*/
		    if(strcmp(temp1->word, index) == 0)
		    {
			f=1;
			s_node *st = temp1->m_sub_link;
			s_node *st_prev =NULL;
			while(st != NULL)
			{
			    /*condition to check for duplicate file names*/
			    if(strcmp(st->file_name,temp->f_name) == 0)
			    {
				++st->word_count;
				break;
			    }
			    /*linking previous sub node with new subnode*/
			    st_prev = st;
			    st = st->s_sub_link;
			}
			if (st == NULL)
			{
			    s_node *s_new = malloc(sizeof(s_node));
			    s_new->word_count = 1;
			    strcpy(s_new->file_name,temp->f_name);
			    s_new->s_sub_link = NULL;
			    ++temp1->file_count;
			    st_prev->s_sub_link = s_new;
			}
		    }
		    prev = temp1;
		    temp1=temp1->m_main_link;
		}
		if( f == 0)
		{
		/*creating main node, sub node and updataing the data*/
		    m_node *m_new = malloc(sizeof(m_node));
		    if(m_new == NULL)
			return e_failure;
		    s_node *s_new = malloc(sizeof(s_node));
		    if(s_new == NULL)
			return e_failure;
		    m_new->file_count = 1;
		    strcpy(m_new->word,index);
		    m_new->m_sub_link = s_new;
		    m_new->m_main_link = NULL;
		    s_new->word_count = 1;
		    strcpy(s_new->file_name, temp->f_name);
		    s_new->s_sub_link = NULL;
		    /*linking the previous main node with new main node*/
		    prev->m_main_link = m_new;
		}
	    }
	}
	/*traverse in forward direction*/
	temp = temp->link;
    }
}	    
