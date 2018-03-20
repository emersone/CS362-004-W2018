//Elizabeth Emerson
//Cameron Brown
//CS 362 (Winter 2018)
//Final Project Part B

import junit.framework.TestCase;


public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   //Manually tests URL inputs.
   public void testManualTest() {
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   assertEquals(false, uv.isValid("")); 
	   assertEquals(true, uv.isValid("google.com")); //FAILS
	   assertEquals(true, uv.isValid("www.google.com")); //FAILS
	   assertEquals(true, uv.isValid("http://www.google.com")); 
	   assertEquals(true, uv.isValid("http://www.google.com:80")); //FAILS
	   assertEquals(false, uv.isValid("http://")); //FAILS
	   assertEquals(true, uv.isValid("http://www.google.com/test/apple")); //FAILS	  
	   assertEquals(true, uv.isValid("http://www.google.com/test"));	   
   }
   
   
   //Partition (testing scheme).
   public void testSchemePartition() { 
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   
	  // assertEquals(true, uv.isValid("http://www.google.com")); //Valid input, passes as expected
	   assertEquals(false, uv.isValid("adg://www.google.com")); //Invalid input, set to false, yet FAILS 
   }
   
   
   //Partition (testing authority).
   public void testAuthorityPartition() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   
	   assertEquals(true, uv.isValid("http://www.google.com")); //Valid input, passes as expected
	   assertEquals(false, uv.isValid("http://")); //Invalid input, set to false, yet FAILS 
   }
   
   
   //Partition (testing port).
   public void testPortPartition() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   
	   assertEquals(true, uv.isValid("http://www.google.com:80")); //Valid input, FAILS
	   assertEquals(false, uv.isValid("http://www.google.com:a")); //Invalid input, set to false, passes as expected
   }
   
   
   //Partition (testing path).
   public void testPathPartition() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   assertEquals(true, uv.isValid("http://www.google.com/test/apple")); //Valid input, FAILS
	   assertEquals(false, uv.isValid("http://www.google.com/test//apple")); //Invalid input, set to false, passes as expected
   }
   
   
   //Partition (testing query).
   public void testQueryPartition() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 
	   
	   assertEquals(true, uv.isValid("http://www.google.com?first=one")); //Valid input, passes as expected
	   assertEquals(false, uv.isValid("http://www.google.com?first=one, second=two")); //Invalid input, set to false, passes as expected
   }
   

   //Tests the isValid() method in the UrlValidator.
   public void testIsValid() {
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   //assertEquals(true, uv.isValid("http://www.google.com:80"));
	   //assertEquals(true, uv.isValid("http://"));
	   assertEquals(true, uv.isValid("http://www.google.com/test/apple"));

   }
   
   
   //Create class to hold test pairs (expected return value of isValid and the changing part of the URL).
   public class testPair {
	   boolean expected;
	   String arg;
	   
	   //Constructor to initialize variables.
	   testPair(boolean e, String a) {
		   this.expected = e;
		   this.arg = a; 
	   }
   }
   
   
   //Tests the scheme part of the UrlValidator.
   public void testScheme() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   //Create array and place elements.
	   testPair[] tests = {
			//new testPair(true, ""), //FAILS
			new testPair(true, "http://"),
			//new testPair(true, "ftp://"), //FAILS
			//new testPair(true, "https://"), //FAILS
			//new testPair(false, "apple://"), //FAILS
	   };
	   
	   //Loops through tests to find bugs in isValid.
	   for(testPair t: tests) {
		   assertEquals(t.expected, uv.isValid(t.arg + "www.google.com"));
	   }
   }
   
   
   //Tests the authority part of the UrlValidator.
   public void testAuthority() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   //Create array and place elements.
	   testPair[] tests = {
			new testPair(false, ""), //FAILS
			new testPair(true, "www.google.com"),
			new testPair(true,"255.255.255.255"),
			new testPair(true,"0.0.0.0"),
			new testPair(false,"256.256.256.256") //FAILS 
	   };
	   
	   //Loops through tests to find bugs in isValid.
	   for(testPair t: tests) {
		   assertEquals(t.expected, uv.isValid("http://" + t.arg));
	   }
   }
   
   
   //Tests the port part of the UrlValidator.
   public void testPort() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   //Create array and place elements.
	   testPair[] tests = {
			new testPair(true, ""),
			new testPair(true,":80"), //FAILS 
			new testPair(false,":a"),
	   };
	   
	   //Loops through tests to find bugs in isValid.
	   for(testPair t: tests) {
		   assertEquals(t.expected, uv.isValid("http://www.google.com" + t.arg));
	   }
   }
   
   
   //Tests the path part of the UrlValidator.
   public void testPath() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   //Create array and place elements.
	   testPair[] tests = {
			new testPair(true, ""),
			new testPair(true,"/test"), 
			new testPair(false,"/.."),
			new testPair(true, "/test/apple"), //FAILS 
			new testPair(false, "/test1//apple"),
	   };
	   
	   //Loops through tests to find bugs in isValid.
	   for(testPair t: tests) {
		   assertEquals(t.expected, uv.isValid("http://www.google.com" + t.arg));
	   }
   }
   
   
   //Tests the query part fo the UrlValidator.
   public void testQuery() {
	   //Calls constructor to initialize the UrlValidator.
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   //Create array and place elements.
	   testPair[] tests = {
			new testPair(true, ""),
			new testPair(true,"first=one"), 
			new testPair(true,"first=one,second=two"), 
			new testPair(false,"first=one, second=two"),

	   };
	   
	   //Loops through tests to find bugs in isValid.
	   for(testPair t: tests) {
		   assertEquals(t.expected, uv.isValid("http://www.google.com?" + t.arg));
	   }
   }
   
   
   
   
   
   
   
   
   
   


}
