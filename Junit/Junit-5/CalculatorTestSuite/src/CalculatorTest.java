import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class CalculatorTest {
	
	@Test
	public void testAdd() {
		Calculator c = new Calculator();
		double result = c.add(50, 10);
		assertEquals(60, result, 0);
	}

}
