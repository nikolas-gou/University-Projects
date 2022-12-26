package domain;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class CalculatorTest {

	@Test
	void testAdd() {
		Calculator calculator = new Calculator();
		double result = calculator.add(10, 5);
		assertEquals(15, result, 0);
	}
	
	@Test
	void testSubtract() {
		Calculator calculator = new Calculator();
		double result = calculator.subtract(10, 5);
		assertEquals(5, result, 0);
	}
	
	@Test
	void testDivision() {
		Calculator calculator = new Calculator();
		double result = calculator.division(10, 5);
		assertEquals(2, result, 0);
	}
	
	@Test
	void testMultiplication() {
		Calculator calculator = new Calculator();
		double result = calculator.multiplication(10, 5);
		assertEquals(50, result, 0);
	}
}
