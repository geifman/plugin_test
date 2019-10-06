//   *****************************************************************************************************************************************
//   ****   PLEASE NOTE: This is a READ-ONLY representation of the actual script. For editing please press the "Develop Script" button.   ****
//   *****************************************************************************************************************************************

Action()
{
	truclient_step("11", "Navigate to 'http://kalimanjaro/NewFlights/'", "snapshot=Action_11.inf");
	truclient_step("12", "home", "snapshot=Action_12.inf");
	{
		truclient_step("12.1", "Click on User Name textbox", "snapshot=Action_12.1.inf");
		truclient_step("12.2", "Type daniel in User Name textbox", "snapshot=Action_12.2.inf");
		truclient_step("12.3", "Type ******* in Password passwordbox", "snapshot=Action_12.3.inf");
		truclient_step("12.4", "Press key Enter on Password passwordbox", "snapshot=Action_12.4.inf");
	}
	truclient_step("13", "Click on Use our Flight Finder...", "snapshot=Action_13.inf");
	truclient_step("14", "Click on findFlights button", "snapshot=Action_14.inf");
	truclient_step("15", "Click on button1 radio", "snapshot=Action_15.inf");
	truclient_step("16", "Click on button3 radio", "snapshot=Action_16.inf");
	truclient_step("17", "Click on reserveFlights button", "snapshot=Action_17.inf");
	truclient_step("18", "Click on First Name textbox", "snapshot=Action_18.inf");
	truclient_step("19", "Type Daniel in First Name textbox", "snapshot=Action_19.inf");
	truclient_step("20", "Type Danan in Last Name textbox", "snapshot=Action_20.inf");
	truclient_step("21", "Click on element (1)", "snapshot=Action_21.inf");
	truclient_step("22", "Select Kosher from Meal listbox", "snapshot=Action_22.inf");
	truclient_step("23", "Click on American Express MasterCard... gridcell", "snapshot=Action_23.inf");
	truclient_step("24", "Select MasterCard from listbox (3) listbox", "snapshot=Action_24.inf");
	truclient_step("25", "Click on American Express MasterCard... textbox", "snapshot=Action_25.inf");
	truclient_step("26", "Type 666 in American Express MasterCard... textbox", "snapshot=Action_26.inf");
	truclient_step("27", "Select 12 from None listbox", "snapshot=Action_27.inf");
	truclient_step("28", "Select 2010 from None listbox", "snapshot=Action_28.inf");
	truclient_step("29", "Click on First Name textbox", "snapshot=Action_29.inf");
	truclient_step("30", "Type Daniel in First Name textbox", "snapshot=Action_30.inf");
	truclient_step("31", "Click on cc mid name textbox", "snapshot=Action_31.inf");
	truclient_step("32", "Type Junior in cc mid name textbox", "snapshot=Action_32.inf");
	truclient_step("33", "Click on cc last name textbox", "snapshot=Action_33.inf");
	truclient_step("34", "Type Danan in cc last name textbox", "snapshot=Action_34.inf");
	truclient_step("35", "Click on Address textbox", "snapshot=Action_35.inf");
	truclient_step("36", "Type 5th avenue in Address textbox", "snapshot=Action_36.inf");
	truclient_step("37", "Click on City textbox", "snapshot=Action_37.inf");
	truclient_step("38", "Type New York in City textbox", "snapshot=Action_38.inf");
	truclient_step("39", "Click on State/Province textbox", "snapshot=Action_39.inf");
	truclient_step("40", "Click on State/Province textbox", "snapshot=Action_40.inf");
	truclient_step("41", "Click on State/Province textbox", "snapshot=Action_41.inf");
	truclient_step("42", "Type New York in State/Province textbox", "snapshot=Action_42.inf");
	truclient_step("43", "Click on Postal Code textbox", "snapshot=Action_43.inf");
	truclient_step("44", "Click on Postal Code textbox", "snapshot=Action_44.inf");
	truclient_step("45", "Type 1 in Postal Code textbox", "snapshot=Action_45.inf");
	truclient_step("46", "Select UNITED STATES from Country listbox", "snapshot=Action_46.inf");
	truclient_step("47", "Click on Address textbox", "snapshot=Action_47.inf");
	truclient_step("48", "Click on Address textbox", "snapshot=Action_48.inf");
	truclient_step("49", "Type central park in Address textbox", "snapshot=Action_49.inf");
	truclient_step("50", "Click on City textbox", "snapshot=Action_50.inf");
	truclient_step("51", "Type New York in City textbox", "snapshot=Action_51.inf");
	truclient_step("52", "Type New York in State/Province textbox", "snapshot=Action_52.inf");
	truclient_step("53", "Click on Postal Code textbox", "snapshot=Action_53.inf");
	truclient_step("54", "Click on Postal Code textbox", "snapshot=Action_54.inf");
	truclient_step("55", "Type 2 in Postal Code textbox", "snapshot=Action_55.inf");
	truclient_step("56", "Select UNITED STATES from Country listbox", "snapshot=Action_56.inf");
	truclient_step("57", "Click on buyFlights button", "snapshot=Action_57.inf");
	truclient_step("58", "Click on link (1) image", "snapshot=Action_58.inf");

	return 0;
}
