package domain;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class TriangleTest {

	@Test
	void testArea_of_triangle() {
		double result;
		Triangle t = new Triangle();
		result = t.area_of_triangle(24, 30, 18);
		assertEquals(216, result, 110);
	}

}
