package domain;

import static org.junit.Assert.*;

import java.util.Arrays;
import java.util.Collection;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;
import org.junit.runners.Parameterized.Parameters;

@RunWith(value = Parameterized.class)
public class TriangleTest {
	private double expected; 
	private double a; 
	private double b; 
	private double c;
	
	@Parameters
	public static Collection<double[]> getTestParameters() {
		return Arrays.asList(new double[][] {
		{ 81.61, 10.0, 17.0, 22.0 },
		{ 6.49, 7.0, 5.0, 3.0 },
		{ 692.82, 40.0, 40.0, 40.0}
		});
	}
	
	public TriangleTest(double expected, double a, double b, double c) {
		this.expected = expected;
		this.a = a;
		this.b = b;
		this.c = c;
	}

	@Test
	public void testArea_of_triangle() {
		Triangle t = new Triangle();
		double result = t.area_of_triangle(a, b, c);
		assertEquals(expected, result , 1.5);
	}

}
