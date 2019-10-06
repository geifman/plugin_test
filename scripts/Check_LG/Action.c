Action()
{
	lr_output_message("I'm OUTPUT msg running on: %s",lr_eval_string("{LG}"));
    lr_message("I'm MESSAGE msg running on: %s",lr_eval_string("{LG}"));
    lr_log_message("I'm LOG msg running on: %s",lr_eval_string("{LG}"));
    lr_debug_message(1,"I'm DEBUG msg running on: %s",lr_eval_string("{LG}"));
	return 0; 
}
