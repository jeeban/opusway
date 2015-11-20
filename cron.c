

void init_cron( void )
{
	
	GtkWidget *cron_entry[6], *cron_label[6], *cron_save_button;
	int i;

	gtk_widget_destroy( feature_frame);
	gtk_widget_destroy( main_image);
	gtk_widget_destroy( sub_image);
	gtk_widget_destroy( service_frame);

	gtk_window_set_title( GTK_WINDOW( main_window), "Advanced Server Management( cron )" );

	for( i=0; i<6; i++ )
	{
		cron_entry[i] = gtk_entry_new();
		cron_label[i] = gtk_label_new( NULL );
	}

	widget_table = gtk_table_new( 22, 16, TRUE);
	gtk_table_attach_defaults ( GTK_TABLE (main_table), widget_table, 1, 7, 3, 7);

	gtk_widget_show_all( widget_table );
}