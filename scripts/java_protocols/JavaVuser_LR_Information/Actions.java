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
		String groupName = lr.get_group_name();
		String hostName = lr.get_host_name();
		String m_hostName = lr.get_master_host_name();
		String repl_java = lr.vendor + " " + lr.version;
		
		String java_home = System.getProperty("java.home");
		String java_arch = System.getProperty("sun.arch.data.model");

		int scen_id = lr.get_scenario_id();
		int user_id = lr.get_vuser_id();

		///////////////////////////////////////////////////////////////////////////
		lr.start_transaction("TR1");
		
		lr.vuser_status_message("Java home is '" + java_home + "'");
		lr.think_time(2);
		
		lr.vuser_status_message("Java version is '" + repl_java + "'");
		lr.think_time(2);
		
		lr.vuser_status_message("Java architecture is '" + java_arch + "'");
		lr.think_time(2);

		lr.vuser_status_message("Group name is '" + groupName + "'");
		lr.think_time(2);

		lr.vuser_status_message("Host name is '" + hostName + "'");
		lr.think_time(2);

		lr.vuser_status_message("Master host name is '" + m_hostName + "'");
		lr.think_time(2);

		lr.vuser_status_message("Scenario ID = " + scen_id);
		lr.think_time(2);

		lr.vuser_status_message("Vuser ID = " + user_id);
		lr.think_time(2);

		lr.end_transaction("TR1", lr.AUTO);
		///////////////////////////////////////////////////////////////////////////

		lr.rendezvous("Rendez1");

		lr.start_transaction("TR2");

		for (int i = 1; i <= 255; i++) {
			lr.peek_events();
			// check execution of lr.user_data_point function in the Controller
			lr.user_data_point("UData", Math.cos(Math.PI / 256 * i));
		}

		switch (user_id) {
		case 1:
			lr.abort();

		case 2:
			lr.exit(lr.EXIT_VUSER, lr.PASS);
		case 3:
			lr.exit(lr.EXIT_ACTION_AND_CONTINUE, lr.PASS);
		case 4:
			lr.exit(lr.EXIT_ITERATION_AND_CONTINUE, lr.PASS);
		case 5:
			lr.exit(lr.EXIT_VUSER_AFTER_ITERATION, lr.PASS);
		case 6:
			lr.exit(lr.EXIT_VUSER_AFTER_ACTION, lr.PASS);

		case 7:
			lr.exit(lr.EXIT_VUSER, lr.FAIL);
		case 8:
			lr.exit(lr.EXIT_ACTION_AND_CONTINUE, lr.FAIL);
		case 9:
			lr.exit(lr.EXIT_ITERATION_AND_CONTINUE, lr.FAIL);
		case 10:
			lr.exit(lr.EXIT_VUSER_AFTER_ITERATION, lr.FAIL);
		case 11:
			lr.exit(lr.EXIT_VUSER_AFTER_ACTION, lr.FAIL);

		case 12:
			lr.exit(lr.EXIT_VUSER, lr.AUTO);
		case 13:
			lr.exit(lr.EXIT_ACTION_AND_CONTINUE, lr.AUTO);
		case 14:
			lr.exit(lr.EXIT_ITERATION_AND_CONTINUE, lr.AUTO);
		case 15:
			lr.exit(lr.EXIT_VUSER_AFTER_ITERATION, lr.AUTO);
		case 16:
			lr.exit(lr.EXIT_VUSER_AFTER_ACTION, lr.AUTO);

		case 17:
			lr.exit(lr.EXIT_VUSER, lr.STOP);
		case 18:
			lr.exit(lr.EXIT_ACTION_AND_CONTINUE, lr.STOP);
		case 19:
			lr.exit(lr.EXIT_ITERATION_AND_CONTINUE, lr.STOP);
		case 20:
			lr.exit(lr.EXIT_VUSER_AFTER_ITERATION, lr.STOP);
		case 21:
			lr.exit(lr.EXIT_VUSER_AFTER_ACTION, lr.STOP);
		}

		lr.end_transaction("TR2", lr.AUTO);
		
		return 0;
	}//end of action


	public int end() throws Throwable {
		return 0;
	}//end of end
}
