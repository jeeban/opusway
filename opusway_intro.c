
void introduction_to_the_app( void ) //start screen
{
	GtkWidget *label, *next_button, *cancel_button, *logo, *body_frame;
	
	//create the main window for the aplication and set window properties
	main_window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	gtk_window_set_position( GTK_WINDOW( main_window), GTK_WIN_POS_CENTER );
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management" );
	gtk_window_set_resizable( GTK_WINDOW( main_window), TRUE );
	gtk_window_resize( GTK_WINDOW( main_window), 700, 400 );
	g_signal_connect( GTK_OBJECT( main_window), "destroy", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL );
	
	//craete the components for the introroduction page
	label = gtk_label_new( NULL );	//the text inside the body frame
	next_button = gtk_button_new_with_label( "NEXT" );	// NEXT button
	cancel_button = gtk_button_new_with_label( "CANCEL" );	//CANCEL button
	logo = gtk_image_new_from_file ("trans.png");	//opusway logo without text
	body_frame = gtk_frame_new( "Server setup wizard" );	//frame to hold the label
	main_table = gtk_table_new( 14, 12, TRUE );	//contains all other widgets
	
	//set the label text and insert it to the body frame
	gtk_label_set_markup( GTK_LABEL( label ), "<span fgcolor=\"black\" font=\"15\">Welcome to Advance SERVER Management</span>" );
	gtk_container_add( GTK_CONTAINER(body_frame), label );
	
	//set actions for next and close button
	g_signal_connect( GTK_OBJECT( next_button), "clicked", GTK_SIGNAL_FUNC( show_terms_and_conditions ), NULL );
	g_signal_connect( GTK_OBJECT( cancel_button), "clicked", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL );
	
	//attach the components to the main table
	gtk_table_attach_defaults ( GTK_TABLE (main_table), logo, 0, 3, 0, 14);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), next_button, 7, 9, 11, 12);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), cancel_button, 9, 11, 11, 12);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), body_frame, 3, 11, 1, 9);
	
	//add the main table to the main window
	gtk_container_add( GTK_CONTAINER( main_window), main_table );
	
	//display the main_window
	gtk_widget_show_all( main_window );
}


