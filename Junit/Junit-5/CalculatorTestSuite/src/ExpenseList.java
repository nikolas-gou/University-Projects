import java.util.ArrayList;
import java.util.List;

public class ExpenseList {
	private List<Double> expenseList;

	public ExpenseList() {
		expenseList = new ArrayList<>();
	}
	
	public void addExpense(Double amount) {
		expenseList.add(amount);
	}
	
	public Double totalExpenses() {
		double total=0;
		Calculator c = new Calculator();
		for (Double d : expenseList) {
		total = c.add(total, d);
		}
		return total;
	}
}
