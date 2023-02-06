package gr.uth.translateexam;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class TranslateWord extends AppCompatActivity {

    private String[][] dic = new String[4][2];
    boolean flag = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_translate_word);
        dic[0][0] = getString(R.string.G1);
        dic[0][1] = getString(R.string.T1);
        dic[1][0] = getString(R.string.G2);
        dic[1][1] = getString(R.string.T2);
        dic[2][0] = getString(R.string.G3);
        dic[2][1] = getString(R.string.T3);
        dic[3][0] = getString(R.string.G4);
        dic[3][1] = getString(R.string.T4);

        Intent intent = getIntent();
        String word = intent.getStringExtra("word");
        TextView GivenWordTextView = findViewById(R.id.GivenWordText);
        for(int i = 0; i < 4; i++) {
            if(word.equals(dic[i][0])) {
                GivenWordTextView.setText(getString(R.string.GivenWord2) + " " +dic[i][1]);
                flag = true;
            }
        }
        if(!flag)
            GivenWordTextView.setText(getString(R.string.Error));
    }
}