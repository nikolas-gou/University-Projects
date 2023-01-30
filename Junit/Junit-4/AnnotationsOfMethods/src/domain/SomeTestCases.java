package domain;

import static org.junit.Assert.*;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class SomeTestCases {

	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		System.out.println("Method execution @BeforeClass");
	}

	@AfterClass
	public static void tearDownAfterClass() throws Exception {
		System.out.println("Method execution @AfterClass");
	}

	@Before
	public void setUp() throws Exception {
		System.out.println("Method execution @Before");
	}

	@After
	public void tearDown() throws Exception {
		System.out.println("Method execution @After");
	}

	@Test
	public void test1() {
		System.out.println("Test 1");
	}
	@Test
	public void test2() {
		System.out.println("Test 2");
	}

}
