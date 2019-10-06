Action()
{

	web_add_auto_header("x-flash-version",
		"10,0,12,36");

	flex_ping("1", 
		"URL=http://kalimanjaro.devlab.ad/weborb30/sampleflextodotnetproject/weborb.aspx", 
		"Snapshot=t6.inf", 
		"ResponseParam=myXML", 
		LAST);

	lr_xml_get_values("XML={myXML}",
	                  "FastQuery=/AMFPacket/Messages/Message/AMF3/object/object-content/object-member[8]/string",
	                  "ValueParam=CorrID",
	                  LAST);

	lr_think_time(3);

	flex_remoting_call(
		"GenericDestination::getTickerInfo",
		"URL=http://kalimanjaro.devlab.ad/weborb30/sampleflextodotnetproject/weborb.aspx",
		"Snapshot=t7.inf",
		"ResponseParameter=secondXML",
		INVOCATION,
		"Target=/2",
		"Operation=getTickerInfo",
		"Destination=GenericDestination",
		"DSEndpoint=my-amf",
		"Source=GettingStarted.Examples.StockQuoteService",
		"Argument="
			"<arguments>"
				"<string>{CorrID}</string>"
			"</arguments>",
		LAST);

	lr_xml_find("XML={secondXML}",
	            "FastQuery=/AMFPacket/Messages/Message/AMF3/object/object-content/object-member[5]/object/object-content/object-member[5]/string",
	            "Value={CorrID}",
	            LAST);

	lr_think_time(3);

	return 0;
}
