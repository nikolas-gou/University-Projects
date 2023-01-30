import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class ExpenseListTest {

	@Test
	public void testTotalExpenses() {
		ExpenseList el = new ExpenseList();el.addExpense(100.0);
		el.addExpense(200.0);
		assertEquals(300.0,el.totalExpenses(),0);
	}

}
