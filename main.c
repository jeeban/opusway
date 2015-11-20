#include <sys/stat.h>
#include <sys/types.h>

#include<gtk/gtk.h>
#include<stdlib.h>
#include<unistd.h>

#include"headers.c"
#include"extra.c"

#include"opusway_intro.c"
#include"app_startup.c"

//#include"ftp.c"
#include"repo.c"
#include"backup.c"
//#include"cron.c"



int main( int argc, char **argv )
{
	
//	if( getuid() != 0 )
//	{
//		printf("run the app as root.\n");
//		return 0;
//	}
	
	gtk_init( &argc, &argv );
//	introduction_to_the_app();
	selection_menu();
	gtk_main();
	
	return 0;
}	


