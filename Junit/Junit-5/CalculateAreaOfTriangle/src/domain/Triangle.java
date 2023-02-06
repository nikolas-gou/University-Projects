package domain;

public class Triangle {
	public double area_of_triangle(double a, double b, double c) {
		double s, area;
		s = (a+b+c) / 2;
		area = Math.sqrt(s * (s-a) * (s - b) * (s - a));
		return area;
	}

}
