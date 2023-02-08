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
	public void testGetA() {
		Triangle t = new Triangle(12, 6, 14);
		assertEquals(12, t.getA(), 0);
	}
	
	@Test
	public void testGetB() {
		Triangle t = new Triangle(12, 6, 14);
		assertEquals(6, t.getB(), 0);
	}
	
	@Test
	public void testGetC() {
		Triangle t = new Triangle(12, 6, 14);
		assertEquals(14, t.getC(), 0);
	}
	
	@Test
	public void testIsosceles() {
		Triangle t = new Triangle(4,4,3);
		assertEquals(TriangleType.Isosceles,
		t.triangleType());
	}
	
	@Test
	public void testIsosceles2() {
		Triangle t = new Triangle(10,4,10);
		assertEquals(TriangleType.Isosceles,
		t.triangleType());
	}
	
	@Test
	public void testIsosceles3() {
		Triangle t = new Triangle(3,4,4);
		assertEquals(TriangleType.Isosceles,
		t.triangleType());
	}
	
	@Test
	public void testIsosceles4() {
		Triangle t = new Triangle(10,4,4);
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
		Triangle t = new Triangle(10,20,100);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid2() {
		Triangle t = new Triangle(-10,10,10);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid3() {
		Triangle t = new Triangle(10,10,-10);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid4() {
		Triangle t = new Triangle(10,-10,10);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid5() {
		Triangle t = new Triangle(10,12,100);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid6() {
		Triangle t = new Triangle(100,12,10);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testNotValid7() {
		Triangle t = new Triangle(10,100,12);
		assertEquals(TriangleType.NotValid, t.triangleType());
	}
	
	@Test
	public void testArea() throws Exception {
		Triangle t = new Triangle(12,6,14);
		assertEquals(35.77, t.area(),0.009);
	}
	
	@Test(expected=Exception.class)
	public void testAreaNotValid() throws Exception {
		Triangle t = new Triangle(12, 6, 140);
		assertEquals(35.77, t.area(), 0.009);
	}

}
