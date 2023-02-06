package gr.uth;

import java.util.ArrayList;
import java.util.List;
public class DirectionCourses {
    public static List<String> getDirectionCourses(String direction, int semester) {
        List<String> courses = new ArrayList<>();
        if (direction.equals("Μηχανικών Λογισμικού")) {
            if (semester == 5) {
                courses.add("Λογική στην Πληροφορική");
                courses.add("Τεχνολογία Λογισμικού");
            } else if (semester == 6) {
                courses.add("Μηχανική Μάθηση");
                courses.add("Μεταγλωττιστές");
            } else if (semester == 7) {
                courses.add("Θεωρία Υπολογισμού");
                courses.add("Ποιότητα Λογισμικού");
            }
        } else if (direction.equals("Μηχανικών Δικτύων")) {
            if (semester == 5) {
                courses.add("Πολυμεσικές Επικοινωνίες");
                courses.add("Σύνθετα Δίκτυα");
            } else if (semester == 6) {
                courses.add("Διάχυτος Υπολογισμός");
                courses.add("Ασύρματες Επικοινωνίες");
            } else if (semester == 7) {
                courses.add("Ευρυζωνικά Δίκτυα");
                courses.add("Κινητές Επικοινωνίες");
            }
        } else if (direction.equals("Μηχανικών Η/Υ")) {
            if (semester == 5) {
                courses.add("Αναγνώριση Προτύπων");
                courses.add("Επεξεργασία Εικόνας");
            } else if (semester == 6) {
                courses.add("Αρχιτεκτονική Η/Υ ΙΙ");
                courses.add("Σχεδίαση Συστημάτων Υλικού");
            } else if (semester == 7) {
                courses.add("Συστήματα Υψηλών Επιδόσεων");
                courses.add("Βιομηχανικά Δίκτυα");
            }
        }
        return courses;
    }
}
