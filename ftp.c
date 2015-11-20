
void init_screen_ftp( void )
{
	int i;
	GtkWidget *terminal_frame, *f_button[5], *scrolled_window, *f_table;
	
	gtk_widget_destroy( feature_frame);
	gtk_widget_destroy( main_image);
	gtk_widget_destroy( sub_image);
	gtk_widget_destroy( service_frame);
	
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management( ftp setup )" );
	
	terminal_frame = gtk_frame_new( "Terminal" );
	button_info = gtk_label_new( "" );
	process_status = gtk_label_new( NULL );
	gtk_label_set_justify( GTK_LABEL( process_status), GTK_JUSTIFY_CENTER );

	
	scrolled_window = gtk_scrolled_window_new (NULL, NULL);
	textview = gtk_text_view_new ();
	gtk_text_view_set_editable( GTK_TEXT_VIEW(textview), FALSE);
	
	gtk_container_add (GTK_CONTAINER (scrolled_window), textview);
	gtk_container_add( GTK_CONTAINER( terminal_frame), scrolled_window );
	
	f_button[0] = gtk_button_new_with_label( "INSTALL" );
	f_button[1] = gtk_button_new_with_label( "FILE" );
	f_button[2] = gtk_button_new_with_label( "FOLDER" );
	f_button[3] = gtk_button_new_with_label( "RESTART" );
	f_button[4] = gtk_button_new_with_label( "REMOVE" );
	
	
	g_signal_connect( GTK_OBJECT( f_button[0]), "enter", GTK_SIGNAL_FUNC( show_message ), "Start the installation process." );
	g_signal_connect( GTK_OBJECT( f_button[1]), "enter", GTK_SIGNAL_FUNC( show_message ), "View the configuration files" );
	g_signal_connect( GTK_OBJECT( f_button[2]), "enter", GTK_SIGNAL_FUNC( show_message ), "Open the share folder." );
	g_signal_connect( GTK_OBJECT( f_button[3]), "enter", GTK_SIGNAL_FUNC( show_message ), "restart the server." );
	g_signal_connect( GTK_OBJECT( f_button[4]), "enter", GTK_SIGNAL_FUNC( show_message ), "Remove the package from the server." );
	
	for( i=0; i<5; i++ )
	{
		g_signal_connect( GTK_OBJECT( f_button[i]), "leave", GTK_SIGNAL_FUNC( show_message ), "" );
	}
	
	
	g_signal_connect( GTK_OBJECT( f_button[0]), "clicked", GTK_SIGNAL_FUNC( ftp_install ), NULL );
	g_signal_connect( GTK_OBJECT( f_button[1]), "clicked", GTK_SIGNAL_FUNC( ftp_file ), NULL );
	g_signal_connect( GTK_OBJECT( f_button[2]), "clicked", GTK_SIGNAL_FUNC( ftp_folder ), NULL );
	
	f_table = gtk_table_new( 12, 18, TRUE );
	
	gtk_table_attach_defaults ( GTK_TABLE (f_table), terminal_frame, 1, 17, 0, 7);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), button_info, 1, 17, 9, 10);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), process_status, 1, 17, 7, 8);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), f_button[0], 1, 4, 10, 11);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), f_button[1], 5, 8, 10, 11);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), f_button[2], 8, 11, 10, 11);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), f_button[3], 11, 14, 10, 11);
	gtk_table_attach_defaults ( GTK_TABLE (f_table), f_button[4], 14, 17, 10, 11);
	

	gtk_table_attach_defaults ( GTK_TABLE (main_table), f_table, 1, 13, 2, 12);
	gtk_widget_show_all( main_window );
}



void show_message( GtkWidget *widget, gpointer data )
{
	gtk_label_set_text( GTK_LABEL( button_info ), (char*)data );
}



void update_terminal( char *output_text )
{
	GtkTextBuffer *buffer;
  	GtkTextIter iter;
  	GtkTextMark *mark;

	buffer = gtk_text_view_get_buffer (textview);
	gtk_text_buffer_get_end_iter (buffer, &iter);

	gtk_text_buffer_insert (buffer, &iter, "\n", -1);
	gtk_text_buffer_insert (buffer, &iter, output_text, -1);

	gtk_text_iter_set_line_offset (&iter, 0);

	mark = gtk_text_buffer_get_insert (buffer);
	gtk_text_buffer_move_mark (buffer, mark, &iter);

	gtk_text_view_scroll_mark_onscreen (textview, mark);
		
	printf( "%s\n", output_text );
	
//	buffer_data_entry();

}


void buffer_data_entry( void )
{
	char ch[1], output[500];
	int output_index=2;

	output[0] = '_';
	output[1] = ' ';
	
	while( read( fileno(pd), ch, sizeof(char) ) > 0 )
	{	
		if( ch[0] != '\n' && ch[0] != '\0' )
		{
			output[ output_index++ ] = ch[0];
		}
		else
		{
			output[ output_index ] = '\0';
			output_index = 2;
			update_terminal( output );
		}
	}
}



void ftp_install( void )
{
	//step 1 install original ftp
	gtk_label_set_text( GTK_LABEL( process_status ), "step 1/3 : installing server" );

	pd = popen( "sh a.sh&", "r" );	//command to install ftp
//	pd = popen( "sudo apt-get update", "r" );
	buffer_data_entry();
//	sleep(1);
/*	
	//step2 copy new files
	gtk_label_set_text( GTK_LABEL( process_status ), "step 2/3 : copying new server files" );
//	sleep(1);
	
	//step3 restart server
	gtk_label_set_text( GTK_LABEL( process_status ), "step 3/3 : restarting server" );
//	sleep(1);
	
	//step4
	gtk_label_set_text( GTK_LABEL( process_status ), "ftp server installed successfully." );
*/
	pclose( pd);
}





void ftp_file( void )
{
	system( "gedit /home/miku/Desktop/vsftpd.conf&" );
}


void ftp_folder( void )
{
	system( "xdg-open /home/miku/Desktop&" );
}
