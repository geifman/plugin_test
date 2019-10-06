//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Action()
{
	truclient_step("1", "Navigate to 'https://kalimanjaro/index.html'", "snapshot=Action_1.inf");
	truclient_step("5", "Click on All kind of CGI's. link", "snapshot=Action_5.inf");
	truclient_step("7", "Click on Example 10 link", "snapshot=Action_7.inf");
	truclient_step("9", "Select Take A Walk from what to do listbox", "snapshot=Action_9.inf");
	truclient_step("11", "Select Chouck from who to do it with listbox", "snapshot=Action_11.inf");
	truclient_step("13", "Multi Select Jeans,Wool Sweater,Sweatshirt,Socks from what to wear multi-listbox", "snapshot=Action_13.inf");
	truclient_step("15", "Click on Submit Choices button", "snapshot=Action_15.inf");

	return 0;
}
