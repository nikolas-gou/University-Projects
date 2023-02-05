package domain;

import static org.junit.Assert.*;
import static org.mockito.Mockito.*;
import org.junit.Test;

public class CourseRegistrationTest {
	@Test
	public void testMark() {
		IAssignment a = mock(IAssignment.class);
		IAssignment b = mock(IAssignment.class);
		IAssignment c = mock(IAssignment.class);
		CourseRegistration cr = new CourseRegistration();
		cr.addAssignment(a); 
		cr.addAssignment(b); 
		cr.addAssignment(c); 
		when(a.getAssignmentMark()).thenReturn(10.0);
		when(b.getAssignmentMark()).thenReturn(9.0); 
		when(c.getAssignmentMark()).thenReturn(7.2); 
		assertEquals(8.73, cr.mark(), 0.01);
	}

}
