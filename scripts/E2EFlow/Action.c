Action()
{

	web_add_auto_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_auto_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=1.0");

	web_url("kalimanjaro.hpeswlab.net", 
		"URL=http://kalimanjaro.hpeswlab.net/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("login");

	web_link("New Mercury Tours", 
		"Text=New Mercury Tours", 
		"Snapshot=t2.inf", 
		LAST);

	web_revert_auto_header("X-P2P-PeerDist");

	web_revert_auto_header("X-P2P-PeerDistEx");

	lr_think_time(8);

	web_submit_form("login.pl", 
		"Snapshot=t3.inf", 
		ITEMDATA, 
		"Name=username", "Value=123", ENDITEM, 
		"Name=password", "Value=123", ENDITEM, 
		"Name=login.x", "Value=41", ENDITEM, 
		"Name=login.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("filghts");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=1.0");

	lr_think_time(17);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t4.inf", 
		EXTRARES, 
		"Url=FormDateUpdate.class", "Referer=", ENDITEM, 
		LAST);

	lr_think_time(6);

	web_submit_form("reservations.pl", 
		"Snapshot=t5.inf", 
		ITEMDATA, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=08/11/2017", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
		"Name=returnDate", "Value=08/12/2017", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=roundtrip", "Value=<OFF>", ENDITEM, 
		"Name=seatPref", "Value=None", ENDITEM, 
		"Name=seatType", "Value=Coach", ENDITEM, 
		"Name=findFlights.x", "Value=34", ENDITEM, 
		"Name=findFlights.y", "Value=9", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t6.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=042;331;08/11/2017", ENDITEM, 
		"Name=reserveFlights.x", "Value=29", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_think_time(4);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t7.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=123", ENDITEM, 
		"Name=lastName", "Value=123", ENDITEM, 
		"Name=address1", "Value=123", ENDITEM, 
		"Name=address2", "Value=123", ENDITEM, 
		"Name=pass1", "Value=123 123", ENDITEM, 
		"Name=creditCard", "Value=", ENDITEM, 
		"Name=expDate", "Value=", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=30", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		LAST);

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=1.0");

	lr_think_time(6);

	web_image("Search Flights Button_2", 
		"Alt=Search Flights Button", 
		"Snapshot=t8.inf", 
		LAST);

	lr_end_transaction("filghts",LR_AUTO);

	web_custom_request("gn.symcd.com", 
		"URL=http://gn.symcd.com/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/ocsp-response", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/ocsp-request", 
		"BodyBinary=0Q0O0M0K0I0\t\\x06\\x05+\\x0E\\x03\\x02\\x1A\\x05\\x00\\x04\\x14\\x18\\xF8\\x85\\xA9\\x97\\x1C\\xDC{\\xEF\\x86\tm\\x01\\x98<\\xA8\\xF9\\x9F%V\\x04\\x14$\\xF2.N\\x0F\\xBD\\xCA\\xF7>)U\\xCAr\\x8Di\\x87VD\\xE9z\\x02\\x10a\\xAF\\x14,\\xF9\\x8EoN\\x17\\xA7\\x88Q\\xFAO\\xB2\\xAF", 
		LAST);

	lr_start_transaction("sighOFF");

	web_add_header("X-P2P-PeerDist", 
		"Version=1.1");

	web_add_header("X-P2P-PeerDistEx", 
		"MinContentInformation=1.0, MaxContentInformation=1.0");

	lr_think_time(21);

	web_url("welcome.pl", 
		"URL=http://kalimanjaro.hpeswlab.net/WebTours/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://kalimanjaro.hpeswlab.net/WebTours/nav.pl?page=menu&in=flights", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("sighOFF",LR_AUTO);

	return 0;
}