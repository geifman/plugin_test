

/*
	This is file generated automatically
*/

//test's imports
  
//imports for junit 4
import org.junit.runners.*;
import org.junit.runner.*;


//code
public class Actions
{ 
	  
	//generate junit4 test suite
	@RunWith(Suite.class)
	@Suite.SuiteClasses( {
	 TestJunit.class
	 
		}
	)
	private	class  ju4_suite {}
	//ju4 cure runner
	JUnitCore core = new JUnitCore();
	 
	
	public int init() throws Throwable {
		return 0;
	}//end of init
	
	public int action() throws Throwable {
		
		 
core.run(ju4_suite.class);
		
		return 0;
	}//end of action 
	
	public int end() throws Throwable {
		return 0;
	}//end of end 
}