void show_terms_and_conditions( void )
{
	GtkWidget *agreement_label, *agree_check_button, *label_table, *scrolled_window, *tc_label, *cancel_button, *logo;
	
	char *agreement_text = "\n\tREAD THIS END USER LICENSE AGREEMENT (EULA) CAREFULLY, BECAUSE BY INSTALLING, COPYING, USING OR DISTRIBUTING THE SOFTWARE, YOU ARE AGREEING TO BE BOUND BY THESE TERMS AND CONDITIONS. IF YOU DO NOT AGREE TO ALL OF THESE TERMS AND CONDITIONS OR DO NOT WISH TO BE BOUND BY THIS EULA,DO NOT INSTALL, COPY, USE OR DISTRIBUTE THE SOFTWARE.\n\n\n\tLICENSE GRANT: Subject to your agreement and compliance with the terms and conditions of this EULA, Opusway grants to you a limited, personal, non-exclusive, non-transferable and revocable license to install, use, access, display and run one copy of the Software on the hard disk or other fixed storage medium of up to one (1) digital processors, computers, or workstations (collectively, Devices) which you own or are under your control solely for your personal or internal business use. For the avoidance of doubt, the foregoing license may not be shared or used concurrently on multiple Devices without the purchase of additional licenses from Opusway for each such Device accessing, displaying, running, and/or using the Software.\n\n\n\tINSTALLATION POLICY: With all purchases, you are authorized to install the software on up to 3 computers that you directly own and operate. This allows you to install this software on your home computer, office and laptop. We also offer multiple license discounts if you find you require more copies. Please see http://www.opusway.com/products/pricing.php.\n\n\n\tREFUND POLICY: We have a no refund policy on all of our software applications and bundles. We do this because we offer free, fully functional trial versions for all of our software this way you can download and try before you buy. These trial versions allow you to test the software risk-free before you decide to make a purchase. One of the perks when you purchase anything from Opusway is that we provide an immediate electronic download of the software program through the Customer Care Center. Because there is no way to guarantee that our software was actually removed from a system after it is installed, this allows us to help fight fraudulent activity.\n\n\n\tYOU ACKNOWLEDGE THAT YOU HAVE READ THE ENTIRE AGREEMENT, UNDERSTAND IT, ACKNOWLEDGE YOU ARE BOUND BY IT AND AGREE TO FULLY COMPLY WITH ALL OF ITS TERMS AND CONDITIONS.";
	
	//set window title
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management( T&C )" );
	
	//destroy the main table so that new table can be created
	gtk_widget_destroy( main_table);
	
	//set the agreement text inside the label to show.
	agreement_label = gtk_label_new( agreement_text );
	gtk_label_set_justify( GTK_LABEL( agreement_label), GTK_JUSTIFY_FILL );
	gtk_label_set_line_wrap( GTK_LABEL( agreement_label), TRUE );
	
	//check box for user acceptance
	agree_check_button = gtk_check_button_new_with_label( "I Agree to the T&C supplied.( Accept to install )" );
	
	//add agreement label to the label table
	label_table = gtk_table_new( 8, 7, TRUE );	//holds the agreement label
	gtk_table_attach_defaults ( GTK_TABLE (label_table), agreement_label, 0, 7, 0, 8);
	
	//create a scrolled window to hold the term and conditions
	scrolled_window = gtk_scrolled_window_new( NULL, NULL );
	gtk_container_set_border_width (GTK_CONTAINER (scrolled_window), 0);
	gtk_scrolled_window_set_policy( GTK_SCROLLED_WINDOW (scrolled_window), GTK_POLICY_AUTOMATIC, GTK_POLICY_ALWAYS);
	gtk_scrolled_window_add_with_viewport( GTK_SCROLLED_WINDOW (scrolled_window), label_table);
	//gtk_widget_show (label_table);
	
	//t&c label
	tc_label = gtk_label_new( NULL );
	gtk_label_set_markup( GTK_LABEL( tc_label ), "<span fgcolor=\"black\" font=\"13\">Terms and Conditions</span>" );
	gtk_label_set_justify( GTK_LABEL( tc_label), GTK_JUSTIFY_LEFT );
	
	//create the additional components
	cancel_button = gtk_button_new_with_label( "ABORT" );	//CANCEL button
	logo = gtk_image_new_from_file ("trans.png");	//opusway logo without text
	main_table = gtk_table_new( 14, 12, TRUE );	//contains all other widgets
	
	//set actions for next and close button AND properties
	g_signal_connect( GTK_OBJECT( cancel_button), "clicked", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL );
	g_signal_connect( GTK_OBJECT( agree_check_button), "toggled", GTK_SIGNAL_FUNC( verification ), NULL );
	
	//attach the components to the main table
	gtk_table_attach_defaults ( GTK_TABLE (main_table), tc_label, 3, 6, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), scrolled_window, 3, 11, 2, 9);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), agree_check_button, 3, 9, 10, 11);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), logo, 0, 3, 0, 14);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), cancel_button, 9, 11, 11, 12);
	
	//add the main table to the main window
	gtk_container_add( GTK_CONTAINER( main_window), main_table );
	
	//display the main_window
	gtk_widget_show_all( main_window );
}




