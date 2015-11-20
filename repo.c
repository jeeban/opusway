
void create_repo( void )
{
	char *content="[opusway]\nname=opusway packages\nbaseurl=file:///mnt/rhel6\nenabled=1\ngpgcheck=0";
	FILE *fd;
	
	printf("opening file\n");
	if( (fd = fopen( "/home/miku/Desktop/repo_by_software", "w" )) && fd == NULL )
	{
		printf("error opening file\n");
		exit(0);
	}
	
	//write content to the file
	fprintf( fd, "%s", content );
	
	printf("closing file\n");
	fclose(fd);
}
	
