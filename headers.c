

//global variables

GtkWidget *main_window, *main_table, *widget_table, *widget_frame, *service_frame[3], *service[15], *service_table[3];

GtkWidget *popup_window, *popup_entry;
GtkWidget *status_label, *install_button, *unlock_button;
GtkWidget *main_image;
GtkWidget *button_info;// *textview;
GtkTextView *textview;
GtkWidget *process_status, *back_to_menu_button;

GtkWidget *label[3], *file_select, *folder_select[2], *button[2], *app_frame, *name_entry, *backup_button, *restore_button;


FILE *pd;	//pipe descripter to execute commands
char  output[500], *source_file, *target_file;
int source_ready, target_ready;

	

int n=1;




//functions used in project


// opusway_intro.c
void introduction_to_the_app( void );
void show_terms_and_conditions( void );
void verification( void );
void verify_user( void );
void close_window_dialog( void );
void on_window_show( GtkWidget* );




//app_startup.c
void selection_menu( void );
void show_image( GtkWidget *widget, gpointer data );
void back_to_menu( void );


//ftp.c
void buffer_data_entry( void );
void init_screen_ftp( void );
void show_message( GtkWidget *widget, gpointer data );
void ftp_install( void );
void update_terminal( char* );
void ftp_file( void );
void ftp_folder( void );


//repo.c
void create_repo( void );




//backup.c
void init_backup_manager( void );
void backup_mode( void );
void restore_mode( void );
void select_a_file( void );
void select_a_folder( GtkWidget *widget, gpointer data );
void take_backup( void );
int backup_process_status( void );
void perform_restore( void );
int restore_process_status( void );



//extra.c
int compare( gchar *str1, char *str2);
int string_length( char *str);




//cron.c
void init_cron( void );






