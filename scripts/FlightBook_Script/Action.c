Action()
{

	web_url("WebTours", 
		"URL=http://myd-vm15892.hpeswlab.net:1080/WebTours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(22);

	lr_start_transaction("sign_on");

	web_submit_form("login.pl", 
		"Snapshot=t14.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=59", ENDITEM, 
		"Name=login.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("sign_on",LR_AUTO);

	lr_think_time(16);

	
//	
//		web_image("Itinerary Button", 
//		"Alt=Itinerary Button", 
//		"Snapshot=t23.inf", 
//		LAST);
//
//	lr_think_time(20);
//
//	web_custom_request("itinerary.pl", 
//		"URL=http://kalimanjaro.hpeswlab.net/WebTours/itinerary.pl", 
//		"Method=POST", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=http://kalimanjaro.hpeswlab.net/WebTours/itinerary.pl", 
//		"Snapshot=t24.inf", 
//		"Mode=HTML", 
//		body_variable_1, 
//		LAST);

	lr_start_transaction("flightbook");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t15.inf", 
		EXTRARES, 
		"Url=FormDateUpdate.class", "Referer=", ENDITEM, 
		"Url=CalSelect.class", "Referer=", ENDITEM, 
		"Url=Calendar.class", "Referer=", ENDITEM, 
		"Url=YearMonthPanel.class", "Referer=", ENDITEM, 
		"Url=DayPanel.class", "Referer=", ENDITEM, 
		"Url=DateInfo.class", "Referer=", ENDITEM, 
		LAST);

	lr_think_time(15);

	web_submit_form("reservations.pl", 
		"Snapshot=t16.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Los Angeles", ENDITEM, 
		"Name=departDate", "Value=08/3/2016", ENDITEM, 
		"Name=arrive", "Value=Portland", ENDITEM, 
		"Name=returnDate", "Value=08/13/2016", ENDITEM, 
		"Name=numPassengers", "Value=2", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=Aisle", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=findFlights.x", "Value=37", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t17.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=352;351;08/3/2016", ENDITEM, 
		"Name=reserveFlights.x", "Value=22", ENDITEM, 
		"Name=reserveFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_think_time(24);

	web_submit_form("reservations.pl_3",
		"Snapshot=t18.inf",
		ITEMDATA,
		"Name=firstName", "Value=Jojo", ENDITEM,
		"Name=lastName", "Value=Bean", ENDITEM,
		"Name=address1", "Value=cluj 32", ENDITEM,
		"Name=address2", "Value=cluj", ENDITEM,
		"Name=pass1", "Value=Jojo Bean", ENDITEM,
		"Name=pass2", "Value=", ENDITEM,
		"Name=creditCard", "Value={CrediCardValues}", ENDITEM,
		"Name=expDate", "Value=32342", ENDITEM,
		"Name=saveCC", "Value=<OFF>", ENDITEM,
		"Name=buyFlights.x", "Value=17", ENDITEM,
		"Name=buyFlights.y", "Value=6", ENDITEM,
		LAST);

	lr_end_transaction("flightbook",LR_AUTO);

	lr_think_time(28);
	
	lr_start_transaction("itinerary_check");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t19.inf", 
		LAST);

	lr_end_transaction("itinerary_check",LR_AUTO);

	lr_start_transaction("sign_off");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t20.inf", 
		LAST);

	lr_end_transaction("sign_off",LR_AUTO);

	return 0;
}