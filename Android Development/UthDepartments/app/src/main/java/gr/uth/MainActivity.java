package gr.uth;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Spinner;
import android.widget.TextView;

import java.util.List;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClickFindCourses(View view) {
        TextView courses = findViewById(R.id.courses);
        Spinner directions = findViewById(R.id.direction);
        String direction =
                String.valueOf(directions.getSelectedItem());
        List<String> courseNames =
                DirectionCourses.getDirectionCourses(direction);
        StringBuilder sb = new StringBuilder();

        for (String courseName : courseNames) {
            sb.append(courseName).append('\n');
        }
        courses.setText(sb);
    }
}