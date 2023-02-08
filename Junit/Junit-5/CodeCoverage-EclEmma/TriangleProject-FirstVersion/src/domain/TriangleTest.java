package domain;

import static org.junit.Assert.*;

import org.junit.Test;

public class TriangleTest {

	@Test
	public void test() {
		Triangle t = new Triangle(12,6,14);
		assertEquals(TriangleType.Scalene,t.triangleType());
	}
	
	@Test
	public void testIsosceles() {
		Triangle t = new Triangle(4,4,3);
		assertEquals(TriangleType.Isosceles,
		t.triangleType());
	}
	
	@Test
	public void testEquilateral() {
		Triangle t = new Triangle(3,3,3);
		assertEquals(TriangleType.Equilateral, t.triangleType());
	}
	
	@Test
	public void testNotValid1() {
		Triangle t = new Triangle(10,10,100);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid2() {
		Triangle t = new Triangle(-10,10,10);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testArea() throws Exception {
		Triangle t = new Triangle(12,6,14);
		assertEquals(35.77, t.area(),0.009);
	}

}
