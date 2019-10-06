int num = 0;

Action()
{
	for (num = 0; num < 300; num++) 
	{
		lr_vuser_status_message( lr_eval_string("Iteration {iter} creating transaction name 'transaction%d'"), num);

		lr_save_int(num,"tNumber");

		if (num < 10) 
		{
			lr_start_transaction(lr_eval_string("transaction000{tNumber}"));
		}
		else
		{
			if (num < 100) 
			{
				lr_start_transaction(lr_eval_string("transaction00{tNumber}"));
			}
			else
			{
				if (num < 1000) 
				{
					lr_start_transaction(lr_eval_string("transaction0{tNumber}"));
				}
				else
				{
					lr_start_transaction(lr_eval_string("transaction{tNumber}"));
				}
			}
		}	

		sleep(200);

		if (num < 10) 
		{
			lr_end_transaction(lr_eval_string("transaction000{tNumber}"), LR_AUTO);
		}
		else
		{
			if (num < 100) 
			{
				lr_end_transaction(lr_eval_string("transaction00{tNumber}"), LR_AUTO);
			}
			else
			{
				if (num < 1000) 
				{
					lr_end_transaction(lr_eval_string("transaction0{tNumber}"), LR_AUTO);
				}
				else
				{
					lr_end_transaction(lr_eval_string("transaction{tNumber}"), LR_AUTO);
				}
				
			}
		}
	}


	return 0;
}
