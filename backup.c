

void init_backup_manager( void )
{
	
	GtkWidget *option_table, *option_frame, *selection_label;
	
	for( n=0; n<15; n++ )
	{
		gtk_widget_set_sensitive( service[n], FALSE );
	}
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management( backup_manager )" );
	gtk_frame_set_label( GTK_FRAME( widget_frame), "Backup manager");
	gtk_widget_show( back_to_menu_button );
	
	widget_table = gtk_table_new( 14, 14, TRUE );
	
	status_label = gtk_label_new("");
	gtk_label_set_justify( GTK_LABEL( status_label), GTK_JUSTIFY_CENTER);
	gtk_label_set_markup( GTK_LABEL( status_label ), "<span fgcolor=\"red\" font=\"13\">Application mode:\n\n(none)</span>" );
	backup_button = gtk_button_new_with_label("BACKUP");
	restore_button = gtk_button_new_with_label("RESTORE");
	
	button[0] = gtk_button_new_with_label("Backup");
	button[1] = gtk_button_new_with_label("Restore");
	label[0] = gtk_label_new( NULL );
	label[1] = gtk_label_new( NULL );
	label[2] = gtk_label_new( NULL );
	name_entry = gtk_entry_new();
	file_select = gtk_button_new_with_label("...");
	folder_select[0] = gtk_button_new_with_label("...");
	folder_select[1] = gtk_button_new_with_label("...");
	process_status = gtk_label_new("...");
	
	g_signal_connect( GTK_OBJECT( file_select), "clicked", GTK_SIGNAL_FUNC( select_a_file ), NULL );
	g_signal_connect( GTK_OBJECT( folder_select[0]), "clicked", GTK_SIGNAL_FUNC( select_a_folder ), (gpointer)0 );
	g_signal_connect( GTK_OBJECT( folder_select[1]), "clicked", GTK_SIGNAL_FUNC( select_a_folder ), (gpointer)1 );
	g_signal_connect( GTK_OBJECT( backup_button), "clicked", GTK_SIGNAL_FUNC( backup_mode ), NULL );
	g_signal_connect( GTK_OBJECT( restore_button), "clicked", GTK_SIGNAL_FUNC( restore_mode ), NULL );
	g_signal_connect( GTK_OBJECT( button[0]), "clicked", GTK_SIGNAL_FUNC( take_backup ), NULL );
	g_signal_connect( GTK_OBJECT( button[1]), "clicked", GTK_SIGNAL_FUNC( perform_restore ), NULL );
	
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), status_label, 1, 7, 3, 7);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), backup_button, 2, 6, 8, 9);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), restore_button, 2, 6, 9, 10);
	
	option_frame = gtk_frame_new("Application mode selection");
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), option_frame, 1, 7, 2, 11);
	app_frame = gtk_frame_new("");
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), app_frame, 7, 13, 2, 11);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), label[0], 8, 11, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), folder_select[0], 11, 12, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), file_select, 11, 12, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), label[1], 8, 11, 5, 6);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), folder_select[1], 11, 12, 5, 6);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), label[2], 11, 12, 6, 7);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), name_entry, 8, 11, 6, 7);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), button[0], 9, 11, 7, 8);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), button[1], 9, 11, 7, 8);
	gtk_table_attach_defaults ( GTK_TABLE (widget_table), process_status, 8, 12, 9, 10);
	
	gtk_table_attach_defaults ( GTK_TABLE (main_table), widget_table, 4, 16, 2, 17);

	gtk_widget_show_all( widget_table );
	gtk_widget_hide( app_frame );
	gtk_widget_hide( label[0] );
	gtk_widget_hide( folder_select[0] );
	gtk_widget_hide( folder_select[1] );
	gtk_widget_hide( label[1] );
	gtk_widget_hide( file_select );
	gtk_widget_hide( label[2] );
	gtk_widget_hide( name_entry );
	gtk_widget_hide( button[0] );
	gtk_widget_hide( button[1] );
	gtk_widget_hide( process_status );
	gtk_widget_hide( main_image);



}