void verification( void )
{
	GtkWidget *logo_with_name, *instruction_label, *cancel_button, *logo, *body_frame;
	//GtkWidget *status_label, *install_button, *unlock_button;
	
	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management( Software verification )" );
	
	//destroy the main table so that new table can be created
	gtk_widget_destroy( main_table);
		
	instruction_label = gtk_label_new( NULL );
	status_label = gtk_label_new( NULL );	//show the status of the app ( locked or unlocked )
	install_button = gtk_button_new();
	unlock_button = gtk_button_new();	//click here to unlock the app
	cancel_button = gtk_button_new_with_label( "ABORT" );	//terminate the app
	logo = gtk_image_new_from_file ("trans.png");
	logo_with_name = gtk_image_new_from_file ("small.png");
	body_frame = gtk_frame_new( NULL );
	main_table = gtk_table_new( 14, 12, TRUE );
	
	gtk_label_set_markup( GTK_LABEL( instruction_label ), "<span fgcolor=\"green\" font=\"13\">Unlock and click on logo to start</span>" );
	gtk_frame_set_label_widget ( GTK_FRAME( body_frame ), instruction_label );
	
	gtk_label_set_markup( GTK_LABEL( status_label ), "<span fgcolor=\"red\" font=\"12\">LOCKED</span>" );
	gtk_container_add( GTK_CONTAINER( unlock_button), status_label );
	
	gtk_widget_set_sensitive (GTK_WIDGET (install_button), FALSE);
	
	gtk_container_add( GTK_CONTAINER( install_button), logo );
	
	g_signal_connect( GTK_OBJECT( install_button), "clicked", GTK_SIGNAL_FUNC( selection_menu ), NULL );
	g_signal_connect( GTK_OBJECT( cancel_button), "clicked", GTK_SIGNAL_FUNC( gtk_main_quit ), NULL );
	g_signal_connect( GTK_OBJECT( unlock_button), "clicked", GTK_SIGNAL_FUNC( verify_user ), NULL );
	
	
	gtk_table_attach_defaults ( GTK_TABLE (main_table), logo_with_name, 1, 6, 10, 13);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), install_button, 1, 11, 2, 9);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), unlock_button, 7, 9, 11, 12);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), cancel_button, 9, 11, 11, 12);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), body_frame, 1, 11, 1, 9);
	
	gtk_container_add( GTK_CONTAINER( main_window), main_table );
	
	gtk_widget_show_all( main_window );
}



void verify_user( void )
{
	//GtkWidget *popup_window, *popup_entry; 
	GtkWidget *popup_label, *popup_table;
	
	popup_window = gtk_window_new( GTK_WINDOW_POPUP );
	gtk_window_set_position( GTK_WINDOW( popup_window), GTK_WIN_POS_CENTER );
	gtk_window_set_resizable( GTK_WINDOW( popup_window), TRUE );
	gtk_window_set_default_size( GTK_WINDOW( popup_window), 300, 150 );
	g_signal_connect( GTK_OBJECT( popup_window), "destroy", GTK_SIGNAL_FUNC( gtk_widget_destroy ), popup_window );
	g_signal_connect( GTK_OBJECT( popup_window), "show", GTK_SIGNAL_FUNC( on_window_show ), NULL );
	
	popup_label = gtk_label_new( NULL );
	popup_entry = gtk_entry_new();
	gtk_label_set_markup( GTK_LABEL( popup_label ), "<span fgcolor=\"green\" font=\"13\">ENTER THE UNLOCK CODE</span>" );
	
	g_signal_connect( GTK_OBJECT( popup_entry), "activate", GTK_SIGNAL_FUNC( close_window_dialog ), NULL );

	popup_table = gtk_table_new( 4, 6, TRUE );
	gtk_table_attach_defaults ( GTK_TABLE (popup_table), popup_label, 0, 6, 1, 2);
	gtk_table_attach_defaults ( GTK_TABLE (popup_table), popup_entry, 1, 5, 2, 3);
	
	gtk_container_add( GTK_CONTAINER( popup_window), popup_table );
	
	gtk_widget_show_all( popup_window );
}




void close_window_dialog( void )
{
	if ( compare( (char*)gtk_entry_get_text( GTK_ENTRY( popup_entry )), "a" ) == 0 )
	{
		gtk_widget_set_sensitive (GTK_WIDGET (install_button), TRUE);
		gtk_widget_set_sensitive (GTK_WIDGET (unlock_button), FALSE);
		gtk_label_set_markup( GTK_LABEL( status_label ), "<span fgcolor=\"green\" font=\"12\">UNLOCKED</span>" );
	}
	gtk_widget_destroy( popup_window );
}




void on_window_show( GtkWidget *w )
{
	while( gdk_keyboard_grab( w->window, FALSE, GDK_CURRENT_TIME ) != GDK_GRAB_SUCCESS )
	{
		sleep( 0.1 );
	}
	while( gdk_pointer_grab( w->window, TRUE, 0 ,NULL, NULL, GDK_CURRENT_TIME) != GDK_GRAB_SUCCESS )
	{
		sleep( 0.1 );
	}
}


