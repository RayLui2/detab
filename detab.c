#include <stdio.h>

int main(void)
{

int i, tabwidth, place, c, extraspaces;
tabwidth = 8;
/* place is cariable to keep track of what index we are on */
place = 0;
extraspaces = 0;

/* loop until we reach the end of file */
while ((c = getchar()) != EOF) {

	/* calculate how many spaces we need for the next tab */ 
	extraspaces = tabwidth - (place % tabwidth);
	
	if (c == '\t') {
		
		/* print out correct number of spaces for a tab */
		for (i = 0; i < extraspaces; i++) {
			putchar(' ');
			place = place + 1;
		}
	}
	
	/* restart our place holder  */	
	else if (c == '\n'){
		place = 0;
		putchar(c);
	}
	
	/* move place holder -1 */
	else if (c == '\b'){
		/* can not backspace passed the left margin */
		if (place == 0) {
			place = 0;
			putchar(c);
		}
		/* move placeholder -1 if we are not at left margin */
		else {
			place = place - 1;
			putchar(c);
		}
	}

	/* reset placeholder if dealing with a carriage return */
	else if (c == '\r'){
		putchar(c);
		place = 0;
	}
	
	/* print out character if not any of the special characters */
	else {
		putchar(c);
		place = place + 1;
	}
}
return 0;
}