void backup_mode( void )
{
	if( compare( (char*)gtk_frame_get_label( GTK_FRAME(app_frame)), "Backup" ) != 0 )
	{
		
		gtk_label_set_markup( GTK_LABEL( status_label ), "<span fgcolor=\"green\" font=\"13\">Application mode:\n\nBACKUP</span>" );
	
		gtk_frame_set_label( GTK_FRAME( app_frame), "Backup");
		gtk_label_set_text( GTK_LABEL( label[0]), "Backup source folder ->     " );
		gtk_label_set_text( GTK_LABEL( label[1]), "Backup destination folder ->" );
		gtk_label_set_text( GTK_LABEL( label[2]), ".tar.gz" );
		gtk_label_set_text( GTK_LABEL( process_status), "..." );
		gtk_button_set_label( GTK_BUTTON( folder_select[0]), "..." );
		gtk_button_set_label( GTK_BUTTON( folder_select[1]), "..." );
		gtk_widget_set_tooltip_text( folder_select[0], NULL );
		gtk_widget_set_tooltip_text( folder_select[1], NULL );
		gtk_entry_set_text( GTK_ENTRY( name_entry), "" );
		
		gtk_widget_show_all( widget_table );
		gtk_widget_hide( file_select );
		gtk_widget_hide( button[1] );
		gtk_widget_hide( main_image);
		
		source_ready = 0;
		target_ready = 0;
	}
}


void restore_mode( void )
{
	if( compare( (char*)gtk_frame_get_label( GTK_FRAME(app_frame)), "Restore" ) != 0 )
	{
		gtk_label_set_markup( GTK_LABEL( status_label ), "<span fgcolor=\"green\" font=\"13\">Application mode:\n\nRESTORE</span>" );
		
		gtk_frame_set_label( GTK_FRAME( app_frame), "Restore");
		gtk_label_set_text( GTK_LABEL( label[0]), "Source tar file ->           " );
		gtk_label_set_text( GTK_LABEL( label[1]), "Restore destination folder ->" );
		gtk_label_set_text( GTK_LABEL( label[2]), "" );
		gtk_label_set_text( GTK_LABEL( process_status), "..." );
		gtk_button_set_label( GTK_BUTTON( file_select), "..." );
		gtk_button_set_label( GTK_BUTTON( folder_select[1]), "..." );
		gtk_widget_set_tooltip_text( folder_select[1], NULL );
		gtk_widget_set_tooltip_text( file_select, NULL );
		gtk_entry_set_text( GTK_ENTRY( name_entry), "" );
		
		gtk_widget_show_all( widget_table );
		gtk_widget_hide( folder_select[0] );
		gtk_widget_hide( button[0] );
		gtk_widget_hide( main_image);
		
		source_ready = 0;
		target_ready = 0;
	}
}






void select_a_file( void )
{
	GtkWidget *dialog;

	dialog = gtk_file_chooser_dialog_new ("Open File", GTK_WINDOW(main_window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

	if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
	{
    		source_file = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    		
    		target_file = source_file;
    		for( ; *target_file != '\0'; target_file++ );
    		target_file = target_file-7;
    		
    		if( compare( target_file, ".tar.gz" ) == 0 )
    		{
    			gtk_label_set_text( GTK_LABEL( process_status), "...");
    			
    			gtk_button_set_label( GTK_BUTTON( file_select), "Done" );
    			gtk_widget_set_tooltip_text( file_select, source_file );
    			source_ready = 1;
    			
    			for( *target_file = '\0'; *target_file != '/'; target_file-- );
    			*target_file = '\0';
    			target_file++;
    			
    			gtk_entry_set_text( GTK_ENTRY( name_entry), target_file );
    		
			gtk_button_set_label( GTK_BUTTON( folder_select[1]), "Default" );
			gtk_widget_set_tooltip_text( folder_select[1], source_file );
			target_file = source_file;
			target_ready = 1;
		}
		else
		{
			gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"red\" font=\"11\">Invalid Source.</span>" );
			gtk_button_set_label( GTK_BUTTON( file_select), "..." );
			gtk_button_set_label( GTK_BUTTON( folder_select[1]), "..." );
			gtk_widget_set_tooltip_text( folder_select[1], NULL );
			gtk_widget_set_tooltip_text( file_select, NULL );
			gtk_entry_set_text( GTK_ENTRY( name_entry), "" );
		}
    	}
    	else
    	{
		gtk_button_set_label( GTK_BUTTON( file_select), "..." );
		gtk_button_set_label( GTK_BUTTON( folder_select[1]), "..." );
		gtk_widget_set_tooltip_text( folder_select[1], NULL );
		gtk_widget_set_tooltip_text( file_select, NULL );
		gtk_entry_set_text( GTK_ENTRY( name_entry), "" );
		source_ready = 0;
		target_ready = 0;
	}	
    	gtk_widget_destroy (dialog);
}






void select_a_folder( GtkWidget *widget, gpointer data )	//data =0 for 1st selction and 1 for 2nd selection
{
	GtkWidget *dialog;

	dialog = gtk_file_chooser_dialog_new ("Open Folder", GTK_WINDOW(main_window), GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);

	if( (int)data == 0 )
	{
		if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
		{
    			source_file = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    			gtk_button_set_label( GTK_BUTTON( widget), "Done" );
    			gtk_widget_set_tooltip_text( widget, source_file );
    			source_ready = 1;
    			
    			target_file = source_file;
    			for( ; *target_file != '\0'; target_file++ );
    			for( ; *target_file != '/'; target_file-- );
    			target_file++;
    			gtk_entry_set_text( GTK_ENTRY( name_entry), target_file );
    			
    			gtk_button_set_label( GTK_BUTTON( folder_select[1]), "Default" );
    			gtk_widget_set_tooltip_text( folder_select[1], source_file );
    			target_file = source_file;
    			target_ready = 1;
		}
		else
		{
			gtk_button_set_label( GTK_BUTTON( widget), "..." );
			gtk_button_set_label( GTK_BUTTON( folder_select[1]), "..." );
			gtk_widget_set_tooltip_text( widget, NULL );
			gtk_widget_set_tooltip_text( folder_select[1], NULL );
			gtk_entry_set_text( GTK_ENTRY( name_entry), "" );
			source_ready = 0;
			target_ready = 0;
		}
		gtk_widget_destroy (dialog);
	}
	else
	{
		if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
		{
    			target_file = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    			gtk_button_set_label( GTK_BUTTON( widget), "Done" );
    			gtk_widget_set_tooltip_text( widget, target_file );
    			target_ready = 1;
		}
		gtk_widget_destroy (dialog);
	}
}






void take_backup( void )
{
	char command[300];
	
	if( source_ready == 1 )
	{

		sprintf( command, "tar cvzf \"%s/%s.tar.gz\" *&", target_file, gtk_entry_get_text( GTK_ENTRY( name_entry)) );
		chdir( source_file );
		//printf("%s\n",command );
		
		
		if( system( command ) == 0 )
		{
			gtk_widget_set_sensitive( button[0], FALSE );
			gtk_widget_set_sensitive( restore_button, FALSE );
			gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"blue\" font=\"11\">Backup creation in progress...</span>" );
			gtk_timeout_add( 1000, backup_process_status, NULL );
		}
		else
		{
			gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"red\" font=\"11\">Backup creation failed.</span>" );
		}
	}
	else
	{
		gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"red\" font=\"11\">Invalid source folder.</span>" );
	}
}






