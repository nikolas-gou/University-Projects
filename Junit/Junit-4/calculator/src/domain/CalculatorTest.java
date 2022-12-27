package domain;

import static org.junit.Assert.*;
import java.util.Arrays;
import java.util.Collection;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(value = Parameterized.class)
public class CalculatorTest {
	private int expected; //αναμενόμενο αποτέλεσμα
	private int valueOne; //πρώτη παράμετρος για την add
	private int valueTwo; //δεύτερη παράμετρος για την add
	
	@Parameters
	public static Collection<Integer[]> getTestParameters() {
		return Arrays.asList(new Integer[][] {
		{ 60, 50, 10 }
		});
	}
	
	public CalculatorTest(int expected, int valueOne, int valueTwo) {
		this.expected = expected;
		this.valueOne = valueOne;
		this.valueTwo = valueTwo;
	}
	
	@Test
	public void testAdd() {
		Calculator calculator = new Calculator();
		double result = calculator.add(valueOne, valueTwo);
		assertEquals(expected, result, 0);
	}
}
