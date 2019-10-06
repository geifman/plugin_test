Action2()
{
	lr_start_transaction("/postaround");

		web_url("/postaround", 
			"URL=http://{DOMAIN}/postaround", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("/postaround", LR_AUTO);
		
	lr_think_time(atoi(lr_eval_string("{ThinkTime}")));

	lr_start_transaction("/handlers/getmessages.ashx");

		web_url("/handlers/getmessages.ashx", 
			"URL=http://{DOMAIN}/postaround/handlers/getmessages.ashx?currlat=&currlon=&uptometers=-1&timezone=2&fromnumber=0&categoryid=*&sortby=0&ismine=0&takenum=20", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("/handlers/getmessages.ashx", LR_AUTO);
		
	lr_think_time(atoi(lr_eval_string("{ThinkTime}")));


	
	return 0;
}