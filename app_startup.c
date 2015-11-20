
void selection_menu( void )
{
	GtkWidget *cancel_button, *logo_with_name,  *temp_table;
	
	//destroying the previous components
	gtk_widget_destroy( status_label );
	gtk_widget_destroy( install_button );
	gtk_widget_destroy( unlock_button );
	gtk_widget_destroy( main_table );

	//creating the new window
	main_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	gtk_window_set_position( GTK_WINDOW( main_window), GTK_WIN_POS_CENTER );
	gtk_window_resize( GTK_WINDOW( main_window), 1366, 768 );
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management( menu )" );
	g_signal_connect( GTK_OBJECT( main_window), "destroy", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL );

	//creating the components
	cancel_button = gtk_button_new_with_label( "ABORT" );
	logo_with_name = gtk_image_new_from_file( "small.png" );
	main_image = gtk_image_new_from_file ("trans.png");
	back_to_menu_button = gtk_button_new_with_label( "<<< Back to menu" );
	widget_frame = gtk_frame_new( "" );
	main_table = gtk_table_new( 20, 16, TRUE );
	
	g_signal_connect( GTK_OBJECT( cancel_button), "clicked", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL );
	
	service_frame[1] = gtk_frame_new( "Networking" );
	service_table[1] = gtk_table_new( 4, 6, TRUE );
	service[0] = gtk_button_new_with_label ("DNS");
	service[1] = gtk_button_new_with_label ("DHCP");
	service[2] = gtk_button_new_with_label ("eth0");
	service[3] = gtk_button_new_with_label ("Repo creation");
	
	gtk_table_attach_defaults ( GTK_TABLE (service_table[1]), service[0], 1, 5, 0, 1);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[1]), service[1], 1, 5, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[1]), service[2], 1, 5, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[1]), service[3], 1, 5, 3, 4);
	gtk_container_add (GTK_CONTAINER ( service_frame[1]), service_table[1]);
	
	service_frame[2] = gtk_frame_new( "Servers" );
	service_table[2] = gtk_table_new( 7, 6, TRUE );
	service[4] = gtk_button_new_with_label ("Networking");
	service[5] = gtk_button_new_with_label ("Servers");
	service[6] = gtk_button_new_with_label ("Admin features");
	service[7] = gtk_button_new_with_label ("Admin features");
	service[8] = gtk_button_new_with_label ("Networking");
	service[9] = gtk_button_new_with_label ("Servers");
	service[10] = gtk_button_new_with_label ("Admin features");
	
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[4], 1, 5, 0, 1);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[5], 1, 5, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[6], 1, 5, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[7], 1, 5, 3, 4);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[8], 1, 5, 4, 5);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[9], 1, 5, 5, 6);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[2]), service[10], 1, 5, 6, 7);
	gtk_container_add (GTK_CONTAINER ( service_frame[2]), service_table[2]);
	
	service_frame[3] = gtk_frame_new( "Admin control" );
	service_table[3] = gtk_table_new( 4, 6, TRUE );
	service[11] = gtk_button_new_with_label ("Backup Manager");
	service[12] = gtk_button_new_with_label ("Task schedules");
	service[13] = gtk_button_new_with_label ("File locker");
	service[14] = gtk_button_new_with_label ("Key logger");
	
	g_signal_connect( GTK_OBJECT( service[11]), "clicked", GTK_SIGNAL_FUNC( init_backup_manager ), NULL );
	
	gtk_table_attach_defaults ( GTK_TABLE (service_table[3]), service[11], 1, 5, 0, 1);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[3]), service[12], 1, 5, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[3]), service[13], 1, 5, 2, 3);
	gtk_table_attach_defaults ( GTK_TABLE (service_table[3]), service[14], 1, 5, 3, 4);
	gtk_container_add (GTK_CONTAINER ( service_frame[3]), service_table[3]);
	
	
//	g_signal_connect( GTK_OBJECT( service[0]), "clicked", GTK_SIGNAL_FUNC( show_features ), "Networking" );
//	g_signal_connect( GTK_OBJECT( service[1]), "clicked", GTK_SIGNAL_FUNC( show_features ), "Servers" );
//	g_signal_connect( GTK_OBJECT( service[2]), "clicked", GTK_SIGNAL_FUNC( show_features ), "Admin features" );
	g_signal_connect( GTK_OBJECT( service[0]), "enter", GTK_SIGNAL_FUNC( show_image ), "networking.jpg" );
	g_signal_connect( GTK_OBJECT( service[1]), "enter", GTK_SIGNAL_FUNC( show_image ), "images.jpg" );
	g_signal_connect( GTK_OBJECT( service[2]), "enter", GTK_SIGNAL_FUNC( show_image ), "web.jpg" );
	
	gtk_table_attach_defaults ( GTK_TABLE (main_table), logo_with_name, 0, 4, 0, 2);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), service_frame[1], 0, 4, 2, 6);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), service_frame[2], 0, 4, 6, 13);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), service_frame[3], 0, 4, 13, 17);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), main_image, 4, 16, 2, 16);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), cancel_button, 13, 15, 18, 19);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), widget_frame, 4, 16, 2, 16);
	
	temp_table = gtk_table_new( 3, 3, TRUE );
	gtk_table_attach_defaults ( GTK_TABLE (temp_table), back_to_menu_button, 0, 3, 2, 3);
	g_signal_connect( GTK_OBJECT( back_to_menu_button), "clicked", GTK_SIGNAL_FUNC( back_to_menu ), NULL );
	gtk_table_attach_defaults ( GTK_TABLE (main_table), temp_table, 4, 6, 14, 17);
		
	gtk_container_add( GTK_CONTAINER(main_window), main_table );
	
	gtk_widget_show_all( main_window );
	gtk_widget_hide( back_to_menu_button );
	
}







void show_image( GtkWidget *widget, gpointer data )
{	
	gtk_image_set_from_file( GTK_IMAGE( main_image), (char*)data );	
}



void back_to_menu( void )
{
	gtk_widget_destroy( widget_table );
	for( n=0; n<15; n++ )
	{
		gtk_widget_set_sensitive( service[n], TRUE );
	}
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management" );
	gtk_frame_set_label( GTK_FRAME( widget_frame), "");
	gtk_widget_hide( back_to_menu_button );
	gtk_widget_show( main_image);
}
