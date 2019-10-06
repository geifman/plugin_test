Action2()
{
	lr_start_transaction("/postaround");

		lr_user_data_point("HTTP_200", 1); //simulate hits
		lr_user_data_point("mic_recv", 1*1024); //simulate throuput
		sleep(214);
		lr_set_transaction_status(LR_PASS);
	
	lr_end_transaction("/postaround", LR_AUTO);
		
	lr_think_time(atoi(lr_eval_string("{ThinkTime}")));

	lr_start_transaction("/handlers/getmessages.ashx");

		lr_user_data_point("HTTP_200", 1); //simulate hits
		lr_user_data_point("mic_recv", 1*1024); //simulate throuput
		sleep(1065);
		lr_set_transaction_status(LR_PASS);
	
	lr_end_transaction("/handlers/getmessages.ashx", LR_AUTO);
		
	lr_think_time(atoi(lr_eval_string("{ThinkTime}")));


	
	return 0;
}