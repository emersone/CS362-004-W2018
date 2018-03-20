

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
	   UrlValidator uv = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES); 

	   assertEquals(false, uv.isValid("")); 
	   assertEquals(true, uv.isValid("google.com")); //FAILS
	   assertEquals(true, uv.isValid("www.google.com")); //FAILS
	   assertEquals(true, uv.isValid("http://www.google.com")); 
	   assertEquals(true, uv.isValid("http://www.google.com:80")); //F
	   assertEquals(true, uv.isValid("http://"));
	   assertEquals(true, uv.isValid("http://www.google.com/test/apple"));	  
	   assertEquals(true, uv.isValid("http://www.google.com/test"));	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
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
   
   
   
   
   
   
   
   
   
   
   


}
