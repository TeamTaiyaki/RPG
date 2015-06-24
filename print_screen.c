
#include <stdio.h>
#include <string.h>

#include "file.h"
#include "print_screen.h"

#define BUF_ROWS		15

static char msg_buf[BUF_ROWS][100];
static char msg_select[100][100];

static int select_rows = 4;
static int my_hp, ememy_hp;

int print_story(char *msg, ...)
{
	int i;
	static int buf_rows;
	char buf[1024];
	va_list list;
	int var_count = 0;
	
	/* variables list */
	for(i = 0; i < strlen(msg) - 1; i++) {
		if((msg[i] == '%') &&
			(msg[i + 1] == 'd' ||
			 msg[i + 1] == 's' ||
			 msg[i + 1] == 'f' ||
			 msg[i + 1] == 'd' ||
			 msg[i + 1] == 'u' ||
			 msg[i + 1] == 'x' ||
			 msg[i + 1] == 'X'))
		{
			var_count++;
		}
	}
	va_start(list, var_count);
	
	//var_args(list, int);
	
	system("cls");
	printf("----------------------------------------------------------------------\n");
	//printf("HP | MY: %5d    || EMEMY: %5d  \n", my_hp, ememy_hp);
	//printf("----------------------------------------------------------------------\n");
	
	if(buf_rows < BUF_ROWS - 1) {
		strncpy(msg_buf[buf_rows], msg, sizeof(msg_buf[buf_rows]));
		buf_rows++;
	} else {
		for(i = 0; i < buf_rows - 1; i++) {
			strncpy(msg_buf[i], msg_buf[i + 1], sizeof(msg_buf[i]));
		}
		sprintf(buf, msg);
		strncpy(msg_buf[buf_rows], buf, sizeof(msg_buf[buf_rows]));
	}
	
	for(i = 0; i < buf_rows; i++) {
		printf(" %s", msg_buf[i]); /* Don't output NewLine at End of Line */
	}
	for(; i < BUF_ROWS; i++) {
		printf("\n");
	}
	
	printf("\n----------------------------------------------------------------------\n");
	
	va_end(list);
	
	return 0;
}

int set_myhp(int hp)
{
	my_hp = hp;
}

int set_ememyhp(int hp)
{
	ememy_hp = hp;
}

int get_myhp(void)
{
	return my_hp;
}

int get_ememyhp(void)
{
	return ememy_hp;
}
