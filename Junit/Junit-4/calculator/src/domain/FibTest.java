package domain;

import static org.junit.Assert.*;
import java.util.Arrays;
import java.util.Collection;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;


@RunWith(value = Parameterized.class)
public class FibTest {
	private int expected;
	private int valueOne;
	private int valueTwo;
	
	@Parameters
	public static Collection<Integer[]> getTestParameters() {
		return Arrays.asList(new Integer[][] {
		{ 5, 5, 1 },
		{ 8, 6, 1 },
		{ 2, 3, 1 }
		});
	}
	
	public FibTest(int expected, int valueOne, int valueTwo) {
		this.expected = expected;
		this.valueOne = valueOne;
		this.valueTwo = valueTwo;
	}

	@Test
	public void testFib() {
		Calculator calculator = new Calculator();
		double result = calculator.fib(valueOne);
		assertEquals(expected, result, valueTwo);
	}

}
