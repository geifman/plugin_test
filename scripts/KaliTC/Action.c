//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Action()
{
	truclient_step("1", "Wait 3 seconds", "snapshot=Action_1.inf");
	lr_start_transaction("Homepage");
	truclient_step("2", "Navigate to 'http://16.60.179.203/index.html'", "snapshot=Action_2.inf");
	lr_end_transaction("Homepage",0);
	truclient_step("3", "Wait 3 seconds", "snapshot=Action_3.inf");

	return 0;
}