int backup_process_status( void )
{

	int ret;
	FILE *fd;
	
	fd = popen( "ps -ef | grep \"tar cvzf\" | wc -l", "r" );
	fscanf( fd, "%d", &ret );
	pclose( fd );
	
	fprintf( stderr, "ret = %d\n", ret );
	if( ret > 2 )
	{
		return TRUE;
	}
	else
	{
		gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"green\" font=\"11\">Backup created</span>" );
		gtk_widget_set_sensitive( button[0], TRUE );
		gtk_widget_set_sensitive( restore_button, TRUE );
		return FALSE;
	}
}








void perform_restore( void )
{
	char command[300];
	
	if( source_ready == 1 )
	{

		sprintf( command, "%s/%s", target_file, gtk_entry_get_text( GTK_ENTRY( name_entry)) );
		printf("target folder is - %s\n",command );
		mkdir( command, S_IRWXU );
		chdir( command );
		sprintf( command, "tar xvzf %s&", gtk_widget_get_tooltip_text( file_select ) );
		printf("target folder is - %s\n",command );
		if( system( command ) == 0 )
		{
			gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"blue\" font=\"11\">Restore in progress...</span>" );
			gtk_widget_set_sensitive( button[1], FALSE );
			gtk_widget_set_sensitive( backup_button, FALSE );
			gtk_timeout_add( 1000, restore_process_status, NULL );
		}
		else
		{
			gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"red\" font=\"11\">Restore failed.</span>" );
		}
	}
	else
	{
		gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"red\" font=\"11\">Invaild source file.</span>" );
	}

}




int restore_process_status( void )
{

	int ret;
	FILE *fd;
	
	fd = popen( "ps -ef | grep \"tar xvzf\" | wc -l", "r" );
	fscanf( fd, "%d", &ret );
	pclose( fd );
	
	fprintf( stderr, "ret = %d\n", ret );
	if( ret > 2 )
	{
		return TRUE;
	}
	else
	{
		gtk_label_set_markup( GTK_LABEL( process_status), "<span fgcolor=\"green\" font=\"11\">Restore completed</span>" );
		gtk_widget_set_sensitive( button[1], TRUE );
		gtk_widget_set_sensitive( backup_button, TRUE );
		return FALSE;
	}
}
