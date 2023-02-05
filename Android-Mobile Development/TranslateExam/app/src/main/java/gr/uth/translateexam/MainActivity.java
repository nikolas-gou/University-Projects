package gr.uth.translateexam;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }

    public void TranslateClick(View view) {
        EditText edittextTranslate = findViewById(R.id.EditTextGiveWord);
        String word = edittextTranslate.getText().toString();

        Intent intent = new Intent(this, TranslateWord.class);
        intent.putExtra("word", word);
        startActivity(intent);
    }
}