package domain;
import java.util.ArrayList;
import java.util.List;

public class CourseRegistration {
	private List<IAssignment> assignments;
	
	public CourseRegistration() {
		assignments = new ArrayList<IAssignment>();
	}
	
	public void addAssignment(IAssignment a) {
	}

	public double mark() {
		double total=0;
		for (IAssignment a : assignments) {
			total += a.getAssignmentMark();
		}
	return total/assignments.size();
	}
}
