checklogindataashx()
{
	lr_start_transaction("/handlers/checklogindata.ashx");

		web_url("/handlers/checklogindata.ashx", 
			"URL=http://{DOMAIN}/postaround/handlers/checklogindata.ashx", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("/handlers/checklogindata.ashx", LR_AUTO);
		
	lr_think_time(atoi(lr_eval_string("{ThinkTime}")));


	
	return 0;
}