Action()
{

lr_start_transaction("Web_Messages_print");

	lr_message("Message  - %s", lr_eval_string("{IterationNum}"));
	lr_think_time (10);

	lr_output_message("Output Message  - %s", lr_eval_string("{IterationNum}"));
	lr_think_time(10);

lr_end_transaction("Web_Messages_print", LR_AUTO);

	return 0;
}
