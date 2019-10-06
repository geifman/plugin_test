Action()
{
lr_start_transaction("test01");

lr_think_time(3);
lr_end_transaction("test01", LR_AUTO);

lr_start_transaction("test02");

lr_log_message("This is log info");

lr_think_time(3);
lr_end_transaction("test02", LR_AUTO);

	
	return 0;
}
