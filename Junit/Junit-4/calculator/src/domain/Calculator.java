package domain;

public class Calculator {
	public double add(double num1, double num2) {
		return num1 + num2;
	}
	
	public int fib(int n) {
		 int prev1 = 0, prev2 = 1;
		 for (int i = 0; i < n; i++) {
			 int savePrev1 = prev1;
			 prev1 = prev2;
			 prev2 = savePrev1 + prev2;
		 }
		 return prev1;
	} 

}
