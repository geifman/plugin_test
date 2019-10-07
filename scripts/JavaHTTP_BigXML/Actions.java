import com.hpe.lr.testing.joh.ExampleBusinessLogicClass;
import com.thoughtworks.xstream.*;
import java.io.*;
import javaHttpJ.*;
import javaHttpJ.parsers.*;
import javaHttpJ.replay.*;
import lrapi.*;
import lrapi.lr2;

public class Actions
{

	public int init() throws Throwable {
		global_init();
		return 0;
	}//end of init
	
	static final Object lock = new Object();
  	static boolean ready = false;


  	public static void global_init() {
    	if (ready == false)
      	synchronized (lock) {
        	if (ready == false) {
				ExampleBusinessLogicClassBA0=XmlBasedBinMemoObjectParsing.xml2bin("requestBody0.xml");
    			ready = true;
        	}
      	}
  	}

	public int action() throws Throwable {
  		String ENDFORM      =  "ENDFORM";
		String LAST         =  "LAST";
		String ENDITEM      =  "ENDITEM";
		String ITEMDATA     =  "ITEMDATA";
		String STARTHIDDENS =  "STARTHIDDENS";
		String ENDHIDDENS   =  "ENDHIDDENS";
		String CONNECT	    =  "CONNECT";
		String RECEIVE      =  "RECEIVE";
		String RESOLVE	    =  "RESOLVE";
		String REQUEST      =  "REQUEST";
		String RESPONSE	    =  "RESPONSE";
		String EXTRARES     =  "EXTRARES";
		int _webresult; 

		try{
			//////////////////////    requestBody0.xml    //////////////////////
			ExampleBusinessLogicClass ExampleBusinessLogicClass0 = (ExampleBusinessLogicClass) JavaHTTP.readObject(ExampleBusinessLogicClassBA0);
			lr.output_message(ExampleBusinessLogicClass0.toString());
			String s1 = (String) lr2.fieldGetter(ExampleBusinessLogicClass0, "data.value");
			lr.output_message("" + s1.length());
		} catch (Exception e) {
			e.printStackTrace();
		}
	
		return 0;
	}//end of action
	

	public int end() throws Throwable {
		return 0;
	}//end of end
  	
  	static byte[] ExampleBusinessLogicClassBA0;
}
