package domain;

import static org.junit.Assert.*;

import org.junit.Test;

public class TriangleTest {

	@Test
	public void test() {
		Triangle t = new Triangle(12,6,14);
		assertEquals(TriangleType.Scalene,t.triangleType());
	}

}
