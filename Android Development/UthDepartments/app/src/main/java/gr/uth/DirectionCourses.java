package gr.uth;

import java.util.ArrayList;
import java.util.List;
public class DirectionCourses {
    public static List<String> getDirectionCourses(String direction) {
        List<String> courses = new ArrayList<>();
        if (direction.equals("Μηχανικών Λογισμικού")) {
            courses.add("Λογική στην Πληροφορική");
            courses.add("Τεχνολογία Λογισμικού");
        }
        else if (direction.equals("Μηχανικών Δικτύων")) {
            courses.add("Πολυμεσικές Επικοινωνίες");
            courses.add("Σύνθετα Δίκτυα");
        }
        else if (direction.equals("Μηχανικών Η/Υ")){
            courses.add("Αναγνώριση Προτύπων");
            courses.add("Επεξεργασία Εικόνας");
        }
        return courses;
    }
}
