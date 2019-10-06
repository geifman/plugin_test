/*
 * LoadRunner Java script. (Build: _build_number_)
 * 
 * Script Description: 
 *                     
 */

import lrapi.lr;

public class Actions
{

	public int init() throws Throwable {
		return 0;
	}//end of init


	public int action() throws Throwable {
		lr.start_transaction("Java User Transaction 1");
		lr.error_message("Hello from Java Vuser");
		lr.think_time(2);
		//lr.sleep(2000);
		lr.end_transaction("Java User Transaction 1", lr.AUTO);
		return 0;
		
	}//end of action


	public int end() throws Throwable {
		return 0;
	}//end of end
}
